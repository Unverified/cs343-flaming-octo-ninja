#include <iostream>
#include <sstream>
#include <unistd.h> //getpid();

#include "config.h"
#include "printer.h"
#include "bank.h"
#include "parent.h"
#include "watcardOffice.h"
#include "nameServer.h"
#include "vendingMachine.h"
#include "bottlingPlant.h"
#include "student.h"

#include "MPRNG.h"

MPRNG mprng;
using namespace std;

bool convert( int &val, char *buffer ) {// convert C string to integer
    std::stringstream ss( buffer );     // connect stream and buffer
    ss >> dec >> val;                   // convert integer from buffer
    return !ss.fail() &&                // conversion successful ?
                                        // characters after conversion all blank ?
        string( buffer ).find_first_not_of( " ", ss.tellg() ) == string::npos;
}

void usage( char *argv[] ) {
    cout << "usage: " << argv[0] << " [ config-file [ random-seed (> 0) ] ]" << endl;
    exit( EXIT_SUCCESS );
}

void uMain::main() {
    int seed = getpid();
    ConfigParms cfgParms;
    
    char defaultConfigPath[] = "soda.config";
    char *configPath = defaultConfigPath;

    switch( argc ) {
    case 3:
        if( !convert( seed, argv[2] ) || seed < 0 ) {
            usage( argv );
        }
    case 2:
        configPath = argv[1];
    case 1:
        cout << seed << endl;
        mprng.seed( seed );
        processConfigFile( configPath, cfgParms );
      break;
    default:
        usage( argv );
    }

    /* Create everything, must be done in this order as per assignment spec. */

    Printer printer( cfgParms.numStudents, cfgParms.numVendingMachines, cfgParms.numCouriers );
    Bank bank( cfgParms.numStudents );
    Parent parent( printer, bank, cfgParms.numStudents, cfgParms.parentalDelay );
    WATCardOffice cardOffice( printer, bank, cfgParms.numCouriers );
    NameServer nameServer( printer, cfgParms.numVendingMachines, cfgParms.numStudents );

    VendingMachine *vendingMachines[cfgParms.numVendingMachines];
    for(unsigned int i = 0; i < cfgParms.numVendingMachines; i++) {
      vendingMachines[i] = new VendingMachine( printer, nameServer, i, cfgParms.sodaCost, cfgParms.maxStockPerFlavour );
    }

    BottlingPlant *bottlingPlant = new BottlingPlant( printer, nameServer, cfgParms.numVendingMachines, cfgParms.maxShippedPerFlavour, cfgParms.maxStockPerFlavour, cfgParms.timeBetweenShipments );

    Student *students[cfgParms.numStudents];
    for(unsigned int i = 0; i < cfgParms.numStudents; i++) {
      students[i] = new Student( printer, nameServer, cardOffice, i, cfgParms.maxPurchases );
    }
    
    /* Delete all the tasks */

    for(unsigned int i = 0; i < cfgParms.numStudents; i++) {
      delete students[i];
    }

    delete bottlingPlant;	// Must be done before deleting vending machines or deadlock can occur

    for(unsigned int i = 0; i < cfgParms.numVendingMachines; i++) {
      delete vendingMachines[i];
    }
}







