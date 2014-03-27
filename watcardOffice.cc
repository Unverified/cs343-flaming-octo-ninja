#include "watcardOffice.h"

WATCardOffice::WATCardOffice( Printer &prt, Bank &bank, unsigned int numCouriers )
  : printer( prt ), bank( bank ), nCouriers( numCouriers ) {

    couriers = new Courier*[nCouriers];
    for( unsigned int i = 0; i < nCouriers; i += 1 ) {
        couriers[i] = new Courier( prt, *this, bank, i );
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
            while (!condCouriers.empty()) condCouriers.signal();
            break;
        } or _Accept(create, transfer, requestWork) {

        }
    }
    printer.print( Printer::WATCardOffice, 'F' );
}

WATCard::FWATCard WATCardOffice::create( unsigned int sid, unsigned int amount ) {
    WATCard *watCard = new WATCard();
    return transfer(sid, amount, watCard);
}

WATCard::FWATCard WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard *card ) {
    Job *job = new Job(sid, amount, card);
    jobs.push_back(job);

    if(!condCouriers.empty()) {
      condCouriers.signal();
    }

    return job->result;
}

WATCardOffice::Job *WATCardOffice::requestWork() {
    if(jobs.empty()) {
        condCouriers.wait();
    }

    if(jobs.empty()) return NULL;	// so couriers can unblock and terminate

    Job *job = jobs.front();
    jobs.pop_front();

    return job;
}

WATCardOffice::Courier::Courier( Printer &printer, WATCardOffice &cardOffice, Bank &bank, unsigned int id )
  : printer( printer ), cardOffice( cardOffice ), bank( bank ), id( id ) {

}

void WATCardOffice::Courier::main() {
    printer.print( Printer::Courier, id, 'S' );
    for(;;) {
        Job *job = cardOffice.requestWork();
        if( job == NULL ) break;
        printer.print(Printer::Courier, 't', job->sid, job->amount);
        bank.withdraw(job->sid, job->amount);
        job->card->deposit(job->amount);
        printer.print(Printer::Courier, 'T', job->sid, job->amount);
        job->result.delivery(job->card);
        delete job;
    }
    printer.print( Printer::Courier, id, 'F' );
}

