#include <iostream>
using namespace std;
int main()
{
	int n,num,pos;
	cout<<"Enter Size of Array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter No. to be inserted"<<endl;
	cin>>num;	
	cout<<"Enter Position for insertion"<<endl;
	cin>>pos;
	pos--;
	for(int i=n-1;i>=pos;i--)
	{
		arr[i+1]=arr[i];
	}
	n++;
	arr[pos]=num;
	cout<<"Array is"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
	return 0;
}
