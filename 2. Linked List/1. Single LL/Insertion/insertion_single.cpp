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


        void insert_beg(int val)
        {
            node1* newnode = new node1;
            newnode->data=val;
            newnode->next=start;
            start=newnode;
        }

        void insert_end(int val)
        {
            node1* ptr;
            ptr=start;
            node1* newnode = new node1;
            newnode->data=val;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=NULL;
        }

        void insert_bef(int val, int val_bef)
        {
            int flag=0;
            node1* ptr;
            node1* preptr;
            node1* newnode = new node1;
            newnode->data=val;
            ptr=start;
            preptr=ptr;

            while(ptr->data!=val_bef && flag!=404)     //this is the loop which will check if no. entered is present in the list or not. If it is not then flag will be 404. It will also move the ptr tag to node which contains num_bef
            {
                if(ptr->next!=NULL)
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
                else
                    flag=404;
            }
            if(flag == 404)
                cout<<endl<<"No such value in the list."<<endl;
            else
            {
                //ptr = start;
                if(start->data == val_bef) //this is the case in which no. is being inserted before starting node. So start tag will be changed.
                {
                    start = newnode;
                    newnode->next = ptr;
                }
                else
                {
                    /*while(ptr->data != bef)
                    {
                        preptr = ptr;
                        ptr = ptr->next;
                    }*/
                    preptr->next = newnode;
                    newnode->next = ptr;
                }
            }
        }

        void insert_aft(int val, int val_aft)
        {
            int flag=0;
            node1* ptr;
            node1* newnode = new node1;
            newnode->data=val;
            ptr=start;
            while(ptr->data!=val_aft && flag!=404)
            {
                if(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                else
                    flag=404;
            }
            if(flag == 404)
                cout<<endl<<"No such value in the list."<<endl;
            else
            {
                newnode->next=ptr->next;
                ptr->next=newnode;
            }
            cout<<"last node addr: "<<newnode->next<<endl;
        }

};

int main()
{
    int n;
    A obj;
    int value,choice;
    cout<<"------------Insertion in Single Linked List-----------"<<endl<<endl;
    cout<<"------------------Create a List First-----------------"<<endl;
    cout<<endl<<"Enter List Size"<<endl;
    cin>>n;
    cout<<"Enter List Data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        obj.create(value);
    }

    int val,val_bef,val_aft;
    cout<<endl<<"------------MENU-------------"<<endl<<endl;
    cout<<"1. Insert in Beginning."<<endl<<"2. Insert in Last."<<endl<<"3. Insert Before."<<endl<<"4. Insert After."<<endl<<"5. Display."<<endl<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<endl<<"Enter Value to be INSERTED at the BEGINING:"<<endl;
        cin>>val;
        obj.insert_beg(val);
        obj.display();
        break;

    case 2:
        cout<<endl<<"Enter Value to be INSERTED at the END:"<<endl;
        cin>>val;
        obj.insert_end(val);
        obj.display();
        break;

    case 3:
        cout<<endl<<"Enter VALUE to be INSERTED:"<<endl;
        cin>>val;
        cout<<"Before:"<<endl;
        cin>>val_bef;
        obj.insert_bef(val,val_bef);
        obj.display();
        break;

    case 4:
        cout<<endl<<"Enter VALUE to be INSERTED:"<<endl;
        cin>>val;
        cout<<"After:"<<endl;
        cin>>val_aft;
        obj.insert_aft(val,val_aft);
        obj.display();
        break;

    case 5:
        obj.display();
        break;
    }
}
