#include <iostream>
using namespace std;

int front=-1,rear=-1;
int size=1;
int q[10];

void insert(int*,int,int);
void del(int);
void display(int*, int);



int main()
{
    int s,choice,data;
    cout<<"Enter Size of Queue: ";
    cin>>s;
    ::size=s;
    ::q[s];
    do
    {
        cout<<endl<<"----------------------------MENU--------------------------"<<endl;
        cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cout<<"Enter your choice ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Data:";
                cin>>data;
                insert(q,data,s);
                break;

            case 2:
                del(s);
                break;

            case 3:
                display(q,s);
                break;
        }
    }while(choice != 4);
return 0;
}

void insert(int* q,int data, int size)
{
    if(front==0 && rear==(size-1) || front==rear+1)
        cout<<endl<<"Overflow"<<endl;
    else if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        q[rear]=data;
    }

    else if(rear==(size-1))
    {
        rear=0;
        q[rear]=data;
    }
    else
    {
        rear++;
        q[rear]=data;
    }
}

void del(int size)
{
    if(front==-1 && rear==-1)
        cout<<endl<<"Underflow "<<endl;
    else if(front==rear)
        {
            front=-1;
            rear=-1;
        }
    else if(front==(size-1))
        front=0;
    else
        front++;
}

void display(int* q, int size)
{
    if(front==-1 && rear==-1)
        cout<<endl<<"Queue is Empty!"<<endl;
    else
    {
        cout<<endl<<"Queue is: "<<endl;
        int i;
        if(front<=rear)
        {
            for(i=front;i<=rear;i++)
            cout<<q[i]<<endl;
        }
        else
        {
            for(i=front;i<(size-1);i++)
                cout<<q[i];
            for(i=0;i<=rear;i++)
                cout<<q[i];
        }
    }
}
