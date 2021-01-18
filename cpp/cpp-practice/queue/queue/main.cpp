//
//  main.cpp
//  queue
//
//  Created by Yue Zhang on 7/1/21.
//

#include <iostream>
#include <vector>
using namespace std;

int Queue[100];
int frontInd = 0;
int backInd = 0;

bool isEmpty() {
    if (frontInd == backInd) {
        cout << "queue is empty" << endl;
        return true;
    } else {
        cout << "queue is not empty" << endl;
        return false;
    }
}

void push(int value) {
    Queue[backInd] = value;
    backInd++;
}

void pop() {
    // pop value from the front
    if (!isEmpty()) {
        Queue[frontInd] = 0;
        frontInd++;
    }
}

int front() {
    return Queue[frontInd];
}

void printQueue() {
    for (int i=frontInd; i<backInd; i++) {
        cout << Queue[i] << endl;
    }
}

int main() {
    push(12);
    push(10);
    push(1);
    printQueue();
    pop();
    printQueue();
    isEmpty();
    pop();
    pop();
    isEmpty();
    
    
    cout << int(sqrt(12));
    return 0;
}





