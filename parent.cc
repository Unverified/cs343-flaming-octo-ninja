#include "printer.h"
#include "bank.h"

#include "parent.h"

Parent::Parent( Printer &prt, 
                Bank &bank, 
                unsigned int numStudents, 
                unsigned int parentalDelay )
  : printer( prt )
  , bank( bank )
  , nStudents( numStudents )
  , delay( parentalDelay ) {
}

void Parent::main() {
}

