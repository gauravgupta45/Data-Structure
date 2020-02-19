#include<iostream>
using namespace std;

int partition(int *a,int be,int e)
{
int right=a[e];
  int left=be;
  int i,t;
  for(i=be;i<e;i++)
  {
if(a[i]<=right)
      {
      t=a[i];
        a[i]=a[left];
        a[left]=t;
        left++;
      }
}

  t=a[e];
  a[e]=a[left];
  a[left]=t;

return left;
}

void quicksort(int *a,int be,int e)
{
int loc;
if(be<e)
{
loc=partition(a,be,e);
    quicksort(a,be,loc-1);
    quicksort(a,loc+1,e);
}
}

int main()
{
int n;
  cout<<"Size : ";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];

quicksort(a,0,n-1);

cout<<"Sorted array"<<endl;
  for(int i=0;i<n;i++)
  cout<<a[i]<<endl;

return 0;
}
