//
//  main.cpp
//  macros
//
//  Created by Yue Zhang on 19/3/21.
//

#include <iostream>
using namespace std;
#define PR_DEBUG 0
#if PR_DEBUG == 1
#define LOG(x) cout << x << endl
#else
#define LOG(x)
#endif

// return multiple variables
tuple<string, int> get2() {
    string s = "hello";
    int a = 3;
    return make_pair(s, a);
}


int main(int argc, const char * argv[]) {
    cout << "this is doing something" << endl;
    LOG("hello");
    LOG(DEBUG);
    
    int* arr = new int[]{1, 2};
    cout << arr[1] << endl;
    return 0;
}
