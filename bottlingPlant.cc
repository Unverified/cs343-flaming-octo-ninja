#include "bottlingPlant.h"
#include "MPRNG.h"

extern MPRNG mprng;

BottlingPlant::BottlingPlant( Printer &prt
                            , NameServer &nameServer
                            , unsigned int numVendingMachines
                            , unsigned int maxShippedPerFlavour
                            , unsigned int maxStockPerFlavour
                            , unsigned int timeBetweenShipments )
  : printer( prt )
  , nameServer( nameServer )
  , maxShippedPerFlavour( maxShippedPerFlavour )
  , timeBetweenShipments( timeBetweenShipments ) {
    
    isRunning = true;
    truck = new Truck( prt, nameServer, *this, numVendingMachines, maxStockPerFlavour );
}

BottlingPlant::~BottlingPlant() {
    delete truck;
}

void BottlingPlant::main() {
    printer.print( Printer::BottlingPlant, 'S' );
    for(;;) {
        unsigned int generated = 0;
        for( unsigned int i = 0; i < VendingMachine::FINAL_COUNT; i += 1 ) {
            unsigned int amountFlavourGenerated = mprng( maxShippedPerFlavour );
            shipment[i] = amountFlavourGenerated;
            generated += amountFlavourGenerated;
        }

        yield( timeBetweenShipments );
        printer.print( Printer::BottlingPlant, 'G', generated );

        _Accept( ~BottlingPlant ) {
            isRunning = false;
            _Accept( getShipment );
            break;
        } or _Accept( getShipment ) {
            printer.print( Printer::BottlingPlant, 'P' );
        }
    }
    printer.print( Printer::BottlingPlant, 'F' );
}

bool BottlingPlant::getShipment( unsigned int cargo[] ) {
  if( !isRunning ) { return true; } 
    for( unsigned int i = 0; i < VendingMachine::FINAL_COUNT; i += 1 ) {
        cargo[i] = shipment[i];
    }
    return false;
}

