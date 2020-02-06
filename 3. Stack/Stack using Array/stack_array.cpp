#include <iostream>
using namespace std;

void push(int val, int *stack, int &top, int size)
{
    if(top>=(size-1))
        cout<<endl<<"Stack is full! Overflow Condition."<<endl;
    else
    {
        top++;
        stack[top] = val;
    }
}

void pop(int &top)
{
    if(top<=-1)
        cout<<endl<<"Stack is empty! Underflow Condition."<<endl;
    else
        top--;
}

void display(int *stack, int &top)
{
    if(top<=-1)
        cout<<endl<<"Stack is empty!"<<endl;
    else
    {
        cout<<endl<<"Stack is: "<<endl;
        for(int i=top; i>=0; i--)
            cout<<stack[i]<<endl;
    }
}

int main()
{
    cout<<"---------------------------Stack using Array--------------------------"<<endl;
    int val;
    int top = -1;
    int stack[10];
    int size;
    cout<<endl<<"Enter size of Stack: "<<endl;
    cin>>size;
    int choice;
    do
    {
        cout<<endl<<"1. Push to Stack."<<endl<<"2. Pop from Stack."<<endl<<"3. Display."<<endl<<"4. Exit"<<endl<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<endl<<"Enter Data:"<<endl;
                cin>>val;
                push(val,stack,top,size);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                display(stack,top);
                break;
        };
    }
    while(choice != 4);
    return 0;
}
