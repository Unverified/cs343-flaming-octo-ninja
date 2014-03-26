#ifndef __PARENT_H__
#define __PARENT_H__

#include "printer.h"
#include "bank.h"

_Task Parent {
    Printer &mPrinter;
    Bank &bank;
    const unsigned int nStudents;
    const unsigned int delay;

    void main();
  public:
    Parent( Printer &prt, Bank &bank, unsigned int numStudents, unsigned int parentalDelay );
};

#endif

