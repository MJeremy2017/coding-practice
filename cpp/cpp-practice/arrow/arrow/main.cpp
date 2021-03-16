//
//  main.cpp
//  arrow
//
//  Created by Yue Zhang on 10/3/21.
//

#include <iostream>
#include <vector>
#include <benchmark.h>
#include <Engine.hpp>
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
    
    Entity(const Entity& other)
    :  x(other.x) {
        cout << "copy happened" << endl;
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


vector<int> decToBinary(int n)
{
    int len = 0;
    int arr[32];
    while (n) {
        arr[len] = n%2;
        n /= 2;
        len++;
    }
    
    vector<int> res;
    for (int i=len-1; i>=0; --i) {
        res.push_back(arr[i]);
    }
    return res;
}

void Binary2dec(vector<int> v) {
    int factor = 1;
    int res = 0;
    for (int i=0; i<v.size(); ++i) {
        res += v[i] * factor;
        factor *= 2;
    }
    cout << res << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // static library (.a, .lib) is loaded at compile time with all code from libraries are copied to the code
    // dynamic library (.so, .dll) is loaded at run time with refercence to the library code
    // https://domiyanyue.medium.com/c-development-tutorial-4-static-and-dynamic-libraries-7b537656163e
    ScopedPtr sp = new Entity(12);
    // -> overloaded a-> == a.operator->()
    sp->Print();

    // vectors
    vector<Entity> v;
    // 3 copies
    // construct entity and place into the vector makes a copy, expanding vector makes another copy
    v.push_back(Entity(2));
    v.push_back(Entity(3));

    cout << "-------" << endl;

    // 2 copies
    vector<Entity> v2;
    v2.reserve(2);
    v2.push_back(Entity(2));
    v2.push_back(Entity(3));

    cout << "-------" << endl;

    // 0 copies
    vector<Entity> v3;
    v3.reserve(2);
    v3.emplace_back(2);
    v3.emplace_back(3);
    
    // self build library
    engine::printMsg("hello world");

    return 0;
}
