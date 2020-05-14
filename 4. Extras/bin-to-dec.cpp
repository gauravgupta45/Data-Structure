#include <iostream>
using namespace std;

// CONCEPT:
// 4>>2 : is equivalent to 4/(2^2)   Since on right shifting the resulting number will be smaller, so division is carrired out.
// 4<<2 : is equivalent to 4*(2^2)   Since on left shifting the resulting number will be greater, so multiplication is carrired out.

void bintodec(int *arr,int n)
{
    int i,r = 0;
    while(i < n)
    {
        r = (r<<1) + arr[i++];
    }
    cout << r << endl;
}

int main()
{
    int arr[5] = {1,1,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bintodec(arr,n);
}
