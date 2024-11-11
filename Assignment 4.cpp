//SAMARTH PATIL
//23574
//DSAL
//ASSIGNMENT 4
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

struct node       //Used to create nodes as tree
{
    char data;     //accepts value for node
    node *leftchild;   //left child stored
    node *rightchild;  //right child stored
} * root;

node *store_root_address;

node *construct_prefix_tree(char prefix[]);
node *construct_postfix_tree(char posfix[]);
void recursive_nonrecursive_choice();
void expression_choice();

void recursive_inorder(node *root);
void recursive_preorder(node *root);
void recursive_postorder(node *root);

void nonrecursive_inorder(node *root);
void nonrecursive_preorder(node *root);
void nonrecursive_postorder(node *root);

bool isOperator(char c)      //Defining Operators
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }

    return false;
}

node *newNode(char v)
{
    node *temp = new node;        // creating node 
    temp->leftchild = NULL;      // the left child is created for node
    temp->rightchild = NULL;    // the right child is created for node
    temp->data = v;            // value is assigned to the node
    return temp;
};

node *construct_postfix_tree(char postfix[])    // For Construction of Postfix Tree 
{
    stack<node *> s; // a stack is created 
    node *root, *t1, *t2; // 3 nodes are made 

    for (int i = 0; i < strlen(postfix); i++) // the infix string accepted from user is iterated in this loop
    {
        if (!isOperator(postfix[i])) // if the infix expression has operator 
        {
            root = newNode(postfix[i]); // root is assigned the operator
            s.push(root); // and then the operator is pushed in the stack
        }

        else
        {
            root = newNode(postfix[i]); // root node is assigned character

            t1 = s.top(); // we assign temp node 1 the top value from stack
            s.pop(); // then pop the value from stack
            t2 = s.top(); // we assign temp node 2 the top value from stack
            s.pop(); // then pop the value from stack

            // make these two nodes as the child of the parent node that contains operator
            root->rightchild = t1;
            root->leftchild = t2;

            s.push(root); // push the root in stack
        }
    }

    root = s.top(); // now assign root as
    s.pop();

    return root;
}

node *construct_prefix_tree(char prefix[])  //For Construction of Prefix tree
{
    stack<node *> s; // a stack is created 
    node *root, *t1, *t2; // 3 nodes are made 

    for (int i = 0; i < strlen(prefix); i++) // the infix string accepted from user is iterated in this loop
    {
        if (!isOperator(prefix[i])) // if the infix expression has operator 
        {
            root = newNode(prefix[i]); // root is assigned the operator
            s.push(root); // and then the operator is pushed in the stack
        }

        else
        {
            root = newNode(prefix[i]); // root node is assigned character

            t1 = s.top(); // we assign temp node 1 the top value from stack
            s.pop(); // then pop the value from stack
            t2 = s.top(); // we assign temp node 2 the top value from stack
            s.pop(); // then pop the value from stack

            // make these two nodes as the child of the parent node that contains operator

            root->leftchild = t1;
            root->rightchild = t2;

            s.push(root); // push the root in stack
        }
    }

    root = s.top();
    s.pop();

    return root;
}

void recursive_inorder(node *root)            //For recursive Inorder
{
    node *temp;
    temp = root;
    if (temp != NULL)
    {
        recursive_inorder(temp->leftchild); // we traverse the left subtree
        cout << " " << temp->data; // print data
        recursive_inorder(temp->rightchild); // we traverse the right subtree
    }
}

void recursive_preorder(node *root)           //For recursive Preorder
{
    node *temp;
    temp = root;
    if (temp != NULL)
    {
        cout << " " << temp->data; // print data
        recursive_preorder(temp->leftchild); // we traverse the left subtree
        recursive_preorder(temp->rightchild);  // we traverse the right subtree
    }
}

void recursive_postorder(node *root)         //For recursive Postorder
{
    node *temp;
    temp = root;
    if (temp != NULL)
    {
        recursive_postorder(temp->leftchild); // we traverse the left subtree
        recursive_postorder(temp->rightchild); // we traverse the right subtree
        cout << " " << temp->data; // print data
    }
}

void nonrecursive_inorder(node *root)            //For Nonrecursive Inorder
{

    stack<node *> s; // stack declared

    node *current_node = root; // root node stored into current_node

    while (current_node != NULL || s.empty() == false) // we check whether current node is null or not and whether stack is empty or not

    {

        while (current_node != NULL) //if current node is not null 

        {
            s.push(current_node); // push current node into stack

            current_node = current_node->leftchild; // now we make the left child as current node
        }

        current_node = s.top(); // now the element on top in stack is amde current node

        s.pop(); // pop element
        cout << current_node->data; // print data

        current_node = current_node->rightchild;  // now we make the right child as current node
    }
}

