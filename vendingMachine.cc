#include "nameServer.h"

#include "vendingMachine.h"

VendingMachine::VendingMachine( Printer &prt
                              , NameServer &nameServer
                              , unsigned int id
                              , unsigned int sodaCost
                              , unsigned int maxStockPerFlavour )
  : printer( prt ), nameServer( nameServer ), id( id ), price( sodaCost ), maxStockPerFlavour( maxStockPerFlavour ) {

}

void VendingMachine::main() {
  printer.print( Printer::Vending, id, 'S' );
}

VendingMachine::Status VendingMachine::buy( Flavours flavour, WATCard &card ) {
    bool implemented = false;
    assert( implemented );
    return Status();
}

unsigned int *VendingMachine::inventory() {
    bool implemented = false;
    assert( implemented );
    return 0;
}

void VendingMachine::restocked() {
    bool implemented = false;
    assert( implemented );
}

_Nomutex unsigned int VendingMachine::cost() {
    return price;
}

_Nomutex unsigned int VendingMachine::getId() {
    return id;
}



