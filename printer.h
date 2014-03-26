#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <iostream>
#include <list>

_Monitor Printer {
    struct Entry {					// Holds the info that should be print, is store in the buffer
      unsigned int col;						// The column this Entry should be printed in
      char state;					
      int value1;
      int value2;
      bool finisher;					// Indicates if this is the entry that caused a finish

      void print() {					// Print this buffer entry
        if(state == 'F' && !finisher) {	// If the entry is a Finished state and this is not the entry that caused the finish then print "..."
          std::cout << "...";
        } else {					// Else print the contents of this entry
          std::cout << state ;				// Print the state
          if(value1 > -1) std::cout << value1;		// Print value1 if there is one
          if(value2 > -1) std::cout << "," << value2;	// Print value2 if there is one
        }
      }
    };

    const unsigned int nStudents;
    const unsigned int nVendingMachines;
    const unsigned int nCouriers;

    unsigned int mNumCols;
    unsigned int mCurCol;

    std::list<Entry> mBuffer;

    void printStart();
    void printEnd();

    Entry createBufferEntry(unsigned int col, char state, int value1, int value2, bool finisher);	// Create a basic buffer entry with just id and state
    void addBufferEntry(unsigned int col, char state);				// Add a buffer entry, flushes if the entry already exists
    void addBufferEntry(unsigned int col, char state, int value1);		// Add a buffer entry, flushes if the entry already exists
    void addBufferEntry(unsigned int col, char state, int value1, int value2);	// Add a buffer entry, flushes if the entry already exists
    void addBufferEntry(unsigned int col, char state, int value1, int value2, bool finisher);	// Add a buffer entry, flushes if the entry already exists
    void flush();							// Flush the buffer
    void fillBufferWithEllipses(unsigned int finisherCol);			// Fill the buffer with Finish states that will be printed as ...
  public:
    enum Kind { Parent, WATCardOffice, NameServer, Truck, BottlingPlant, Student, Vending, Courier };
    Printer( unsigned int numStudents, unsigned int numVendingMachines, unsigned int numCouriers );
    ~Printer();
    void print( Kind kind, char state );
    void print( Kind kind, char state, int value1 );
    void print( Kind kind, char state, int value1, int value2 );
    void print( Kind kind, unsigned int lid, char state );
    void print( Kind kind, unsigned int lid, char state, int value1 );
    void print( Kind kind, unsigned int lid, char state, int value1, int value2 );

  private:
    int getCol(Kind kind, unsigned int lid);
};

#endif