void nonrecursive_preorder(node *root)          //For Nonrecursive Preorder
{
    stack<node *> s; // stack declared
    s.push(root); // push root in stack
    if (root == NULL) // if root is null come out of the function
    {
        return;
    }

    while (s.empty() == false) // if stack is not empty
    {
        node *temp = s.top(); // assign temporary node with the value that is on top in stack
        s.pop(); // we pop element
        cout << " " << temp->data; // print data 

        if (temp->rightchild)
        {
            s.push(temp->rightchild);  // push right child in stack
        }

        if (temp->leftchild)
        {

            s.push(temp->leftchild); // push left child in stack
        }
    }
}

void nonrecursive_postorder(node *root)         //For Nonrecursive Postorder
{
    if (root == NULL) // if root is null come out of the function
    {
        return;
    }

    stack<node *> s1; // stack1 created
    stack<node *> s2; // stack2 created
    s1.push(root); // push root in stack1
    node *temp;

    while (s1.empty() == false) // if stack1 is not empty
    {
        temp = s1.top(); // put top element from stack in temp node
        s1.pop(); // pop element from stack1
        s2.push(temp); // push the temp node value in stack2

        if (temp->leftchild)
        {
            s1.push(temp->leftchild); // push left child in stack1
        }

        if (temp->rightchild)
        {
            s1.push(temp->rightchild); // push right child in stack1
        }
    }

    while (!s2.empty()) // if stack 2 is not empty
    {
        temp = s2.top(); // temporary node is assigned top value of stack2
        s2.pop(); // pop element from stack 2
        cout << " " << temp->data; // print data
    }
}

int main()
{
    int k = 0;
    int choice, choice_R, choice_NR;
    node *root_address;
    char reverse[100], prefix[100], postfix[100];

    node *construct_prefix_tree(char prefix[]);
    node *construct_postfix_tree(char posfix[]);
    void recursive_non_recursive_choice();
    void expression_choice();

    void recursive_inorder(node * root);
    void recursive_preorder(node * root);
    void recursive_postorder(node * root);

    void nonrecursive_inorder(node * root);
    void nonrecursive_preorder(node * root);
    void nonrecursive_postorder(node * root);

    do
    {
        cout << "\n";
        cout << "\n From which expression you want to construct binary expression tree?\n";
        cout << "\n 1) Prefix Expression. \n 2) Postfix Expression. \n 3) Exit.";
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            //ACCEPTING PREFIX EXPRESSION
            cout << "\nEnter Prefix Expression: ";
            cin >> prefix;

            for (int j = strlen(prefix) - 1; j >= 0; j--)
                reverse[k++] = prefix[j];
            reverse[k] = '\0';
            //cout<<reverse;
            root_address = construct_prefix_tree(reverse);

            cout << "\nIn which manner you want to traverse the binary expression tree?"<<endl;
            cout << "1) Recursively. \n2) Non-Recursively. \n3) Exit."<<endl;
            cout << "Enter Your Choice:  ";
            cin >> choice_R;
            switch (choice_R)
            {
            case 1:
                //RECURSIVE FUNCTIONS ON PREFIX
                cout << "\nRecursive preorder is: ";
                recursive_preorder(root_address);

                cout << "\nRecursive inorder is: ";
                recursive_inorder(root_address);

                cout << "\nRecursive postorder is: ";
                recursive_postorder(root_address);

                break;

            case 2:
                //NON RECURSIVE FUNCTIONS ON PREFIX

                cout << "\n\nNon-Recursive preorder is: ";
                nonrecursive_preorder(root_address);

                cout << "\nNon-Recursive inorder is: ";
                nonrecursive_inorder(root_address);

                cout << "\nNon-Recursive postorder is: ";
                nonrecursive_postorder(root_address);
                break;

            case 3:
                cout << "You Have Successfully Exitted.....";
                break;

            default:
                cout << "INVALID CHOICE.....";
            }
            break;

        case 2:
            cout << "\nEnter Postfix Expression: ";
            cin >> postfix;
            root_address = construct_postfix_tree(postfix);
            cout << "\nIn which manner you want to traverse the binary expression tree?" << endl;
            cout << "1) Recursively. \n2) Non-Recursively. \n3) Exit.";
            cout << "\nEnter Your Choice:  ";
            cin >> choice_R;
            switch (choice_R)
            {
            case 1:
                //RECURSIVE FUNCTIONS ON PREFIX
                cout << "\nRecursive preorder is: ";
                recursive_preorder(root_address);

                cout << "\nRecursive inorder is: ";
                recursive_inorder(root_address);

                cout << "\nRecursive postorder is: ";
                recursive_postorder(root_address);

                break;

            case 2:
                //NON RECURSIVE FUNCTIONS ON PREFIX

                cout << "\n\nNon-Recursive preorder is: ";
                nonrecursive_preorder(root_address);

                cout << "\nNon-Recursive inorder is: ";
                nonrecursive_inorder(root_address);

                cout << "\nNon-Recursive postorder is: ";
                nonrecursive_postorder(root_address);
                break;

            case 3:
                cout << "You Have Successfully Exitted.....";
                break;

            default:
                cout << "INVALID CHOICE.....";
            }
        }
    } while (choice != 3);
    return 0;
}
