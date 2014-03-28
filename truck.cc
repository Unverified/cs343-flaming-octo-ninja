#include "bottlingPlant.h"
#include "vendingMachine.h"
#include "truck.h"

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

void Truck::main() {
    printer.print(Printer::Truck, 'S');
    unsigned int cargo[VendingMachine::FINAL_COUNT];
    while( !plant.getShipment( cargo ) ) {

    }
    printer.print( Printer::Truck, 'F' );
}
