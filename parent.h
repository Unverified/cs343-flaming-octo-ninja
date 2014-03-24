#ifndef __PARENT_H__
#define __PARENT_H__

_Task Parent {
    Printer &printer;
    Bank &bank;
    const unsigned int delay;
    const unsigned int nStudents;

    void main();
  public:
    Parent( Printer &prt, Bank &bank, unsigned int numStudents, unsigned int parentalDelay );
};

#endif

