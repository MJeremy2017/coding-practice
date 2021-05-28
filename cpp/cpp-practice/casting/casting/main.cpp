//
//  main.cpp
//  casting
//
//  Created by Yue Zhang on 19/4/21.
//

#include <iostream>
#include <vector>
#include <map>
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
//    double value = 3.213;
//    double value2 = (int)value;
//    cout << value << " " << value2 << endl;
//
//    Derived* d = new Derived;
//    Base* b = d;
//    // downcasting
////    Derived* ac = dynamic_cast<Derived*>(b);  // runtime checking
//
////    if (ac) {
////        cout << ac << endl;
////    }
//
//    string S_name = "square";
//    int v = 3;
//    Shape* s = new Square(S_name, v);
//    s->get_info();
//
//    Square* sq = dynamic_cast<Square*>(s);
//
//    if (sq) {
//        sq->get_info();
//    }
//
//    vector<int> vec = {1, 2, 3, 4};
//    vector<int> new_vec = vector<int>(vec.begin(), vec.begin()+1);
//    cout << vec[0] << endl;
//    cout << vec.back() << endl;
////    vec.erase(vec.end());
//    for (auto i:new_vec) {
//        cout << i << endl;
//    }
//
    struct Case {
        string name;
    };
    
    Case* c1 = new Case;
    c1->name = "jj";
    cout << c1->name << endl;
    
    Case* c2 = c1;
    c2->name = "MM";
    cout << c1->name << endl;
    
    map<Case*, int> t;
    Case* c3 = new Case;
    c3->name = "hello";
    t[c3] = 1;
    
    Case* c4 = new Case;
    c4->name = "hello";
    t[c4] = 0;
    cout << "result of c3: " << t[c3] << " map size: " << t.size() << endl;  // size of 2
    
    map<int, int> m2;
    int a = 1;
    int b = 1;
    m2[a] = 1;
    m2[b] = 0;
    cout << m2.size() << endl;
    
    string str = "sataaaasddsa";
    // return the end of the pointer
    auto pend = remove(str.begin(), str.end(), 'a');
    for (auto it=str.begin(); it!=pend; it++) {
        cout << *it << " ";  // stsdds
    }
    
    
    return 0;
}
