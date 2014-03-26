#include "parent.h"

Parent::Parent( Printer &prt, 
                Bank &bank, 
                unsigned int numStudents, 
                unsigned int parentalDelay )
  : mPrinter( prt )
  , bank( bank )
  , nStudents( numStudents )
  , delay( parentalDelay ) {
}

void Parent::main() {
  mPrinter.print(Printer::Parent, 'S');
}

