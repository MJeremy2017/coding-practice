//
//  main.cpp
//  casting
//
//  Created by Yue Zhang on 19/4/21.
//

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "This is base class" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "This is derived class" << endl;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    double value = 3.213;
    double value2 = (int)value;
    cout << value << " " << value2 << endl;
    
    Derived* d = new Derived;
    Base* b = d;
    // downcasting
//    Derived* ac = dynamic_cast<Derived*>(b);  // runtime checking
    
//    if (ac) {
//        cout << ac << endl;
//    }
    
    return 0;
}
