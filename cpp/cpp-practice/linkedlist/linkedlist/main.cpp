//
//  main.cpp
//  linkedlist
//
//  Created by Yue Zhang on 9/1/21.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next; // pointer to next node
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    // O(1)
    void insert_end(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    void insert_start(int data) {
        if (isEmpty()) insert_end(data);
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }
    
    // O(n)
    void insert_position(int pos, int data) {
        if (pos == 0) insert_start(data);

        Node* node = head;
        while (pos > 1) {
            node = node->next;
            pos--;
        }
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = node->next;
        node->next = new_node;
    }
    
    void delete_first() {
        if (isEmpty()) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    
    // O(n)
    void delete_last() {
        if (isEmpty()) return;
        Node* node = head;
        Node* prev = new Node;
        while (node->next) {
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
        tail = prev;
        delete node;
    }
    
    // O(n)
    void delete_position(int pos) {
        if (isEmpty()) return;
        if (pos == 0) delete_first();
        
        Node* node = head;
        while (pos > 1) {
            node = node->next;
            pos--;
        }
        node->next = node->next->next;
    }
    
    bool isEmpty() {
        if (head) {
            return false;
        }
        return true;
    }
    
    void printList() {
        if (isEmpty()) return;
        Node* node = head;
        while (node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
    
    void reverse() {
        Node* node = head;
        Node* prev = NULL;
        Node* tmp;
        while (node) {
            head = node;
            tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
    }
};


// malloc allocates memory, while new allocates memory AND calls the constructor of the object you're allocating memory for.
int main() {
    // insert code here...
    LinkedList a;
    a.insert_end(3);
    a.insert_start(1);
    a.insert_end(4);
    a.insert_start(5);
    a.insert_position(1, 20);
    a.delete_first();
    a.delete_last();
    a.delete_position(1);
    a.insert_start(3);
    a.insert_start(31);
    a.reverse();
    a.printList();
    
    return 0;
}
