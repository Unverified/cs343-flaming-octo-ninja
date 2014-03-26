#include "watcardOffice.h"


WATCardOffice::WATCardOffice( Printer &prt, Bank &bank, unsigned int numCouriers )
  : mPrinter(prt), mBank(bank), mNumCouriers(numCouriers) {

}

void WATCardOffice::main() {

}

WATCard::FWATCard WATCardOffice::create( unsigned int sid, unsigned int amount ) {
  bool implemented = false;
  assert(implemented);
  return NULL;
}

WATCard::FWATCard WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard *card ) {
  bool implemented = false;
  assert(implemented);
  return NULL;
}

WATCardOffice::Job *WATCardOffice::requestWork() {
  bool implemented = false;
  assert(implemented);
  return NULL;
}

WATCardOffice::Courier::Courier() {

}

void WATCardOffice::Courier::main() {

}

