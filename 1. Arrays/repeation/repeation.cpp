#include <iostream>
using namespace std;

void normal_search(int arr[],int n)
{
	int num,c;
	cout<<"Enter No. to search for:"<<endl;
	cin>>num;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==num)
			c++;
	}	
	cout<<num <<" is repeated "<<c<<" times."<<endl;
}

int main()
{
	int n;
	cout<<"Enter Array size"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	normal_search(arr,n);
	
	return 0;
}
