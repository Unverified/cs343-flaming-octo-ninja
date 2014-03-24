#include "vendingMachine.h"
#include "printer.h"
#include "nameServer.h"

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents )
  : printer( prt ), nVendingMachines( numVendingMachines ), nStudents( numStudents ) {

}
    
void NameServer::VMregister( VendingMachine *vendingmachine ){
}

VendingMachine *NameServer::getMachine( unsigned int id ){
}

VendingMachine **NameServer::getMachineList(){
}

void NameServer::main(){
}

