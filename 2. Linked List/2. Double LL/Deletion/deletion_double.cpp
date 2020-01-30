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
            }
        }


        int del_beg()
        {
            if(start->next!=NULL)

            {   node1* ptr;
                ptr = start;
                start = ptr->next;
                delete ptr;
                start->prev = NULL;
            }
            else
            {
                delete start;
                cout<<endl<<"List is Empty now!"<<endl;
                return 0;
            }



        }

        int del_end()
        {
            node1* ptr;

            if(start->next!= NULL)
            {
                ptr = start;
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->prev->next = NULL;
                delete ptr;
            }
            else
            {
                delete start;
                cout<<endl<<"List is empty now!"<<endl;
                return 0;
            }
        }

        int del_bef(int bef)
        {
            int search_flag = 0;
            node1* ptr;
            ptr = start;
            while(ptr != NULL)
            {
                if(ptr->data == bef)
                    search_flag = 1;
                ptr = ptr->next;
            }

            if(search_flag == 0)
            {
                cout<<endl<<"No such value in the list!"<<endl;
                return 0;
            }

            else
            {
                if(start->data == bef)
                {
                    cout<<endl<<"No value before "<<start->data<<"!"<<endl;
                    return 0;
                }
                if(start->next->data == bef)
                {
                    ptr = start;
                    start = ptr->next;
                    delete ptr;
                    start->prev = NULL;
                }

                else
                {
                    ptr = start;
                    while(ptr->next->data != bef)
                        ptr = ptr->next;
                    ptr->next->prev = ptr->prev->next;
                    ptr->prev->next = ptr->next;
                }
            }
        }
        int del_aft(int aft)
        {
            int search_flag = 0;
            node1* ptr;
            node1* temp;
            ptr = start;
            while(ptr != NULL)
            {
                if(ptr->data == aft)
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
                while(ptr->data!=aft)
                    ptr = ptr->next;
                if(ptr->next == NULL)
                {
                    cout<<endl<<"No value after "<<ptr->data<<"!"<<endl;
                    return 0;
                }

                if(ptr->next->next == NULL)
                {
                    delete ptr->next;
                    ptr->next = NULL;
                }
                else
                {
                    temp = ptr->next->next;
                    delete ptr->next;
                    ptr->next = temp;
                    temp->prev = ptr;
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
    cout<<"------------Deletion in Double Linked List-----------"<<endl<<endl;
    cout<<"-------------------Create a List First----------------"<<endl;
    cout<<endl<<"Enter List Size:"<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<endl<<"Enter Valid Size!"<<endl;
        return 0;
    }
    cout<<endl<<"Enter List Values:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        obj.create(value);
    }

    int choice,val,res;
    cout<<endl<<"---------------------------MENU-------------------------"<<endl;
    cout<<endl<<"1. Delete First Element."<<endl<<"2. Delete Last Element."<<endl<<"3. Delete Before."<<endl<<"4. Delete After."<<endl<<"5. Display."<<endl<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:

        res = obj.del_beg();
        if(res!=0)
            obj.display();
        break;

    case 2:
        res = obj.del_end();
        if(res!=0)
            obj.display();
        break;

    case 3:
        cout<<endl<<"Before:"<<endl;
        cin>>val;
        obj.del_bef(val);
        obj.display();
        break;

    case 4:
        cout<<endl<<"After:"<<endl;
        cin>>val;
        obj.del_aft(val);
        obj.display();
        break;

    case 5:
        obj.display();
        break;
    }
    return 0;
}
