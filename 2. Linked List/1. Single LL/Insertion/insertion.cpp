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
        void create(int val)
        {
            node1* ptr;
            node1* newnode = new node1;
            newnode->data=val;
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


        void insert_beg(int num_beg)
        {
            node1* newnode = new node1;
            newnode->data=num_beg;
            newnode->next=start;
            start=newnode;
        }

        void insert_end(int num_end)
        {
            node1* ptr;
            ptr=start;
            node1* newnode = new node1;
            newnode->data=num_end;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=NULL;
        }

        void insert_bef(int num_bef, int bef)
        {
            int flag=0;
            node1* ptr;
            node1* preptr;
            node1* newnode = new node1;
            newnode->data=num_bef;
            ptr=start;
            preptr=ptr;
            while(ptr->data!=bef && flag!=404)
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
                cout<<"ERROR! Value is not in the list."<<endl;
            else
            {
                preptr->next=newnode;
                newnode->next=ptr;
            }
        }

        void insert_aft(int num_aft, int aft)
        {
            int flag=0;
            node1* ptr;
            node1* newnode = new node1;
            newnode->data=num_aft;
            ptr=start;
            while(ptr->data!=aft && flag!=404)
            {
                if(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                else
                    flag=404;
            }
            if(flag == 404)
                cout<<"ERROR! Value is not in the list."<<endl;
            else
            {
                newnode->next=ptr->next;
                ptr->next=newnode;
            }
        }

};

int main()
{
    int n;
    A obj;
    int values,choice;
    cout<<"--------Create a List First------"<<endl;
    cout<<endl<<"Enter List Size"<<endl;
    cin>>n;
    cout<<"Enter List Data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>values;
        obj.create(values);
    }

    int num_beg,num_end,num_aft,aft,num_bef,bef;
    cout<<endl<<"------------MENU-------------"<<endl<<endl;
    cout<<"1. Insert in Beginning."<<endl<<"2. Insert in Last."<<endl<<"3. Insert Before."<<endl<<"4. Insert After."<<endl<<"5. Display."<<endl<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<endl<<"Enter Value to be INSERTED at the BEGINING:"<<endl;
        cin>>num_beg;
        obj.insert_beg(num_beg);
        obj.display();
        break;

    case 2:
        cout<<endl<<"Enter Value to be INSERTED at the END:"<<endl;
        cin>>num_end;
        obj.insert_end(num_end);
        obj.display();
        break;

    case 3:
        cout<<endl<<"Enter VALUE to be INSERTED:"<<endl;
        cin>>num_bef;
        cout<<"Before:"<<endl;
        cin>>bef;
        obj.insert_bef(num_bef,bef);
        obj.display();
        break;

    case 4:
        cout<<endl<<"Enter VALUE to be INSERTED:"<<endl;
        cin>>num_aft;
        cout<<"After:"<<endl;
        cin>>aft;
        obj.insert_aft(num_aft,aft);
        obj.display();
        break;

    case 5:
        obj.display();
        break;
    }
}
