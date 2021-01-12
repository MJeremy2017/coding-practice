//
//  main.cpp
//  sort
//
//  Created by Yue Zhang on 11/1/21.
//

#include <iostream>
#include <vector>
using namespace std;

void printArray(int a[], int size) {
    for (int i=0; i<size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> bubbleSort(vector<int> arr) {
    for (int i=0; i<arr.size(); ++i) {
        for (int j=i+1; j<arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

void merge1(int ar[], int left, int mid, int right) {
    // both a and b are sorted vectors
    int size_a = mid-left+1;
    int size_b = right-mid;
    int a[size_a], b[size_b];
    
    for (int i=left; i<=mid; ++i) {
        a[i-left] = ar[i];
    }
    
    for (int j=mid+1; j<=right; ++j) {
        b[j-mid-1] = ar[j];
    }
        
    int i = 0;
    int j = 0;
    int k = left;
    while (i < size_a && j < size_b) {
        if (a[i] < b[j]) {
            ar[k] = a[i];
            i++;
        } else {
            ar[k] = b[j];
            j++;
        }
        k++;
    }
    
    while (i < size_a) {
        ar[k] = a[i];
        i++;
        k++;
    }
    while (j < size_b) {
        ar[k] = b[j];
        j++;
        k++;
    }
    
}


void mergeSort1(int a[], int left, int right) {
    int mid = (left + right)/2;
    if (left >= right) {
        return;
    }
    mergeSort1(a, left, mid);
    mergeSort1(a, mid+1, right);
    merge1(a, left, mid, right);
    
}

int partition1(int a[], int left, int right) {
    int index = left;
    int pivot = a[right];
    for (int i=left; i<right; ++i) {
        if (a[i] < pivot) {
            swap(a[i], a[index]);
            index++;
        }
    }
    swap(a[right], a[index]);
    return index;
}

void quickSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int index = partition1(a, left, right);
    quickSort(a, left, index-1);
    quickSort(a, index+1, right);
}


void printVector(vector<int> a) {
    for (int i=0; i<a.size(); ++i) {
        cout << a[i] << " ";
    }
}

void countSort(int ar[], int exp, int size) {
    int output[size];
    int count[10] = {0};
    
    for (int i=0; i<size; ++i) {
        count[(ar[i]/exp)%10]++;
    }
    
    for (int i=1; i<10; ++i) {
        count[i] += count[i-1];
    }
    
    for (int i=size-1; i>=0; --i) {
        int index = (ar[i]/exp)%10;
        output[count[index] - 1] = ar[i];
        count[index]--;
    }
        
    for (int i=0; i<size; ++i) {
        ar[i] = output[i];
    }
    cout << endl;
}

void radixSort(int ar[], int size) {
    int m = ar[0];
    for (int i=1; i<size; ++i) {
        if (ar[i] > m) m = ar[i];
    }
    
    int exp = 1;
    while (m / exp > 0) {
        countSort(ar, exp, size);
        exp *= 10;
    }
}

int main() {
    // insert code here...
    vector<int> a;
    a = {3, 8, 12, 2, 3, 9, 11};

    a = bubbleSort(a);

    printVector(a);
    cout << endl;

    int ar[] = {3, 8, 12, 2, 11, 2};
    radixSort(ar, 6);
    
    mergeSort1(ar, 0, 5);
    quickSort(ar, 0, 5);
    printArray(ar, 6);
    
    
    return 0;
}
