#include <iostream>
#include <sstream>
#include <unistd.h> //getpid();

#include "config.h"
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
        processConfigFile( configPath, cfgParms );
      break;
    default:
        usage( argv );
    }

}

