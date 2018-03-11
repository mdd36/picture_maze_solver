#include <iostream>

#include "ImageProcessor.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    ImageProcessor imp = *(new ImageProcessor());

    auto* fName = const_cast<char *>(R"(.\..\data\simple.png)");
    cout << fName << endl;
    int M = 14;
    int N = 14;
    imp.ReadImage(fName, M, N);
    return 0;
}