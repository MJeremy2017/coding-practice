//
//  main.cpp
//  template
//
//  Created by Yue Zhang on 8/3/21.
//

#include <iostream>
using namespace std;

// templates are evaluated at compile time
template<typename T, int N>

//void print_value(TT value) {
//    cout << value << endl;
//}

class Array {
private:
    T m_Array[N];
public:
    int get_size() const {
        return N;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    print_value(53);
//    print_value("addidas");
    
    Array<int, 10> arr;
    cout << arr.get_size() << endl;
    return 0;
}
