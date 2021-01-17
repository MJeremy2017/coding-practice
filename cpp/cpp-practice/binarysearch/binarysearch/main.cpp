//
//  main.cpp
//  binarysearch
//
//  Created by Yue Zhang on 10/1/21.
//

#include <iostream>
using namespace std;

int A[9] = {2, 5, 5, 6, 9, 19, 26, 45, 69};

int binarySearch(int value) {
    int left = 0; int right = 8;
    while (left <= right) {
        int mid = (left + right)/2;
        if (value < A[mid]) {
            right = mid - 1;
        } else if (value > A[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int fisrtIndex(int value, int left, int right) {
    int ind = -1, mid;
    while (left <= right) {
        mid = (left + right)/2;
        if (value > A[mid]) {
            left = mid + 1;
        } else if (value < A[mid]) {
            right = mid - 1;
        } else {
            ind = mid;
            right = mid - 1;
        }
    }
    
    return ind;
}

double sqrt(double value) {
    if (value < 0) return -1;
    if (value == 0) return 0;
    
    double mid;
    if (value >= 1) {
        double left = 1, right = value;
        mid = (left + right)/2.0;
        while (abs(mid * mid - value) > 0.01) {
            if (mid * mid > value) {
                right = mid;
            } else if (mid * mid < value) {
                left = mid;
            } else {
                return mid;
            }
        }
    } else {
        mid = 1/sqrt(1/value);
    }
    return mid;
}

int lastIndex(int value, int left, int right) {
    int ind = -1, mid;
    while (left <= right) {
        mid = (left + right)/2;
        if (value > A[mid]) {
            left = mid + 1;
        } else if (value < A[mid]) {
            right = mid - 1;
        } else {
            ind = mid;
            left = mid + 1;
        }
    }
    
    return ind;
}


int main() {
    // insert code here...
    int ind;
    ind = binarySearch(6);
    cout << "6 is in the position: " << ind << endl;

    ind = binarySearch(5);
    cout << "5 is in the position: " << ind << endl;

    ind = binarySearch(19);
    cout << "19 is in the position: " << ind << endl;

    ind = fisrtIndex(12, 0, 8);
    cout << "first index of 5 is in the position: " << ind << endl;

    ind = lastIndex(5, 0, 8);
    cout << "last index of 5 is in the position: " << ind << endl;
    
    double sq;
    sq = sqrt(0.2);
    cout << sq << endl;
    return 0;
}
