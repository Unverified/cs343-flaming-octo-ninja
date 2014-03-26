#include "nameServer.h"

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents )
  : printer( prt ), nVendingMachines( numVendingMachines ), nStudents( numStudents ) {

}

void NameServer::main(){
}
    
void NameServer::VMregister( VendingMachine *vendingmachine ) {
  
}

VendingMachine *NameServer::getMachine( unsigned int id ) {
  bool implemented = false;
  assert(implemented);
  return NULL;
}

VendingMachine **NameServer::getMachineList() {
  bool implemented = false;
  assert(implemented);
  return NULL;
}

