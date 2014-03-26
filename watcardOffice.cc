#include "watcardOffice.h"

WATCardOffice::WATCardOffice( Printer &prt, Bank &bank, unsigned int numCouriers )
  : printer( prt ), bank( bank ), nCouriers( numCouriers ) {

    couriers = new Courier*[nCouriers];
    for( unsigned int i = 0; i < nCouriers; i += 1 ) {
        couriers[i] = new Courier( prt, i );
    }
}

WATCardOffice::~WATCardOffice() {
    for( unsigned int i = 0; i < nCouriers; i += 1 ) {
        delete couriers[i];
    }

    delete[] couriers;
}

void WATCardOffice::main() {
    printer.print( Printer::WATCardOffice, 'S' );
    for(;;){
        _Accept( ~WATCardOffice ) {
            break;
        }
    }
    printer.print( Printer::WATCardOffice, 'F' );
}

WATCard::FWATCard WATCardOffice::create( unsigned int sid, unsigned int amount ) {
    bool implemented = false;
    assert( implemented );
    return NULL;
}

WATCard::FWATCard WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard *card ) {
    bool implemented = false;
    assert( implemented );
    return NULL;
}

WATCardOffice::Job *WATCardOffice::requestWork() {
    bool implemented = false;
    assert( implemented );
    return NULL;
}

WATCardOffice::Courier::Courier( Printer &printer, unsigned int id )
  : printer( printer ), id( id ) {

}

void WATCardOffice::Courier::main() {
    printer.print( Printer::Courier, id, 'S' );
    for(;;) {
        _Accept( ~Courier ) {
            break;
        }
    }
    printer.print( Printer::Courier, id, 'F' );
}

