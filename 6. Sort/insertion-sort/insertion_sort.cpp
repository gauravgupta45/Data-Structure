#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"--------------------INSERTION SORT-------------------"<<endl;
    cout<<endl<<"Enter Array Size: ";
    cin>>n;
    int arr[n];
    int temp,j;
    cout<<endl<<"Enter Data: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int k=1;k<n;k++)
    {
        temp = arr[k];
        j = k-1;
        while(temp<arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    cout<<endl<<"Array after Insertion Sort: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
}
