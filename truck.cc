#include "printer.h"
#include "nameServer.h"
#include "bottlingPlant.h"

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

}
