#include "bank.h"

Bank::Bank( unsigned int numStudents )
  : nStudents( numStudents ) {
    balance = new unsigned int[numStudents];
    overdrawn = new uCondition[numStudents];

    for( unsigned int i = 0; i < numStudents; i += 1 ){
        balance[i] = 0;
    }
}

Bank::~Bank() {
    delete[] balance;
    delete[] overdrawn;
}

void Bank::deposit( unsigned int id, unsigned int amount ) {
    assert( id < nStudents );
    balance[id] += amount;
    overdrawn[id].signal();
}

void Bank::withdraw( unsigned int id, unsigned int amount ) {
    assert( id < nStudents );
    while( balance[id] < amount ) {
        overdrawn[id].wait();
    }
    balance[id] -= amount;
}

