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
        Printer &mCPrinter;
        unsigned int mId;

        void main();
      public:
        Courier(Printer &printer, unsigned int id);
    };                 // communicates with bank

    Printer &mPrinter;
    Bank &mBank;
    unsigned int mNumCouriers;

    Courier **mCouriers;

    void main();
  public:
    _Event Lost {};                        // uC++ exception type, like "struct"
    WATCardOffice( Printer &prt, Bank &bank, unsigned int numCouriers );
    ~WATCardOffice();
    WATCard::FWATCard create( unsigned int sid, unsigned int amount );
    WATCard::FWATCard transfer( unsigned int sid, unsigned int amount, WATCard *card );
    Job *requestWork();
};

#endif

