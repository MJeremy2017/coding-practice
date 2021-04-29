//
//  main.cpp
//  casting
//
//  Created by Yue Zhang on 19/4/21.
//

#include <iostream>
#include <vector>
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

// The parent class
class Shape {
  string s_name;
  public:
    Shape(string name): s_name(name){}
    
    virtual void get_info(){
        cout<< s_name <<endl;
    }
};

// The child class
class Square : public Shape {
    int side;
  public:
    Square(string S_name, int value)
      : Shape(S_name), side(value){}
    
    void get_info(){
      cout << "Area of the square is: "<< side * side << endl;
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
    
    string S_name = "square";
    int v = 3;
    Shape* s = new Square(S_name, v);
    s->get_info();
    
    Square* sq = dynamic_cast<Square*>(s);
    
    if (sq) {
        sq->get_info();
    }
    
    vector<int> vec = {1, 2, 3, 4};
//    int x = 1;
    vector<int> new_vec = vector<int>(vec.begin(), vec.begin()+1);
    cout << vec[0] << endl;
    cout << vec.back() << endl;
//    vec.erase(vec.end());
    for (auto i:new_vec) {
        cout << i << endl;
    }
    
    return 0;
}
