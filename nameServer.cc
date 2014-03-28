#include "nameServer.h"

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents )
  : printer( prt ), nVendingMachines( numVendingMachines ), nStudents( numStudents ) {
    registered = 0;

    vendingMachines = new VendingMachine*[numVendingMachines];
    for( unsigned int i = 0; i < numVendingMachines; i += 1 ) {
        vendingMachines[i] = NULL;
    }
 
    studentAssignedVMs = new int[numStudents];
    for(unsigned int i = 0; i < numStudents; i++) {
        studentAssignedVMs[i] = i % numVendingMachines;
    }
}

NameServer::~NameServer() {
    delete [] vendingMachines;
    delete [] studentAssignedVMs;
}

void NameServer::main() {
    printer.print( Printer::NameServer, 'S' );
    for(;;) {
        _Accept( ~NameServer ) {
            break;
        }or _When ( registered < nVendingMachines ) _Accept( VMregister ) {
            registered += 1;
        }or _When ( registered == nVendingMachines ) _Accept( getMachine ) {
            studentAssignedVMs[lastId] = (studentAssignedVMs[lastId] + 1) % nVendingMachines;
        }or _When ( registered == nVendingMachines ) _Accept( getMachineList ) {
        }
    }
    printer.print( Printer::NameServer, 'F' );
}
    
void NameServer::VMregister( VendingMachine *vendingmachine ) {
    vendingMachines[vendingmachine->getId()] = vendingmachine;  
    printer.print( Printer::NameServer, 'R', vendingmachine->getId() );
}

VendingMachine *NameServer::getMachine( unsigned int sid ) {
    lastId = sid;
    printer.print(Printer::NameServer, 'N', sid, studentAssignedVMs[sid]);
    return vendingMachines[studentAssignedVMs[sid]];
}

VendingMachine **NameServer::getMachineList() {
    return vendingMachines;
}

