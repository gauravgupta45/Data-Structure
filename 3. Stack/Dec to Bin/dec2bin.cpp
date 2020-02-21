#include <iostream>
using namespace std;

void dectobin(int data)
{
    int rem,top=-1;
    int stk[10];
    while(data > 0)
    {
        rem = data%2;
        data = data/2;
        top++;
        stk[top] = rem;
    }
    for(int i=top;i>=0;i--)
        cout<<stk[i];
}

int main()
{
    cout<<"-------------# Decimal To Binary #------------"<<endl<<endl;
    int data;
    cout<<"Enter Decimal No.:"<<endl;
    cin>>data;
    cout<<endl<<"Binary Representation is: "<<endl;
    dectobin(data);
    return 0;
}
