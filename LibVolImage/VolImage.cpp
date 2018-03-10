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
using std::endl;
using std::cout;

using namespace WHTMIC023;

VolImage::VolImage() { // default constructor
}

VolImage::~VolImage() { // destructor
    for (int i = 0; i < slices.size(); i++) {
        for (int j = 0; j < height; j++) {
            delete(slices[i][j]);
        }
        delete(slices[i]);
    }
}

bool VolImage::readImages(string baseName) {
    ifstream file = ifstream(baseName + ".data");
    int numSlices;        
    file >> width;
    file >> height;
    file >> numSlices;
    cout << "filepath: " << baseName << endl << "width: " << width << endl << "height: " << height << endl << "number of images: " << numSlices << endl;
    slices.reserve(numSlices);
    file.close();

    for (int i = 0; i < numSlices; i++) {
        file.open(baseName + std::to_string(i) + ".raw", std::ios_base::in | std::ios_base::binary);

        unsigned char** ptrArr = new unsigned char* [height];
        for (int j = 0; j < height; j++) {
            unsigned char* charArr = new unsigned char [width];
            for (int k = 0; k < width; k++) {
                file.read((char*) &charArr[k], 1);
            }
            ptrArr[j] = charArr;
        }
        slices.push_back(ptrArr);
        file.close();
    }
    printf("Byte [1][1][1]: %u\n", slices[1][1][1]);
    return true;
}

void VolImage::diffmap(int sliceI, int sliceJ, string output_prefix) {

}

void VolImage::extract(int sliceId, string output_prefix) {

}

int VolImage::volImageSize(void) {
    return (slices.size() * (width * height)) + (slices.size() * (4 + ( 4 * height)));
}
