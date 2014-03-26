#include "nameServer.h"

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents )
  : printer( prt ), nVendingMachines( numVendingMachines ), nStudents( numStudents ) {
    vendingMachines = new VendingMachine*[numVendingMachines];
}

NameServer::~NameServer() {
    delete[] vendingMachines;
}

void NameServer::main() {
    printer.print( Printer::NameServer, 'S' );
}
    
void NameServer::VMregister( VendingMachine *vendingmachine ) {
    vendingMachines[vendingmachine->getId()] = vendingmachine;  
}

VendingMachine *NameServer::getMachine( unsigned int id ) {
    return vendingMachines[id];
}

VendingMachine **NameServer::getMachineList() {
    return vendingMachines;
}

