//
//  main.cpp
//  cpp-practice
//
//  Created by Yue Zhang on 5/1/21.
//

#include <iostream>
#include <vector>
using namespace std;


void countArr(vector<int>& arr) {
    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<int> counts(range), output(arr.size());
    
    for (int i=0; i<arr.size(); ++i) {
        ++counts[arr[i] - min];
    }

    // count sort
    int k = 0;
    for (int i=0; i<counts.size(); ++i) {
        if (counts[i] > 0) {
            for (int j=0; j<counts[i]; ++j) {
                output[k] = i+min;
                ++k;
            }
        }
    }
    
    // print arr
    for (int i=0; i<output.size(); ++i) {
        std::cout << output[i] << " ";
    }
}


int main() {
    vector<int> arr = {-1, 3, 3, 2, 2, 1, 1, 1, 5};
    countArr(arr);
    return 0;
}
