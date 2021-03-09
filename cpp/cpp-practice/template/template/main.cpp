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

class MyString {
private:
    char* buffer;
    unsigned int size;
public:
    MyString(const char* s) {
        size = int(strlen(s));
        buffer = new char[size+1];
        memcpy(buffer, s, size);
        // add end character
        buffer[size] = 0;
    }

    char& operator[](int index) {
        return buffer[index];
    }
    
    // copy constructor
    MyString(const MyString& another) {
        cout << "string is copied" << endl;
        // to perform a deep copy
        size = another.size;
        buffer = new char[size+1];
        memcpy(buffer, another.buffer, size+1);
    }

    ~MyString() {
        delete buffer;
    }
        
    friend ostream& operator<<(ostream& stream, const MyString& s);
};

// if not with '&
void printMyString(MyString& s) {
    cout << s << endl;
}

ostream& operator<<(ostream& stream, const MyString& s) {
    stream << s.buffer;
    return stream;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    print_value(53);
//    print_value("addidas");
    MyString a = "asdfsd";
    MyString b = a;
    
    cout << a << " " << b << endl;
    printMyString(a);
    
    Array<int, 10> arr;
    cout << arr.get_size() << endl;
    
    return 0;
}
