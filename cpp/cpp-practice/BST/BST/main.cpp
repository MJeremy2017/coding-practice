//
//  main.cpp
//  BST
//
//  Created by Yue Zhang on 6/2/21.
//

#include <iostream>
using namespace std;

class BST {
public:
    int data;
    BST* left;
    BST* right;

    BST();
    BST(int);
};

// member initialization in constructors
BST::BST(): data(0), left(NULL), right(NULL) {}

BST::BST(int value) {
    this->data = value;
    left = NULL;
    right = NULL;
}

BST* insert(BST* root, int value) {
    if (!root) {
        return new BST(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

void Inorder(BST* root) {
    if (!root) {
        return;
    }
    
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

BST* find_node(BST* root, int value) {
    if (!root) return NULL;
    if (root->data == value) return root;
    
    if (value < root->data) {
        return find_node(root->left, value);
    } else {
        return find_node(root->right, value);
    }
}

BST* get_min_node(BST* root) {
    if (!root) return NULL;
    while (root->left) {
        root = root->left;
    }
    return root;
}

BST* delete_node(BST* root, int value) {
     if (value < root->data) {
         root->left = delete_node(root->left, value);
     } else if (value > root->data) {
         root->right = delete_node(root->right, value);
     } else {
         if (root->left == NULL) {
             return root->right;
         } else if (root->right == NULL) {
             return root->left;
         } else {
             BST* min_node = get_min_node(root->right);
             root->data = min_node->data;
             root->right = delete_node(root->right, min_node->data);
         }
         
     }
    return root;
}

int main() {
    // insert code here...
    BST* root = new BST(10);
    root = insert(root, 5);
    root = insert(root, 19);
    root = insert(root, 13);
    root = insert(root, 2);
    root = insert(root, 20);
    
    root = delete_node(root, 19);
    Inorder(root);
    
    return 0;
}


