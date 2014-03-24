#include <iostream>
#include <unistd.c>

#include "MPRNG.h"

MPRNG mprng;
using namespace std;

void usage( char *argv[] ) {
    cout << argv[0] << " [ config-file [ random-seed (> 0) ] ]" << endl;
    exit( EXIT_SUCCESS );
}


void uMain::main() {
    char defaultfile[] = "soda.config";
    int seed = getpid();

}

