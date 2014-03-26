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
      flavour = mprng( 3 );
}

void Student::main() {
    printer.print( Printer::Student, id, 'S', flavour, purchases);
    
    printer.print( Printer::Student, id, 'F' );
}

