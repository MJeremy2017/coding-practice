//
//  main.cpp
//  array
//
//  Created by Yue Zhang on 22/2/21.
//

#include <iostream>
#include <array>
using namespace std;

int main() {
    // insert code here...
    
    int arr[5];
    arr[0] = 1;
    arr[2] = 3;  // move the start pointer 2 bytes and set the value to 3
    
    int* arr_heap = new int[5];
    arr_heap[0] = 2;
    
    int* ptr;
    
    cout << sizeof(arr_heap) << endl;  // pointer to the array stored on heap which is 8 bytes on this specific machine
    cout << sizeof(ptr) << endl;  // an int pointer 9 bytes
    cout << sizeof(arr) << endl;  // the size of the array with 5 elements 20 bytes
    cout << sizeof(int) << endl;  // size of int 4 bytes
    
    delete[] arr_heap;
    
    array<int, 5> builtin_arr;
    for (int i=0; i<builtin_arr.size(); ++i) {
        builtin_arr[i] = 3;
    }

    return 0;
}
