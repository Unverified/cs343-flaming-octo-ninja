#ifndef __BANK_H__
#define __BANK_H__

_Monitor Bank {
    const unsigned int nStudents;
    unsigned int *balance;
    uCondition *overdrawn;

  public:
    Bank( unsigned int numStudents );
    ~Bank();
    void deposit( unsigned int id, unsigned int amount );
    void withdraw( unsigned int id, unsigned int amount );
};

#endif

