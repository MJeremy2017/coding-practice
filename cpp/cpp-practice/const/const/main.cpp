//
//  main.cpp
//  const
//
//  Created by Yue Zhang on 25/2/21.
//

#include <iostream>
#include <memory>
using namespace std;

class Entity {
private:
    int x, y;
public:
    // put const on the right of function is saying class members
    // inside the function should not be modified
    // here the variable is allowed to reassign but not inside this function
    int getX() const {
//        x = 3; not allowed to reassign
        return x;
    }
};

void printEntity(const Entity& e) {
    int value = e.getX();
    cout << value << endl;
}

class A {
public:
    void show()
    {
        cout << "A::show()" << endl;
    }
};


int main() {
    // insert code here...
    int value = 11;
    cout << value << endl;
    const int A = 3;  // A should not be modified
    cout << A << endl;
    int *a = new int;
    *a = 12;  // change the value of the pointer pointing to
//    a = &A;  fail int* pointer is incompatible with const int*
    cout << *a << endl;
    
    const int* b = new int(3);  // const type pointer: the value at the pointer can't be modified
//    *b = 22;  fail:
    cout << *b << endl;
    
    int* const c = new int;  // pointer is a constant that the pointer forever points to a fixed address
    *c = 11;
    *c = 12;
    
    unique_ptr<class A> p1(new class A);
    p1->show();
    cout << p1.get() << endl;
    
    unique_ptr<class A> p2 = move(p1);
    cout << p1.get() << endl;  // becomes null
    cout << p2.get() << endl;
    
    cout << "shared pointer" << endl;
    shared_ptr<class A> pp1(new class A);
    shared_ptr<class A> pp2(pp1);
    
    cout << pp1.use_count() << endl;
    cout << pp2.use_count() << endl;
    cout << "pp1 relinquishes ownership" << endl;
    pp1.reset();
    // Many shared_ptr can point to a single resource. shared_ptr maintains reference count for this propose. when all shared_ptr’s pointing to resource goes out of scope the resource is destroyed.
    cout << pp1.use_count() << endl;
    cout << pp2.use_count() << endl;
    
    return 0;
}
