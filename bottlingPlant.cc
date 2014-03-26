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

}

void BottlingPlant::main() {

}

bool BottlingPlant::getShipment( unsigned int cargo[] ) {
  bool implemented = false;
  assert(implemented);
  return false;
}

