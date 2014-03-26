#include "printer.h"

using namespace std;

Printer::Printer( unsigned int numStudents, unsigned int numVendingMachines, unsigned int numCouriers ) 
  : nStudents( numStudents ), nVendingMachines( numVendingMachines ), nCouriers( numCouriers ) {

  mNumCols = 5 + nStudents + nVendingMachines + nCouriers;
  mCurCol = 0;
  printStart();
}

Printer::~Printer() {
  printEnd();
}

void Printer::printStart() {
  cout << "Parent\tWATOff\tNames\tTruck\tPlant";

  for(unsigned int i = 0; i < nStudents; i++) {
    cout << "\tStud" << i;
  }

  for(unsigned int i = 0; i < nVendingMachines; i++) {
    cout << "\tMach" << i;
  }

  for(unsigned int i = 0; i < nCouriers; i++) {
    cout << "\tCour" << i;
  }
  cout << endl;

  for(unsigned int i = 0; i < mNumCols; i++) {
    if(i > 0) cout << "\t";
    cout << "*******";
  }
  cout << endl;
}

void Printer::printEnd() {
  flush();
  cout << "\n**********************" << endl;
}

void Printer::flush() {
  for( ; !mBuffer.empty(); mCurCol++) {	// Constintly loop, printing whats at the front of the buffer and breaking if the buffer is empty
    Entry entry = mBuffer.front();
    if(entry.col < mCurCol) {		// If the next id in the buffer is less than the current column we are printing we need to wrap to the next line
      cout << endl;			// Print a newline
      mCurCol = 0;				// Set the column we are printing to the first one, ie 0
    }
 
    if(mCurCol != 0) cout << "\t";		// Print a tab character is the column we are printing is no the first one
    if(entry.col == mCurCol) {		// If the column we are printing matches the next id in the buffer then print that entry
      entry.print();			// Prints the entry
      mBuffer.pop_front();		// Remove the entry from the buffer
    }
  }
}

Printer::Entry Printer::createBufferEntry(unsigned int col, char state, int value1, int value2, bool finisher) {
  Entry entry;
  entry.col = col;
  entry.state = state;
  entry.value1 = value1;
  entry.value2 = value2;
  entry.finisher = finisher;
  return entry;
}

void Printer::addBufferEntry(unsigned int col, char state) {
  if(state == 'F') printFinish(col);
  else addBufferEntry(col, state, -1, -1, false);
}

void Printer::addBufferEntry(unsigned int col, char state, int value1) {	
  addBufferEntry(col, state, value1, -1, false);
}

void Printer::addBufferEntry(unsigned int col, char state, int value1, int value2) {	
  addBufferEntry(col, state, value1, value2, false);
}

void Printer::addBufferEntry(unsigned int col, char state, int value1, int value2, bool finisher) {	// Add an entry to the back of the buffer
  list<Entry>::iterator it;

  for (it = mBuffer.begin();;it++) {
    if(it == mBuffer.end() || it->col > col) {
      break;
    } else if(it->col == col) {
      flush();
      it = mBuffer.begin();
      break;
    }
  }
  
  mBuffer.insert(it, createBufferEntry(col, state, value1, value2, finisher));
}

void Printer::printFinish(unsigned int finishedCol) {// Fill all the empty spaces in the buffer with finished state
  flush();
  for(unsigned int i = 0; i < mNumCols; i++) {			// Add entries behind of the finished task in the buffer
    if(i == finishedCol) addBufferEntry(i, 'F', -1, -1, true);
    else addBufferEntry(i, 'F', -1, -1, false);
  }
}

int Printer::getCol(Kind kind, unsigned int lid) {
  switch(kind) {
    case Student:
      return 5 + lid;
    case Vending:
      return 5 + nStudents + lid;
    case Courier:
      return 5 + nStudents + nVendingMachines + lid;
    default:
      return kind;
  }
}

void Printer::print( Kind kind, char state ) {
  addBufferEntry(getCol(kind, 0), state);
}

void Printer::print( Kind kind, char state, int value1 ) {
  addBufferEntry(getCol(kind, 0), state, value1);
}

void Printer::print( Kind kind, char state, int value1, int value2 ) {
  addBufferEntry(getCol(kind, 0), state, value1, value2);
}

void Printer::print( Kind kind, unsigned int lid, char state ) {
  addBufferEntry(getCol(kind, lid), state);
}

void Printer::print( Kind kind, unsigned int lid, char state, int value1 ) {
  addBufferEntry(getCol(kind, lid), state, value1);
}

void Printer::print( Kind kind, unsigned int lid, char state, int value1, int value2 ) {
  addBufferEntry(getCol(kind, lid), state, value1, value2);
}
