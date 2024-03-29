#include "bottlingPlant.h"
#include "vendingMachine.h"
#include "truck.h"
#include "MPRNG.h"
#include <iostream>
extern MPRNG mprng;
const static unsigned int MAX_COFFEE_WAIT = 10;


Truck::Truck( Printer &prt
            , NameServer &nameServer
            , BottlingPlant &plant
            , unsigned int numVendingMachines
            , unsigned int maxStockPerFlavour )
  : printer( prt )
  , nameServer( nameServer )
  , plant( plant )
  , nVendingMachines( numVendingMachines )
  , maxStockPerFlavour( maxStockPerFlavour) {
}

#include <iostream>
void Truck::main() {
    printer.print(Printer::Truck, 'S');
    VendingMachine **machines = nameServer.getMachineList();	//begins by obtaining a list of vending machines from the nameserver
    unsigned int cargo[VendingMachine::FLAVOUR_COUNT];
    while( true ) {
        yield( mprng( 1, MAX_COFFEE_WAIT ) );
      
      if( plant.getShipment( cargo ) ) { break; }
        unsigned int totalCargo = 0;
        for( unsigned int i = 0; i < VendingMachine::FLAVOUR_COUNT; i += 1 ) {
            totalCargo += cargo[i];   
        }
        printer.print( Printer::Truck, 'P', totalCargo );

        for( unsigned int i = 0; i < nVendingMachines && totalCargo > 0; i += 1 ) {
            unsigned int *stock = machines[i]->inventory();
            printer.print( Printer::Truck, 'd', machines[i]->getId(), totalCargo );

            unsigned int amtNotFilled = 0;
            for( unsigned int j = 0; j < VendingMachine::FLAVOUR_COUNT; j += 1 ) {
                unsigned int amtToStock = maxStockPerFlavour - stock[j];
                unsigned int amtRestocked = cargo[j] > amtToStock ? amtToStock : cargo[j];
                cargo[j] -= amtRestocked;
                stock[j] += amtRestocked;
                totalCargo -= amtRestocked;
                amtNotFilled += (amtToStock - amtRestocked);
            }

            if( amtNotFilled > 0 ) {
                printer.print( Printer::Truck, 'U', machines[i]->getId(), amtNotFilled );
            }
            machines[i]->restocked();
            printer.print( Printer::Truck, 'D', machines[i]->getId(), totalCargo );
        }
    }
    printer.print( Printer::Truck, 'F' );
}
