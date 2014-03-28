#include "MPRNG.h"
#include "parent.h"

extern MPRNG mprng;

static const unsigned int MIN_CASH = 1;
static const unsigned int MAX_CASH = 3;

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
    printer.print( Printer::Parent, 'S' );
    for(;;) {
        _Accept( ~Parent ) {
            break;
        } _Else { 
            unsigned int winner = mprng( nStudents-1 );
            unsigned int amount = mprng( MIN_CASH, MAX_CASH );
            
            yield( delay );
            bank.deposit( winner, amount );
            printer.print( Printer::Parent, 'D', winner, amount );
        }

    }
    printer.print( Printer::Parent, 'F' );
}

