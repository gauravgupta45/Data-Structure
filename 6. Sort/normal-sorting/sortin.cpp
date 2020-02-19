#include <iostream>
using namespace std;

int main()
{
	int n,t;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
	}
	
	cout<<"Array is"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
	
}
