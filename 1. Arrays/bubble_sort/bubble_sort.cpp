#include <iostream>
using namespace std;

int main()
{
	int n,t;
	cout<<"Enter Array Size"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;				
			}
		}
	}
	cout<<"Array is"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;	
}
