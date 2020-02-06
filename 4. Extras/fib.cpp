#include <iostream>
using namespace std;


int fib(int x)
{
    if(x==0 || x==1)
        return(x);
    else
        return(fib(x-1)+fib(x-2));
}

int main()
{
    int y,res;
    cout<<"Enter Limit :"<<endl;
    cin>>y;
    cout<<endl<<"Output is:"<<endl;
    for(int i=0;i<y;i++)
        cout<<" "<<fib(i)<<endl;
}

