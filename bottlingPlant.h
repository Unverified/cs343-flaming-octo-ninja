#ifndef __BOTTLING_PLANT_H__
#define __BOTTLING_PLANT_H__

#include "printer.h"
#include "nameServer.h"
#include "truck.h"

_Task BottlingPlant {
    Printer &printer;
    NameServer &nameServer;
    const unsigned int nVendingMachines;
    const unsigned int maxShippedPerFlavour;
    const unsigned int maxStockPerFlavour;
    const unsigned int timeBetweenShipments;

    Truck *truck;

    void main();
  public:
    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines,
                 unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour,
                 unsigned int timeBetweenShipments );
    ~BottlingPlant();
    bool getShipment( unsigned int cargo[] );
};

#endif

