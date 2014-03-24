#ifndef __NAME_SERVER_H__
#define __NAME_SERVER_H__

_Task NameServer {
    unsigned int nVendingMachines;
    unsigned int nStudents;
    Printer &printer;

    void main();
  public:
    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    void VMregister( VendingMachine *vendingmachine );
    VendingMachine *getMachine( unsigned int id );
    VendingMachine **getMachineList();
};

#endif

