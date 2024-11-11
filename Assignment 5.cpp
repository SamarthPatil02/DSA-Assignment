/*ASSIGNMENT 5:
Name:SAMARTH PATIL
Roll No. 23574
Sub :Data Structures and algorithms
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *right;
    Node *left;

    // Constructor to initialize a new node
    Node(int data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

class BinaryTree {
private:
    Node* root;

    // Recursive function to insert a new node with the given data
    Node* insert(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    // Recursive function to perform in-order traversal and print node values
    void shift(Node* node) {
        if (node != NULL) {
            shift(node->left);
            cout << node->data << " ";
            shift(node->right);
        }
    }

    // Function to find the minimum value node in the right subtree
    Node* findMin(Node* node) {
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Recursive function to delete a node with the given data
    Node* del(Node* node, int data) {
        if (node == NULL) {
            return NULL;
        }
        if (data < node->data) {
            node->left = del(node->left, data);
        } else if (data > node->data) {
            node->right = del(node->right, data);
        } else {
            // Node with the data is found
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = del(node->right, temp->data);
        }
        return node;
    }

public:
    // Constructor to initialize an empty binary tree
    BinaryTree() {
        this->root = NULL;
    }

    // Public method to insert a new node with the given data
    void insert(int data) {
        root = insert(root, data);
    }

    // Public method to display the tree elements in sorted order
    void display() {
        shift(root);
        cout << endl;
    }

    // Public method to delete a node with the given data
    void Delete(int data) {
        root = del(root, data);
    }
};

int main() {
    BinaryTree tree;
    int choice;

    while (true) {
        cout << "ENTER WHAT YOU WANT : \n1. INSERT \n2. DELETE \n3. DISPLAY \n4. EXIT" << endl;
        cout << ": ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
        } else if (choice == 2) {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            tree.Delete(value);
        } else if (choice == 3) {
            tree.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Enter a valid choice" << endl;
        }
    }

    return 0;
}
