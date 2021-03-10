//
//  main.cpp
//  arrow
//
//  Created by Yue Zhang on 10/3/21.
//

#include <iostream>
using namespace std;

class Entity {
public:
    int x;
public:
    Entity(int value)
        :x(value) {}
    
    void Print() {
        cout << "Entity x: " << x << endl;
    }
};

class ScopedPtr {
private:
    Entity* ptr;
public:
    ScopedPtr(Entity* x) {
        ptr = x;
    }
    
    // override arrow
    Entity* operator->() {
        return ptr;
    }
    
    ~ScopedPtr() {
        delete ptr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ScopedPtr sp = new Entity(12);
    
    // -> overloaded a-> == a.operator->()
    sp->Print();
    return 0;
}
