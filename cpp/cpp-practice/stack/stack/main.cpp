//
//  main.cpp
//  stack
//
//  Created by Yue Zhang on 6/1/21.
//

#include <iostream>
#include <vector>
using namespace std;

int Stack[100], ind;
char input[100];

void push(int value) {
    ++ind;
    Stack[ind] = value;
}

bool isEmpty() {
    if (ind > 0) {
        return false;
    } else {
        return true;
    }
}

void pop() {
    Stack[ind] = 0;
    --ind;
}

int top() {
    if (!isEmpty()) {
        return Stack[ind];
    } else {
        return 0;
    }
}

void printStack() {
    for (int i=1; i<=ind; ++i) {
        cout << Stack[i] << endl;
    }
}

bool verifty(char input[]) {
    int n = int(strlen(input));
    for (int i=0; i<n; ++i) {
        if (input[i] == '(') push(1);
        if (input[i] == '[') push(2);
        if (input[i] == '{') push(3);
        
        if (input[i] == ')') {
            if (isEmpty() || top() != 1) return false;
            else pop();
        }
        if (input[i] == ']') {
            if (isEmpty() || top() != 2) return false;
            else pop();
        }
        if (input[i] == '}') {
            if (isEmpty() || top() != 3) return false;
            else pop();
        }
    }
    return true;
}

int main() {
    cin >> input;
    bool ans = verifty(input);
    cout << ans << endl;
    return 0;
}
