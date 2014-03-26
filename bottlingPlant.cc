#include "bottlingPlant.h"

BottlingPlant::BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines,
                 unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour,
                 unsigned int timeBetweenShipments ) 
  :  mPrinter(prt), 
     mNameServer(nameServer),
     mNumVendingMachines(numVendingMachines),
     mMaxShippedPerFlavour(maxShippedPerFlavour),
     mMaxStockPerFlavour(maxStockPerFlavour),
     mTimeBetweenShipments(timeBetweenShipments) {

  mTruck = new Truck( prt, nameServer, *this, numVendingMachines, maxStockPerFlavour );
}

BottlingPlant::~BottlingPlant() {
  delete mTruck;
}

void BottlingPlant::main() {
  mPrinter.print(Printer::BottlingPlant, 'S');
}

bool BottlingPlant::getShipment( unsigned int cargo[] ) {
  bool implemented = false;
  assert(implemented);
  return false;
}

