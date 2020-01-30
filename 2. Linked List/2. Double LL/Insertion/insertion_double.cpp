#include <iostream>
using namespace std;

struct node1
{
    int data;
    node1* prev;
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
            newnode->data = value;
            if(start == NULL)
            {
                start = newnode;
                start->next=NULL;
                start->prev = NULL;
            }
            else
            {   ptr=start;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=newnode;
                newnode->next=NULL;
                newnode->prev = ptr;
                //cout<<"Newnode add = "<<newnode<<endl;
            }
        }

        void insert_beg(int val)
        {
            node1* newnode = new node1;
            newnode->data = val;
            newnode->next = start;
            start->prev = newnode;
            newnode->prev = NULL;
            start = newnode;
        }

        void insert_end(int val)
        {
            node1* ptr;
            node1* newnode = new node1;
            newnode->data = val;
            newnode->next = NULL;
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            newnode->prev = ptr;
            ptr->next = newnode;

        }

        int insert_bef(int val, int val_bef)
        {
            int search_flag = 0;
            node1* ptr;
            node1* newnode = new node1;
            newnode->data = val;

            ptr = start;
            while(ptr!=NULL)
            {
                if(ptr->data == val_bef)
                    search_flag = 1;
                ptr = ptr->next;
            }

            if(search_flag == 0)
            {
                cout<<endl<<"No such Value in the List!"<<endl;
                return 0;
            }

            else
            {
                if(start->data == val_bef)
                {
                    start->prev = newnode;
                    newnode->prev = NULL;
                    newnode->next = start;
                    start = newnode;
                    return 0;
                }
                else
                {
                    ptr = start;
                    while(ptr->data != val_bef)
                        ptr = ptr->next;
                    newnode->next = ptr;
                    newnode->prev = ptr->prev;
                    ptr->prev->next = newnode;
                    ptr->prev = newnode;
                    return 0;
                }
            }
        }

        int insert_aft(int val, int val_aft)
        {
            int search_flag = 0;
            node1* ptr;
            node1* newnode = new node1;
            newnode->data = val;

            ptr = start;
            while(ptr!=NULL)
            {
                if(ptr->data == val_aft)
                    search_flag = 1;
                ptr = ptr->next;
            }

            if(search_flag == 0)
            {
                cout<<endl<<"No such value in the List!"<<endl;
                return 0;
            }

            else
            {

                ptr = start;
                while(ptr->data != val_aft)
                    ptr = ptr->next;
                if(ptr->next == NULL) //checking if val_aft is equal to the value of last node. 
                {
                    ptr->next = newnode;
                    newnode->next = NULL;
                    newnode->prev = ptr;
                }
                else
                {
                    newnode->next = ptr->next;
                    ptr->next->prev=newnode;
                    ptr->next = newnode;
                    newnode->prev = ptr;
                }
            }
        }

        void display()
        {
            node1* ptr;
            ptr = start;
            cout<<endl<<"List is:"<<endl;
            while(ptr != NULL)
            {
                cout<<ptr->data<<endl;
                ptr = ptr->next;
            }
        }
};




int main()
{
    int n,value;
    A obj;
    cout<<"------------Insertion in Double Linked List-----------"<<endl<<endl;
    cout<<"-------------------Create a List First----------------"<<endl;
    cout<<endl<<"Enter List Size:"<<endl;
    cin>>n;
    cout<<endl<<"Enter List Values:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        obj.create(value);
    }

    int choice,val,val_bef,val_aft;
    cout<<endl<<"---------------------------MENU-------------------------"<<endl;
    cout<<endl<<"1. Insert at the Beginning."<<endl<<"2. Insert at the End."<<endl<<"3. Insert Before."<<endl<<"4. Insert After."<<endl<<"5. Display."<<endl<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<endl<<"Value to be inserted at the Beginning:"<<endl;
        cin>>val;
        obj.insert_beg(val);
        obj.display();
        break;

    case 2:
        cout<<endl<<"Value to be inserted at the End:"<<endl;
        cin>>val;
        obj.insert_end(val);
        obj.display();
        break;

    case 3:
        cout<<endl<<"Value to be inserted:"<<endl;
        cin>>val;
        cout<<endl<<"Before:"<<endl;
        cin>>val_bef;
        obj.insert_bef(val,val_bef);
        obj.display();
        break;

    case 4:
        cout<<endl<<"Value to be inserted:"<<endl;
        cin>>val;
        cout<<endl<<"After:"<<endl;
        cin>>val_aft;
        obj.insert_aft(val,val_aft);
        obj.display();
        break;

    case 5:
        obj.display();
        break;
    }
    return 0;
}
