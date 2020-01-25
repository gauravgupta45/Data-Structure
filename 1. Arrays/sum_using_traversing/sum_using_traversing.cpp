#include <iostream>
using namespace std;

void sum_fun(int arr[],int n)
{
	int sum=0;
	
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
		
	cout<<"Sum is: "<<sum<<endl;
}

void max_min_fun(int arr[],int n)
{
	int max,min,t;
	
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
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
	cout<<"Min value is: "<<arr[0]<<endl;
	cout<<"Max value is: "<<arr[n-1]<<endl;

}




int main()
{
	int n;
	cout<<"Enter Size of Array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
//	sum_fun(arr,n);
	max_min_fun(arr,n);
}
