#include "bottlingPlant.h"

BottlingPlant::BottlingPlant( Printer &prt
                            , NameServer &nameServer
                            , unsigned int numVendingMachines
                            , unsigned int maxShippedPerFlavour
                            , unsigned int maxStockPerFlavour
                            , unsigned int timeBetweenShipments )
  : printer( prt )
  , nameServer( nameServer )
  , nVendingMachines( numVendingMachines )
  , maxShippedPerFlavour( maxShippedPerFlavour )
  , maxStockPerFlavour( maxStockPerFlavour )
  , timeBetweenShipments( timeBetweenShipments ) {
    truck = new Truck( prt, nameServer, *this, numVendingMachines, maxStockPerFlavour );
}

BottlingPlant::~BottlingPlant() {
    delete truck;
}

void BottlingPlant::main() {
    printer.print( Printer::BottlingPlant, 'S' );
}

bool BottlingPlant::getShipment( unsigned int cargo[] ) {
    bool implemented = false;
    assert( implemented );
    return false;
}

