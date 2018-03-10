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

using namespace WHTMIC023;
using std::string;
using std::cout;

int main(int argc, const char* argv []) {
    VolImage* vol = new VolImage;
    VolImage volume = *vol;
    volume.readImages(string(argv[1]));
    cout << "Number of bytes required: " << std::to_string(volume.volImageSize()) << std::endl;
    if (argv[2] == NULL) {
        return 0;
        delete(vol);
    }
    
    string option = string(argv[2]);
    if (option == "-x") {

    }
    else if (option == "-d") {

    }
    else {
        cout << "Unrecognised command: " << option << ". Exiting...";
        return 1;
    }
}