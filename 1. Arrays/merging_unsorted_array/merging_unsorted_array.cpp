#include <iostream>
using namespace std;
int main()
{
	int n1,n2;
	cout<<"Enter array Size"<<endl;
	cin>>n1;
	
	int arr1[n1];
	cout<<"Enter Array"<<endl;
	for(int i=0;i<n1;i++)
		cin>>arr1[i];
	cout<<"Enter array Size"<<endl;
	cin>>n2;
	
	int arr2[n2];
	cout<<"Enter Array"<<endl;
	for(int i=0;i<n2;i++)
		cin>>arr2[i];
	
	int arr3[n1+n2];
	
	for(int i=0;i<n1+n2;i++)
	{
		if(i<n1)
			arr3[i]=arr1[i];
		else
			arr3[i]=arr2[i-n1];
	}
	
	cout<<"Array is"<<endl;
	for(int i=0;i<n1+n2;i++)
		cout<<arr3[i]<<endl;
	
	return 0;
}
