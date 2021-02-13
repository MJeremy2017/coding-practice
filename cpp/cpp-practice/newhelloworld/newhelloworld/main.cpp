//
//  main.cpp
//  newhelloworld
//
//  Created by Yue Zhang on 10/2/21.
//

// what compiler does?
// 1. preprocessor preprocess and copy include header files into the current file
// 2. compiler compile the file into machine code result in .obj files
#include <iostream>
#include <benchmark/benchmark.h>
#include "log.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << sizeof(true) << endl;  // 1 byte
    
    // linker link to log function in another .cpp file
    init_log();
    log("hello");
    return 0;
}
