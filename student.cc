#include "MPRNG.h"
#include "student.h"

extern MPRNG mprng;

Student::Student( Printer &prt, 
                  NameServer &nameServer, 
                  WATCardOffice &cardOffice, 
                  unsigned int id,
                  unsigned int maxPurchases )
  : printer( prt )
  , nameServer( nameServer )
  , cardOffice( cardOffice )
  , id ( id )
  , maxPurchases( maxPurchases ) {
      
  purchases = mprng( 1, maxPurchases );
  flavour = (VendingMachine::Flavours) mprng( VendingMachine::FLAVOUR_COUNT - 1 );
}

Student::~Student() {
    delete fwatCard;
}

void Student::main() {
    printer.print( Printer::Student, id, 'S', flavour, purchases);
    fwatCard = cardOffice.create( id, 5 );

    VendingMachine::Status purchaseStatus = VendingMachine::STOCK;    
    while( true ) {
        switch( purchaseStatus ) {
        case VendingMachine::STOCK:
            machine = nameServer.getMachine( id );
            printer.print( Printer::Student, id, 'V', machine->getId() );
          break;
        case VendingMachine::FUNDS:
            fwatCard = cardOffice.transfer( id, machine->cost() + 5, fwatCard );  
          break;
        case VendingMachine::BUY:
            printer.print( Printer::Student, id, 'B', fwatCard()->getBalance() );
            purchases -= 1;
        default:
          break;
        }

      if( purchases == 0 ) { break; }

        yield( mprng( 1, 10 ) );

        while(true){
            try {
                purchaseStatus = machine->buy( flavour, *fwatCard() );
                break;
            } catch ( WATCardOffice::Lost ) {
                printer.print( Printer::Student, id, 'L' );
                fwatCard = cardOffice.create( id, 5 );
            }
        }
    }
    printer.print( Printer::Student, id, 'F' );
}

