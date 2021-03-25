//
//  main.cpp
//  static_array
//
//  Created by Yue Zhang on 25/3/21.
//

#include <iostream>
#include <array>
#include <vector>
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
    return 0;
}
