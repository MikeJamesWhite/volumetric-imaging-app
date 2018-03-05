#include "VolImage.h"

class WHTMIC023::VolImage {

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