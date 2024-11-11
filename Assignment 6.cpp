//SAMARTH PATIL
//Roll no:23574
//batch:S4
//DSAL
// Assignment 6
// Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order.
#include<bits/stdc++.h>  // header
using namespace std; 
  
struct Node 
{ 
    struct Node *left, *right; 
    int data; 
    
    bool thread_left; // to check whether the node is internal or leaf
 
    bool thread_right; // to check whether the node is internal or leaf
}; 
  

Node *insert(struct Node *root, int data_to_insert) 
{ 
    
    Node *temp = root; // creating temporary node to store root
    Node *parent = NULL; // to find parent node
    while (temp != NULL) // to find suitable place for inserting node (find parent)
    { 
        
        if (data_to_insert == (temp->data))  // check whether key is duplicate or not
        { 
           cout<<"Duplicate Key !\n";
 
            return root; 
        } 
  
        parent = temp; // Update parent  pointer 
  
        // Moving on left subtree. 
        if (data_to_insert < temp->data)  // to add data in left subtree
        { 
            if (temp -> thread_left == false) // if parent node then we add the child node
                temp = temp -> left; 
            else
                break; 
        } 
  
        // Moving on right subtree. 
        else
        { 
            if (temp->thread_right == false) 
                temp = temp -> right; 
            else
                break; 
        } 
    } 
  
    // Create a new node 
    // to add the child node after finding the parent node
    Node *new_node = new Node; 
    new_node -> data = data_to_insert; 
    new_node -> thread_left = true; 
    new_node -> thread_right = true; 
  
    if (parent == NULL) 
    { 
        root = new_node; 
        new_node -> left = NULL; 
        new_node -> right = NULL; 
    } 
    else if (data_to_insert < (parent -> data)) 
    { // inserting element to left side 
        new_node -> left = parent -> left;    // 90    Data to insert 55
        new_node -> right = parent;  //    80         100 
        parent -> thread_left = false;// 60    85            120
        parent -> left = new_node; // 55
    } 
    else
    { // inserting element to right side                // 90    Data to insert 87
        new_node -> left = parent;        //        80         100 
        new_node -> right = parent -> right; // 60    85            120
        parent -> thread_right = false;   //              87   
        parent -> right = new_node; 
    } 
  
    return root; 
} 
 void preorder(struct Node *root )  
{  
        struct Node *ptr;  // temporary node named ptr
        if(root==NULL)  
        {  
                cout << "Tree is empty" << endl;  
                return;  
        }  
        ptr=root;  
        while(ptr!=NULL)  
        {  
                cout<<ptr->data<<" ";  // data printed 1st as preorder
                if(ptr->thread_left==false)  // condition for parent left
                        ptr=ptr->left;  
                else if(ptr->thread_right==false)  // condition for parent right 
                        ptr=ptr->right;  
                else  // condition for leaf node
                {  
                        while(ptr!=NULL && ptr->thread_right==true)  
                                ptr=ptr->right;  
                        if(ptr!=NULL)  
                                ptr=ptr->right;  
                }  
        }  
}   
struct Node *inorderSuccessor(struct Node *temp) 
{  // to print inorder traversal 
    
    if (temp -> thread_right == true) // If right subtree of node is not NULL, then succ lies in right subtree.
        return temp->right; // Go to right subtree and return the node with minimum key value in the right subtree.
  
   
    temp = temp -> right; // If right subtree of node is NULL, then succ is one of the ancestors.
    while (temp -> thread_left == false)  
        //Travel up using the parent pointer until you see a node which is left child of its parent. The parent of such a node is the succ.
        temp = temp -> left; 
    return temp; 
} 
 
void inorder(struct Node *root) 
{ // inorder means prints in ascending order
    if (root == NULL) 
        cout<<"Tree is empty"; 
  
    // Reach leftmost node 
    Node *temp = root; // temporary variable 
    while (temp -> thread_left == false)  // 90
        temp = temp -> left;//       70          100 
    //                           60      80
    // One by one print successors 
    while (temp != NULL) 
    { 
        cout<<temp -> data<<" ";  
        temp = inorderSuccessor(temp); 
    } 
} 
  

int main() 
{ 
    Node *root = NULL; int ch,n,size;
    
    
    do{
       cout<<"\n1. Insert";
    cout<<"\n2. Display Inorder Threaded binary tree";
    cout<<"\n3. Display Preorder Threaded binary tree ";
    cout<<"\n4. Exit\nEnter Choice :";
    cin>>ch;
   switch(ch){
      case 1:cout<<"How many nodes you want to enter :";
      cin>>size;
      for(int i=1;i<=size;i++){
         cout<<"#"<<i<<" Insert node value  : ";
                cin>>n;
                root=insert(root,n);
                }
             break;
     case 2:
     cout<<"Inorder binary threaded tree: ";
     inorder(root);   ;
     cout<<endl;
             break;
       case 3:
     cout<<"Preorder binary threaded tree: ";
     preorder(root);   ;
     cout<<endl;
             break;
   }}while(ch!=4);
  
    return 0; 
} 





