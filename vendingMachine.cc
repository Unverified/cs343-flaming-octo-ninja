#include "nameServer.h"

#include "vendingMachine.h"

VendingMachine::VendingMachine( Printer &prt
                              , NameServer &nameServer
                              , unsigned int id
                              , unsigned int sodaCost
                              , unsigned int maxStockPerFlavour )
  : printer( prt ), nameServer( nameServer ), id( id ), price( sodaCost ), maxStockPerFlavour( maxStockPerFlavour ) {
    for( unsigned int i; i < FINAL_COUNT; i += 1 ) {
        stock[i] = 1;   
    }

    nameServer.VMregister( this );
}

void VendingMachine::main() {
    printer.print( Printer::Vending, id, 'S', cost() );
    for(;;) {
        _Accept( ~VendingMachine ) {
            break;
        }or _Accept( buy, inventory, restocked ) {
        }
    }
    printer.print( Printer::Vending, id, 'F' );
}

VendingMachine::Status VendingMachine::buy( Flavours flavour, WATCard &card ) {
  if( stock[flavour] == 0 ) { return STOCK; }
  if( card.getBalance() < cost() ) { return FUNDS; }
    
    card.withdraw( cost() );
    printer.print( Printer::Vending, id, 'B', flavour, stock[flavour] );

  return BUY;
}

unsigned int *VendingMachine::inventory() {
  return stock;
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

