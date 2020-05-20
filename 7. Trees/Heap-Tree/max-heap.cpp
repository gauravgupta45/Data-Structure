#include <iostream>
#include <cmath>
using namespace std;

const int mxN = 2e5;

// insert() will take O(NlogN) time to build a heap of N Nodes. It is a Bottom-Top approch.
// heapify() on other hand is much more efficient. It takes only O(N) time. It is a Top-Bottom approach.

void insert(int *arr, int &n, int val)
{
    n = n+1;
    arr[n-1] = val;

    // Let's mark our current position, we are on last node, where val is present.
    int pos = n-1;
    while(pos>=1)
    {
        int par = floor((pos-1)/2);
        if(arr[par]<=arr[pos])
        {
            int temp = arr[par];
            arr[par] = arr[pos];
            arr[pos] = temp;
            pos = par;
        }
        else
            return;
    }
}

void heapify(int *arr, int n, int i)
{
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;

  if (l < n && arr[l] > arr[largest])
    largest = l;
  if (r < n && arr[r] > arr[largest])
    largest = r;
  if (largest != i)
  {
    int temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;
    heapify(arr, n, largest);
  }
}

void del(int *arr, int &n)
{
    int last = arr[n-1];
    n = n-1;
    int ptr = 0, left = 1, right = 2;
    arr[ptr] = last;
    while(left <=  n)
    {
        if(arr[ptr] >= arr[left] && arr[ptr] >= arr[right])
            return;
        if(arr[left] > arr[right])
        {
            int temp = arr[ptr];
            arr[ptr] = arr[left];
            arr[left] = temp;
            ptr = left;
        }
        else
        {
            int temp = arr[ptr];
            arr[ptr] = arr[right];
            arr[right] = temp;
            ptr = right;
        }
        left = 2*ptr+1;
        right = 2*ptr+2;
    }

}

void display(int *arr, int n)
{
    cout<<endl<<"Heap Tree is: ";
    for(int i = 0; i < n; i++)
        cout << arr[i]<<"\t";
    cout << endl;
}


int main()
{
    cout<<endl<<"-----------------------Heap Tree-------------------------"<<endl;

    int n, arr[mxN];
    cout << "Enter Array Size: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = n/2-1; i >= 0; i--)
        heapify(arr,n,i);
    cout <<endl << "Heap Built with O(N) time complexity! [Heapify Method]"  << endl;
    display(arr,n);

    int ins_val, ch=-1;;
    while(ch!=4)
    {
        cout<<endl<<"1. Insert"<<endl<<"2. Delete Root Node"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cout<<endl<<"Enter Your Choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<endl<<"Enter Value to be inserted in the Heap: ";
                cin>>ins_val;
                insert(arr,n,ins_val);
                cout << endl << "Value inserted with O(logN) time complexity! [Insertion Method]"  << endl;
                display(arr,n);
                break;

            case 2:
                del(arr,n);
                cout << endl << "Root Value has been deleted!" << endl;
                display(arr,n);
                break;
            case 3:
                display(arr,n);
                break;
        }
    }
    return 0;
}
