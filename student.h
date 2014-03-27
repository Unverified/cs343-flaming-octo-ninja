#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "printer.h"
#include "nameServer.h"
#include "watcardOffice.h"
#include "watcard.h"
#include "vendingMachine.h"

_Task Student {
    Printer &printer;
    NameServer &nameServer;
    WATCardOffice &cardOffice;
    const unsigned int id;
    unsigned int maxPurchases;

    unsigned int purchases;
    VendingMachine::Flavours flavour;
    WATCard::FWATCard fwatCard;
    VendingMachine *machine;

    void main();
    void createNewCard();
  public:
    Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id,
             unsigned int maxPurchases );
    ~Student();
};

#endif

