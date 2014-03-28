#ifndef __WATCARD_OFFICE_H__
#define __WATCARD_OFFICE_H__

#include "printer.h"
#include "bank.h"
#include "watcard.h"
#include <queue>

_Task WATCardOffice {
    struct Job {                           // marshalled arguments and return future
        unsigned int sid;
        unsigned int amount;
        WATCard *card;
        WATCard::FWATCard result;                   // return future
        Job( unsigned int sid, unsigned int amount, WATCard *card ) : sid( sid ), amount( amount ), card( card ) {}
    };

    _Task Courier {
        Printer &printer;
        WATCardOffice &cardOffice;
        Bank &bank;
        const unsigned int id;
        void main();
      public:
        Courier(Printer &printer, WATCardOffice &cardOffice, Bank &bank, unsigned int id);
        ~Courier(){}
    };                 // communicates with bank

    Printer &printer;
    Bank &bank;
    const unsigned int nCouriers;
    Courier **couriers;
    std::queue<Job*> jobs;

    unsigned int bufId;
    unsigned int bufAmt; 
    Job *bufJob;

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

