#include <iostream>
using namespace std;

int main()
{
	int n,pos;
	cout<<"Enter Size of Array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter Position"<<endl;
	cin>>pos;
	pos--;
	for(int i=pos;i<n;i++)
	{
		arr[i]=arr[i+1];
	}	
	n--;
	cout<<n;
	cout<<"Array is"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
	return 0;
}
