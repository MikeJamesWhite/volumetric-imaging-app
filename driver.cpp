/**
 * driver.cpp
 * 
 * Driver program to run the volumetric imaging library.
 * 
 * Author: Michael White (WHTMIC023)
 * Date: 09/03/2018
 */

#include "VolImage.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace WHTMIC023;
using std::string;
using std::cout;
using std::endl;
using std::stringstream;

int main(int argc, const char* argv []) {
    VolImage volume;
    volume.readImages(string(argv[1]));
    cout << "Number of bytes required: " << std::to_string(volume.volImageSize()) << std::endl;
    if (argv[2] == NULL) {
        return 0;
    }

    string option = string(argv[2]);
    if (option == "-x") { // extract normal slice
        int i = 0;
        stringstream ss = stringstream(argv[3]);
        ss >> i;
        string outputFile = string(argv[4]);
        volume.extract(i, outputFile);
    }
    else if (option == "-d") { // calculate diffmap
        int i, j = 0;
        stringstream ss = stringstream(argv[3]);
        ss >> i;
        ss = stringstream(argv[4]);
        ss >> j;
        string outputFile = string(argv[5]);
        volume.diffmap(i, j, outputFile);
    }
    else if (option == "-g") { // extract vertical slice
        int i = 0;
        stringstream ss = stringstream(argv[3]);
        ss >> i;
        string outputFile = string(argv[4]);
        volume.rowExtract(i, outputFile);
    }
    else {
        cout << "Unrecognised command: " << option << ". Exiting...";
        return 1;
    }
    return 0;
}