#include "nameServer.h"

#include "vendingMachine.h"

VendingMachine::VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour )
  : mPrinter(prt), mNameServer(nameServer), mId(id), mSodaCost(sodaCost), mMaxStockPerFlavour(maxStockPerFlavour) {

}

void VendingMachine::main() {
  mPrinter.print(Printer::Vending, mId, 'S');
}

VendingMachine::Status VendingMachine::buy( Flavours flavour, WATCard &card ) {
  bool implemented = false;
  assert(implemented);
  return Status();
}

unsigned int *VendingMachine::inventory() {
  bool implemented = false;
  assert(implemented);
  return 0;
}

void VendingMachine::restocked() {

}

_Nomutex unsigned int VendingMachine::cost() {
  bool implemented = false;
  assert(implemented);
  return 0;
}

_Nomutex unsigned int VendingMachine::getId() {
  bool implemented = false;
  assert(implemented);
  return 0;
}



