//SAMARTH PATIL
//Roll no:23574
//batch:S4
//DSAL
//..................................................................................................
// Assignment 9
/*Implement Heap sort to sort given set of values using max or min heap.*/
//..................................................................................................
#include <iostream>                                 // header
using namespace std;

void Maxheapify(int Arr[], int n, int i)            // function to heapify the tree
{
    int largest = i;                               // i is the largest element (i = root)
    int l = 2 * i + 1;                             // left = 2*i + 1
    int r = 2 * i + 2;                             // right = 2*i + 2
  
    if (l < n && Arr[l] > Arr[largest])            // if left child is larger than root
    {
        largest = l;
    }

    if (r < n && Arr[r] > Arr[largest])            // if right child is larger than largest so far 
    {
        largest = r;
    }

    if (largest != i)                               // if largest is not root
    {
        swap(Arr[i], Arr[largest]);                // swap root and largest
        Maxheapify(Arr, n, largest);               // recursively heapify the subtree
    }
}


void Maxheapsort(int Arr[], int n)                 // implementing heap sort
{
    for (int i = n / 2 - 1; i >= 0; i--)           // build heap
    {
        Maxheapify(Arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)                // extracting elements from heap one by one 
    {
        swap(Arr[0], Arr[i]);                     // move current root to end
        Maxheapify(Arr, i, 0);                  // again call max heapify on the reduced heap
    }
}


void Display(int Arr[], int n)                // passing argument as array and integer
{
    for (int i = 0; i < n; ++i)               // traversing array using for loop 
    {
        cout << Arr[i] << " ";                // printing elements
    }

    cout << "\n";
}
 
 
int main()                                        // main program
{
    int n,Arr[n]; 
    cout<<"How many elements you want to sort?:  ";
    cin>>n;
    cout<<"Enter "<<n<<" Elements: \n";
    for(int i=0; i<n; i++)
    {
        cin>>Arr[i];
    }
    
    Maxheapsort(Arr, n);                             // calling maxheapsort funtion 
 
    cout << "\nSorted array is: \n";
    Display(Arr, n);                                 // calling display function
    
    return 0;
}

