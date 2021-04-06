//
//  main.cpp
//  static_array
//
//  Created by Yue Zhang on 25/3/21.
//

#include <iostream>
#include <array>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    array<int, 3> arr;
    arr[1] = 2;
    arr[4] = 3;
    
    // lambda
    int a = 10;
    auto lambda_func = [=](int value){  // pass outside value by value copy
        cout << a << endl;
        cout << value << endl;
        return "done";
    };
    
    string c = lambda_func(3);
    cout << c << endl;
    
    vector<int> aa = {1, 2, 4, 2};
    auto it = find_if(aa.begin(), aa.end(), [](int value) {return value > 3;});
    cout << *it << endl;
    
    stack<int> st;
    if (!st.empty() && st.top() == 1)
        cout << st.top() << endl;
    
    // 2d array
    // [ ] [ ] [ ] ... [ ]
    //  |   |
    // [ ] [ ]
    // arr -> 5 * 20
    int** a2d = new int*[5];
    for (int i=0; i<5; ++i) {
        a2d[i] = new int[20];
    }
    
    cout << a2d[3][11] << '\n';
    
    // delete: delete both the a2d pointer and a2d
    for (int i=0; i<5; ++i) {
        delete[] a2d[i];
    }
    delete[] a2d;
    
    return 0;
}
