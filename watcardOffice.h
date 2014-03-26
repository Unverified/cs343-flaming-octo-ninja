#ifndef __WATCARD_OFFICE_H__
#define __WATCARD_OFFICE_H__

#include "printer.h"
#include "bank.h"
#include "watcard.h"

_Task WATCardOffice {
    struct Job {                           // marshalled arguments and return future
        //Args args;                         // call arguments (YOU DEFINE "Args")
        WATCard::FWATCard result;                   // return future
        Job( /*Args args ) : args( args*/ ) {}
    };

    _Task Courier {
        void main();
      public:
        Courier();
    };                 // communicates with bank

    Printer &mPrinter;
    Bank &mBank;
    unsigned int mNumCouriers;

    void main();
  public:
    _Event Lost {};                        // uC++ exception type, like "struct"
    WATCardOffice( Printer &prt, Bank &bank, unsigned int numCouriers );
    WATCard::FWATCard create( unsigned int sid, unsigned int amount );
    WATCard::FWATCard transfer( unsigned int sid, unsigned int amount, WATCard *card );
    Job *requestWork();
};

#endif

