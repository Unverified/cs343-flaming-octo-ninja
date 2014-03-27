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
  flavour = (VendingMachine::Flavours)mprng( 3 );
  fwatCard = cardOffice.create(id, 5);
  machine = nameServer.getMachine(id);

  printer.print(Printer::Student, id, 'V', machine->getId());
}

Student::~Student() {
    delete fwatCard;
}

void Student::main() {
    printer.print( Printer::Student, id, 'S', flavour, purchases);

    VendingMachine::Status purchaseStatus;    
    for(;purchases > 0;) {
        yield(mprng(1, 10));

        for(;;) {
            try {
                purchaseStatus = machine->buy(flavour, *fwatCard());
                break;
            } catch ( WATCardOffice::Lost ) {
                printer.print(Printer::Student, id, 'L');
                fwatCard = cardOffice.create(id, 5);
            }
        }

        switch(purchaseStatus) {
          case VendingMachine::STOCK:
            machine = nameServer.getMachine(id);
            printer.print(Printer::Student, id, 'V', machine->getId());
            break;
          case VendingMachine::FUNDS:
            fwatCard = cardOffice.transfer(id, machine->cost() + 5, fwatCard);
            
            break;
          case VendingMachine::BUY:
          printer.print(Printer::Student, id, 'B', flavour, machine->inventory()[flavour]);
          purchases--;
          default:
            break;
        }
    }

    printer.print( Printer::Student, id, 'F' );
}

