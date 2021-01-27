//
//  main.cpp
//  minheap
//
//  Created by Yue Zhang on 27/1/21.
//

#include <iostream>
#include <vector>
using namespace std;

int A[10000];
int size = 0;

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return 2*i+1;
}

int right(int i) {
    return 2*i+2;
}

int get_min() {
    // O(1)
    return A[0];
}

// heapify a subtree from index i
void heapify(int i) {
    // O(logn)
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && A[l] < A[smallest]) {
        smallest = l;
    }
    if (r < size && A[r] < A[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(A[i], A[smallest]);
    }
}

int extract_min() {
    if (size <= 1) return INT_MAX;
    if (size == 1) {
        size--;
        return A[0];
    }
    
    int value = A[0];
    A[0] = A[size-1];
    heapify(0);
    size--;
    return value;
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void decrease_key(int i, int new_value) {
    // O(logn)
    A[i] = new_value;
    while (parent(i) >= 0 && A[parent(i)] > A[i]) {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

void insert_key(int value) {
    // O(logn)
    A[size] = value;
    size++;
    int i = size - 1;
    while (parent(i) >= 0 && A[parent(i)] > A[i]) {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

void delete_key(int i) {
    decrease_key(i, INT_MIN);
    extract_min();
}

int main() {
    // insert code here...
    insert_key(3);
    insert_key(2);
    delete_key(1);
    insert_key(15);
    insert_key(5);
    insert_key(4);
    insert_key(45);
    cout << extract_min() << " ";
    cout << get_min() << " ";
    decrease_key(2, 1);
    cout << get_min() << " ";
    return 0;
}
