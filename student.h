#ifndef __STUDENT_H__
#define __STUDENT_H__

_Task Student {
    Printer &printer;
    NameServer &nameServer;
    WATCardOffice &cardOffice;
    const unsigned int id;
    unsigned int maxPurchases;

    void main();
  public:
    Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id,
             unsigned int maxPurchases );
};

#endif

