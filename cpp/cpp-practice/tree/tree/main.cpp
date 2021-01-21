//
//  main.cpp
//  tree
//
//  Created by Yue Zhang on 20/1/21.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};


int main() {
    Node *tree = new Node(3);
    // tree->left = new Node(2);
    (*tree).left = new Node(4);
    tree->right = new Node(5);
    // following is the same
    cout << (*tree).data << endl;
    cout << tree->data << endl;
    cout << tree->left->data << endl;
    cout << tree->right->data << endl;

    long long int s = 4999949998;
    cout << s << endl;
    return 0;
}
