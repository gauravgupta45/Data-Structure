#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"--------------------MERGE SORT-------------------"<<endl;
    cout<<endl<<"Enter Array Size: ";
    cin>>n;
    int arr[n];
    int temp,j;
    cout<<endl<<"Enter Data: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    return 0;
}
