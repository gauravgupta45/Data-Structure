#include <iostream>
using namespace std;

int smallest(int *arr, int i, int n)
{
    int smallest_index = i;
    for(int j = i+1; j<n; j++)
    {
        if(arr[j]<arr[smallest_index])
        {
            smallest_index = j;
        }
    }
    return smallest_index;
}

void selection_sort(int *arr, int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        int smallest_index = smallest(arr,i,n);
        temp = arr[i];
        arr[i] = arr[smallest_index];
        arr[smallest_index] = temp;
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid+1, k = low, aux_arr[20];
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
            aux_arr[k++] = arr[i++];
        else
            aux_arr[k++] = arr[j++];
    }

    while(i<=mid)
        aux_arr[k++] = arr[i++];
    while(j<=high)
        aux_arr[k++] = arr[j++];
    for(int i=0;i<=high;i++)
        arr[i] = aux_arr[i];
}

void merge_sort (int *arr, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main()
{
    int n,m;
    cout<<"--------------------MERGE SORT-------------------"<<endl;
    cout<<endl<<"Enter Array-1 Size: ";
    cin>>n;
    int arr1[n];
    cout<<endl<<"Enter Data: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    selection_sort(arr1,n);

    cout<<endl<<"Enter Array-2 Size: ";
    cin>>m;
    int arr2[m];
    cout<<endl<<"Enter Data: "<<endl;
    for(int i=0;i<m;i++)
        cin>>arr2[i];
    selection_sort(arr2,m);

    int z = n+m;
    int arr3[z];
    for(int i=0;i<z;i++)
    {
        if(i<n)
            arr3[i] = arr1[i];
        else
            arr3[i] = arr2[i-n];
    }

    merge_sort(arr3,0,z-1);
    cout<<endl<<"Merge Sorted Array is:"<<endl;
    for(int i=0;i<z;i++)
        cout<<arr3[i]<<" ";

    return 0;
}
