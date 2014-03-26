#ifndef __NAME_SERVER_H__
#define __NAME_SERVER_H__

#include "printer.h"
#include "vendingMachine.h"

_Task NameServer {
    Printer &printer;
    const unsigned int nVendingMachines;
    const unsigned int nStudents;

    unsigned int lastId;
    unsigned int registered;
    VendingMachine **vendingMachines;
    
    void main();
  public:
    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    ~NameServer();
    void VMregister( VendingMachine *vendingmachine );
    VendingMachine *getMachine( unsigned int id );
    VendingMachine **getMachineList();
};

#endif

