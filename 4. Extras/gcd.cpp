#include <iostream>
using namespace std;


int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    else
        return gcd(b,a%b);
}

int main()
{
    int a,b,res;
    cout<<"Enter A and B:"<<endl;
    cin>>a>>b;
    res = gcd(a,b);
    cout<<"GCD Is:"<<endl<<res<<endl;
}
