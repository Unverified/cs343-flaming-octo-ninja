#include "nameServer.h"

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents )
  : printer( prt ), nVendingMachines( numVendingMachines ), nStudents( numStudents ) {
    registered = 0;

    vendingMachines = new VendingMachine*[numVendingMachines];
    for( unsigned int i = 0; i < numVendingMachines; i += 1 ) {
        vendingMachines[i] = NULL;
    }
}

NameServer::~NameServer() {
    delete[] vendingMachines;
}

void NameServer::main() {
    printer.print( Printer::NameServer, 'S' );

    for(;;) {
        _Accept( ~NameServer ) {
            break;
        }or _When ( registered < nVendingMachines ) _Accept( VMregister ) {
            printer.print( Printer::NameServer, 'R', lastId );
            registered += 1;
        }or _When ( registered == nVendingMachines ) _Accept( getMachine, getMachineList ) {

        }
    }
}
    
void NameServer::VMregister( VendingMachine *vendingmachine ) {
    lastId = vendingmachine->getId();
    vendingMachines[vendingmachine->getId()] = vendingmachine;  
}

VendingMachine *NameServer::getMachine( unsigned int id ) {
    return vendingMachines[id];
}

VendingMachine **NameServer::getMachineList() {
    return vendingMachines;
}

