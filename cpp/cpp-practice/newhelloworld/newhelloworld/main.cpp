//
//  main.cpp
//  newhelloworld
//
//  Created by Yue Zhang on 10/2/21.
//

#include <iostream>
//#include "log.cpp"
using namespace std;

// a decoration telling there is such a function
void log(const char* msg);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "hello world" << endl;
    log("hello");
    return 0;
}
