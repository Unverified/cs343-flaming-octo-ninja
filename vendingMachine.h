#ifndef __VENDING_MACHINE_H__
#define __VENDING_MACHINE_H__

#include "printer.h"
#include "watcard.h"

_Task NameServer;

_Task VendingMachine {
    Printer &printer;
    NameServer &nameServer;
    const unsigned int id;
    const unsigned int price;
    const unsigned int maxStockPerFlavour;


    void main();
  public:
    enum Flavours { CHERRY, CREAMSODA, ROOTBEER, LIME, FINAL_COUNT }; // flavours of soda (YOU DEFINE)
    enum Status { BUY, STOCK, FUNDS };     // purchase status: successful buy, out of stock, insufficient funds
    VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    Status buy( Flavours flavour, WATCard &card );
    unsigned int *inventory();
    void restocked();
    _Nomutex unsigned int cost();
    _Nomutex unsigned int getId();
  private:
    unsigned int stock[FINAL_COUNT];
  
};

#endif

