/**
 * VolImage.cpp
 * 
 * Implementation file for the Volumetric Imaging Library, libVolImage.
 * 
 * Author: Mike White (WHTMIC023)
 * Date: 05/03/2018
 */

#include "VolImage.h"
#include <fstream>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ifstream;

using namespace WHTMIC023;

VolImage::VolImage() { // default constructor
}

VolImage::~VolImage() { // default destructor
}

bool VolImage::readImages(string baseName) {
    ifstream file = ifstream(baseName + ".data");
    int numSlices;        
    file >> width;
    file >> height;
    file >> numSlices;
    slices.reserve(numSlices);
    file.close();

    for (int i = 0; i < numSlices; i++) {
        file.open(baseName + std::to_string(i) + ".raw", std::ios_base::binary);

        unsigned char* ptrArr[height];
        for (int j = 0; j < height; j++) {
            unsigned char charArr[width];
            for (int k = 0; k < width; k++) {
                unsigned char val;
                file >> val;
                charArr[k] = val;
            }
            ptrArr[j] = charArr;
        }
        slices[i] = ptrArr;
        file.close();
    }
    return true;
}

void VolImage::diffmap(int sliceI, int sliceJ, string output_prefix) {

}

void VolImage::extract(int sliceId, string output_prefix) {

}

int VolImage::volImageSize(void) {

}
