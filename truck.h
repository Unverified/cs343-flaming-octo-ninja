#ifndef __TRUCK_H__
#define __TRUCK_H__

#include "printer.h"
#include "nameServer.h"
#include "bottlingPlant.h"

_Task Truck {
    Printer &printer;
    NameServer &nameServer;
    BottlingPlant &plant;
    const unsigned int nVendingMachines;
    const unsigned int maxStockPerFlavour;

    void main();
  public:
    Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant,
           unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
};

#endif

