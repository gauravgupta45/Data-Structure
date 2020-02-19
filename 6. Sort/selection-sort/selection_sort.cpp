#include <iostream>
using namespace std;

int smallest(int* arr, int n, int k)
{
     int small = arr[k];
     int pos = k;
     for(int j=k+1;j<n;j++)
     {
         if(small>arr[j])
         small = arr[j];
         pos = j;
     }
     return pos;
}

int main()
{
    int n;
    cout<<"--------------------SELECTION SORT-------------------"<<endl;
    cout<<endl<<"Enter Array Size: ";
    cin>>n;
    int arr[n];
    int temp;
    cout<<endl<<"Enter Data: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int k=0;k<n;k++)
    {
        int pos = smallest(arr,n,k);
        int temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }

    cout<<endl<<"Array after Selection Sort: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
