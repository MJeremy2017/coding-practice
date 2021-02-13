//
//  log.cpp
//  newhelloworld
//
//  Created by Yue Zhang on 10/2/21.
//
#include <iostream>
using namespace std;

// actual definition of function
void log(const char* msg) {
    cout << msg << endl;
}

void init_log() {
    log("log init");
}
