#include <iostream>

#include <dlfcn.h>
#include "FileParser.h"

using namespace std;

int main() {
//    dlopen("libpython3.6.so.1.0", RTLD_NOW | RTLD_NOLOAD | RTLD_GLOBAL);
//    cout << "LOADING IMAGE" << endl;
//
//    //Use python to parse the image
//    string dataSource = "simple";
//    string command = R"(python ./../resources/im-to-text.py )";
//    command += dataSource;
//    system(command.c_str());

    cout << "BEGINNING MAZE SOLVING" << endl;

    //CODE HERE TO SOLVE THE MAZE
    auto parser = *(new FileParser());
    parser.createGraph("./../data/simple.txt");

//    cout << "GENERATING IMAGE OUTPUT" << endl;
//
//    command = R"(python ./../resources/text-to-im.py )";
//    command += dataSource;
//    system(command.c_str());

    cout << "DONE" << endl;
    return 0;
}