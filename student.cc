#include "printer.h"
#include "nameServer.h"
#include "watcardOffice.h"

#include "student.h"

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
}

void Student::main() {

}

