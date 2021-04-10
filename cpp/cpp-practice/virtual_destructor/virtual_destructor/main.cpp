//
//  main.cpp
//  virtual_destructor
//
//  Created by Yue Zhang on 7/4/21.
//

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor" << endl;
    }
    
    // indicate that this destructor could be extended
    virtual ~Base() {
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor" << endl;
    }

    ~Derived() {
        cout << "Derived Destructor" << endl;
    }

};

int main(int argc, const char * argv[]) {
    int x = 5;
    int y = 2;
    if (x&y) {
        cout << "dsfasdfs" << endl;
    }
    
    // insert code here...
    Base* base = new Base;
    delete base;
    
    cout << "---------------------" << endl;
    
    Derived* derived = new Derived;
    delete derived;

    cout << "---------------------" << endl;
    
    Base* poly = new Derived;
    delete poly;

    return 0;
}
