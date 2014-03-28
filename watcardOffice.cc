#include "watcardOffice.h"

WATCardOffice::WATCardOffice( Printer &prt, Bank &bank, unsigned int numCouriers )
  : printer( prt ), bank( bank ), nCouriers( numCouriers ) {
    couriers = new Courier*[nCouriers];
    for( unsigned int i = 0; i < nCouriers; i += 1 ) {
        couriers[i] = new Courier( printer, *this, bank, i );
    }
}

WATCardOffice::~WATCardOffice() {
    for( unsigned int i = 0; i < nCouriers; i += 1 ) {
        delete couriers[i];
    }
    delete [] couriers;
}

void WATCardOffice::main() {
    printer.print( Printer::WATCardOffice, 'S' );
    for(;;){
        _Accept( ~WATCardOffice ) {
            while( !jobs.empty() ) {
                //trying to close expunge jobs
                delete jobs.front();
                jobs.pop();
            }
            for( unsigned int i; i < nCouriers; i += 1 ) { 
                //let in the couriers to give closing command
                _Accept( requestWork );
            }
            break;
        } or _When( !jobs.empty() ) _Accept( requestWork ) {
            printer.print( Printer::WATCardOffice, 'W' );
        } or _Accept( create ) {
            printer.print( Printer::WATCardOffice, 'C', bufId, bufAmt );
            jobs.push( bufJob );
        } or _Accept( transfer ) {
            printer.print( Printer::WATCardOffice, 'T', bufId, bufAmt );
            jobs.push( bufJob );
        }
    }
    printer.print( Printer::WATCardOffice, 'F' );
}



WATCard::FWATCard WATCardOffice::create( unsigned int sid, unsigned int amount ) {
    return transfer( sid, amount, new WATCard );
}

WATCard::FWATCard WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard *card ) {
    bufId = sid;
    bufAmt = amount;
    bufJob = new Job( sid, amount, card );
    
    return bufJob->result;
}

WATCardOffice::Job *WATCardOffice::requestWork() {
  if( jobs.empty() ) { return NULL; }
    Job *job = jobs.front();
    jobs.pop();
    return job;
}

WATCardOffice::Courier::Courier( Printer &printer, WATCardOffice &cardOffice, Bank &bank, unsigned int id )
  : printer( printer ), cardOffice( cardOffice ), bank( bank ), id( id ) {
}

void WATCardOffice::Courier::main() {
    printer.print( Printer::Courier, id, 'S' );
    for(;;) {
        Job *job = cardOffice.requestWork();
        if( job == NULL ) { break; }

        printer.print( Printer::Courier, id, 't', job->sid, job->amount );
        bank.withdraw( job->sid, job->amount );
        job->card->deposit( job->amount );
        job->result.delivery( job->card );
        printer.print( Printer::Courier, id, 'T', job->sid, job->amount );

        delete job;
    }
    printer.print( Printer::Courier, id, 'F' );
}

