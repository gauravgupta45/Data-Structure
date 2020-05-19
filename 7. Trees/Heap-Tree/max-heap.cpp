#include <iostream>
#include <cmath>
using namespace std;

void insert(int *arr, int &n, int val)
{
    n = n+1;
    arr[n] = val;

    // Let's mark our current position, we are on last node, where val is present.
    int pos = n;
    while(pos>1)
    {
        int par = floor(pos/2);
        if(arr[par]<=arr[pos])
        {
            int temp = arr[par];
            arr[par] = arr[pos];
            arr[pos] = temp;
            pos = par;
            //cout << endl << val << " is inserted in the Heap." <<endl;
        }
        else
            return;
    }

}

void del(int *arr, int &n)
{
    int last = arr[n];
    n = n-1;
    int ptr = 1, left = 2, right = 3;
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
        left = 2*ptr;
        right = left+1;
    }

}

void display(int *arr, int &n)
{
    cout<<endl<<"Heap Tree is: ";
    for(int i=1;i<=n;i++)
        cout << arr[i]<<"\t";
    cout << endl;
}


int main()
{
    int root_val;
    cout << "Enter Root Value: ";
    cin >> root_val;
    int arr[] = {root_val};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ins_val, ch=-1;;
    while(ch!=4)
    {
        cout<<endl<<"-----------------------Heap Tree-------------------------"<<endl;
        cout<<endl<<"1. Insert"<<endl<<"2. Delete Root Node"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cout<<endl<<"Enter Your Choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<endl<<"Enter Value to be inserted in the Heap: ";
                cin>>ins_val;
                insert(arr,n,ins_val);
                break;
            case 2:
                del(arr,n);
                cout << "Root Value has been deleted!" << endl;
                break;
            case 3:
                display(arr,n);
                break;
        }
    }

    // insert(arr,n,36);
    // insert(arr,n,54);
    // insert(arr,n,27);
    // insert(arr,n,63);
    // insert(arr,n,72);
    // insert(arr,n,61);
    // insert(arr,n,18);
    // display(arr,n);
    //
    // del(arr,n);
    // display(arr,n);

    return 0;
}
