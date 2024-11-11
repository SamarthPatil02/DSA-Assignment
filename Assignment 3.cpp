/*ASSIGNMENT 3:
Name:SAMARTH PATIL
Roll No. 23574
Sub :Data Structures and algorithms
*/
#include <iostream>
using namespace std;
#define MAXSIZE 5
int rear = -1, front = -1, queue[MAXSIZE];

void insert() {
    int x;
    if ((rear + 1) % MAXSIZE == front) {
        cout << "Queue is full" << endl;
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    
    rear = (rear + 1) % MAXSIZE;
    cout << "Enter a number to insert: ";
    cin >> x;
    queue[rear] = x;
    cout << x << " is added at position: " << rear << endl;
}

void Delete() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    int ele = queue[front];
    cout << ele << " is deleted from position: " << front << endl;
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAXSIZE;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    int i = front;
    while (true) {
        cout << queue[i] << endl;
        if (i == rear) break;
        i = (i + 1) % MAXSIZE;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Enter what you want: \n1. INSERT \n2. DELETE \n3. DISPLAY \n4. EXIT" << endl;
        cout << ": ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Enter a valid choice" << endl;
        }
    }
}
