#ifndef __BOTTLING_PLANT_H__
#define __BOTTLING_PLANT_H__

#include "printer.h"
#include "nameServer.h"
#include "truck.h"

_Task BottlingPlant {
    Printer &mPrinter;
    NameServer &mNameServer;
    unsigned int mNumVendingMachines;
    unsigned int mMaxShippedPerFlavour;
    unsigned int mMaxStockPerFlavour;
    unsigned int mTimeBetweenShipments;

    Truck *mTruck;

    void main();
  public:
    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines,
                 unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour,
                 unsigned int timeBetweenShipments );
    ~BottlingPlant();
    bool getShipment( unsigned int cargo[] );
};

#endif

