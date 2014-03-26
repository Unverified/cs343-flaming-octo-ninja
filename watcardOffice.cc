#include "watcardOffice.h"


WATCardOffice::WATCardOffice( Printer &prt, Bank &bank, unsigned int numCouriers )
  : mPrinter(prt), mBank(bank), mNumCouriers(numCouriers) {

    mCouriers = new Courier*[mNumCouriers];
    for(unsigned int i = 0; i < mNumCouriers; i++) {
        mCouriers[i] = new Courier(mPrinter, i);
    }
}

WATCardOffice::~WATCardOffice() {
    for(unsigned int i = 0; i < mNumCouriers; i++) {
        delete mCouriers[i];
    }

    delete[] mCouriers;
}

void WATCardOffice::main() {
    mPrinter.print(Printer::WATCardOffice, 'S');
}

WATCard::FWATCard WATCardOffice::create( unsigned int sid, unsigned int amount ) {
    bool implemented = false;
    assert( implemented );
    return NULL;
}

WATCard::FWATCard WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard *card ) {
    bool implemented = false;
    assert( implemented );
    return NULL;
}

WATCardOffice::Job *WATCardOffice::requestWork() {
    bool implemented = false;
    assert( implemented );
    return NULL;
}

WATCardOffice::Courier::Courier(Printer &printer, unsigned int id) : mCPrinter(printer), mId(id) {

}

void WATCardOffice::Courier::main() {
  mCPrinter.print(Printer::Courier, mId, 'S');
}

