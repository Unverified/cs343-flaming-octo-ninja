#ifndef __NAME_SERVER_H__
#define __NAME_SERVER_H__

#include "printer.h"
#include "vendingMachine.h"

_Task NameServer {
    Printer &mPrinter;
    unsigned int nVendingMachines;
    unsigned int nStudents;

    VendingMachine **mVendingMachines;

    void main();
  public:
    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    void VMregister( VendingMachine *vendingmachine );
    VendingMachine *getMachine( unsigned int id );
    VendingMachine **getMachineList();
};

#endif

