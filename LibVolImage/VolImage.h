/**
 * VolImage.h
 * 
 * Header file for the Volumetric Imaging Library, libVolImage.
 * 
 * Author: Mike White (WHTMIC023)
 * Date: 05/03/2018
 */
#ifndef VOL_IMAGE
#define VOL_IMAGE

#include <vector.h>

namespace WHTMIC023 {

class VolImage {

private:

    int width, height;
    vector <unsigned char**> slices;

public:

    VolImage(); // default constructor
    VolImage(); // default destructor


    bool readImages(string baseName);

    void diffmap(int sliceI, int sliceJ, string output_prefix);

    void extract(int sliceId, string output_prefix);

    int volImageSize(void);
};

}

#endif