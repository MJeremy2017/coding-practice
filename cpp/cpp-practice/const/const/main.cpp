//
//  main.cpp
//  const
//
//  Created by Yue Zhang on 25/2/21.
//

#include <iostream>
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
//    c = &value;  fail: pointer can not be re-assigned
    
    
    
    return 0;
}
