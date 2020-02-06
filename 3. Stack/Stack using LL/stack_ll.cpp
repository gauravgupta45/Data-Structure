#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class A
{
    node* head;
    int counter;
    public:
        A()
        {
            head = NULL;
            counter = 0;
        }

        void push(int val, int size)
        {
            if(counter < size)
            {
                node* newnode  = new node;
                newnode->data = val;
                if(head == NULL)
                {
                    newnode->next = head;
                    head = newnode;
                    counter++;
                }
                else
                {
                    newnode->next = head;
                    head = newnode;
                    counter++;
                }

            }
            else
            {
                cout<<endl<<"Stack is Full! Overflow Condition."<<endl;
            }
        }

        void pop()
        {
            if(head == NULL)
                cout<<endl<<"Stack is Empty!"<<endl;
            else
                head = head->next;
        }

        void display()
        {
            node* ptr;
            ptr = head; 
            if(ptr == NULL)
                cout<<endl<<"Stack is Empty!"<<endl;
            else
            {
                cout<<endl<<"Stack is:"<<endl;
                while(ptr != NULL)
                {
                    cout<<ptr->data<<endl;
                    ptr = ptr->next;
                }
            }
        }
};


int main()
{
    int size;
    A obj;

    cout<<"----------------------------Stack using Linked List--------------------------"<<endl;
    int val;
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
                obj.push(val,size);
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                obj.display();
                break;
        };
    }
    while(choice != 4);
    return 0;












    return 0;
}
