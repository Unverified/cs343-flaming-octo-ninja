#ifndef __BOTTLING_PLANT_H__
#define __BOTTLING_PLANT_H__

#include "printer.h"
#include "nameServer.h"
#include "truck.h"
#include "vendingMachine.h"

_Task BottlingPlant {
    Printer &printer;
    NameServer &nameServer;
    const unsigned int maxShippedPerFlavour;
    const unsigned int timeBetweenShipments;

    bool isRunning;
    unsigned int shipment[VendingMachine::FINAL_COUNT];
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

