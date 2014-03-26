#include "bottlingPlant.h"

#include "truck.h"

Truck::Truck( Printer &prt
            , NameServer &nameServer
            , BottlingPlant &plant
            , unsigned int numVendingMachines
            , unsigned int maxStockPerFlavour )
  : mPrinter( prt )
  , nameServer( nameServer )
  , plant( plant )
  , nVendingMachines( numVendingMachines )
  , maxStockPerFlavour( maxStockPerFlavour) {
}

void Truck::main() {
  mPrinter.print(Printer::Truck, 'S');
}
