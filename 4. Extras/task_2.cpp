#include <iostream>
using namespace std;

struct node1
{
    int data;
    node1* next;
};
class A
{
    private:
        node1* start;
    public:
        A()
        {
            start = NULL;
        }
        void create(int value)
        {
            node1* ptr;
            node1* newnode = new node1;
            newnode->data=value;
            if (start==NULL)
            {
                start=newnode;
                newnode->next=NULL;
            }
            else
            {
                ptr=start;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=newnode;
                newnode->next=NULL;
            }
        }

        void display()
        {
            cout<<endl<<"List is:"<<endl;
            node1* ptr;
            ptr=start;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<endl;
                ptr=ptr->next;
            }
        }

        void duplicay_factor(int val)
        {
            node1* ptr;
            int c=0;
            ptr = start;
            while(ptr != NULL)
            {
                if(ptr->data == val)
                    c++;
                ptr = ptr->next;
            }
            cout<<endl<<"Duplicacy factor: "<<c<<endl;
        }

        void duplicate_elem()
        {
            int count=0;
            node1* ptr1;
            node1* ptr2;
            ptr1 = start;

            while(ptr1 != NULL)
            {
                ptr2 = start;
                count = 1;
                while(ptr2 != NULL)
                {
                    if(ptr1 == ptr2)
                    {
                        ptr2 = ptr2->next;
                    }
                    if(ptr1->data == ptr2->data)
                        count++;
                    ptr2 = ptr2->next;
                }
                if(count>1)
                    cout<<ptr1->data<<" is repeated "<<count<<" times!"<<endl;
                ptr1 = ptr1->next;
            }
        }
};

int main()
{
    int n;
    A obj;
    int value,choice;
    cout<<"##################################--Some Random Task--####################################"<<endl<<endl;
    cout<<"------------------Create a List First-----------------"<<endl;
    cout<<endl<<"Enter List Size"<<endl;
    cin>>n;
    cout<<"Enter List Data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        obj.create(value);
    }

    int val;
    cout<<endl<<"------------MENU-------------"<<endl<<endl;
    cout<<"1. Check how many Elements are Duplicate and there occurrence."<<endl<<"2. Check the occurence of a specific Element."<<endl<<"3. Display List"<<endl<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<endl;
        obj.duplicate_elem();
        break;
    case 2:
        cout<<endl<<"Specify Element:"<<endl;
        cin>>val;
        obj.duplicay_factor(val);
        break;
    case 3:
        obj.display();
    }
    return 0;
}
