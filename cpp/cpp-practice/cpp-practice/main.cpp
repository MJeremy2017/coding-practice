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


void merge(vector<int>& arr, int left, int mid, int right) {
    int size_a = mid - left + 1;
    int size_b = right - mid;
    int a[size_a];
    int b[size_b];
    
    for (int i=left; i<=mid; ++i) {
        a[i-left] = arr[i];
    }
    
    for (int i=mid+1; i<=right; ++i) {
        b[i-mid-1] = arr[i];
    }
    
    int i = 0;
    int j = 0;
    int k = left;
    while (i<size_a && j<size_b) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    
    while (i < size_a) {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < size_b) {
        arr[k] = b[j];
        j++;
        k++;
    }
}


void merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right)/2;
    
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
    
}

int main() {
    vector<int> arr = {-1, 3, 3, 2, 2, 1, 1, 1, 5};
    countArr(arr);
    cout << endl;
    
    int size = int(arr.size());
    merge_sort(arr, 0, size-1);
    for (int i=0; i<arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
