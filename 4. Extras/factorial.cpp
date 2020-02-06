#include <iostream>
using namespace std;


int fact(int a)
{
    if(a == 1 || a == 0)
        return 1;
    else
        return(a*fact(a-1));

}

int main()
{
    int a,res;
    cout<<"Enter A:"<<endl;
    cin>>a;
    res = fact(a);
    cout<<"Factorial Is:"<<endl<<res<<endl;
}
