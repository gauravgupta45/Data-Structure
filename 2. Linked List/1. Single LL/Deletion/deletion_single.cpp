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


        int del_beg()
        {
            int flag=0;
            node1* ptr;
            ptr = start;
            start=ptr->next;  //This means list will start from 2nd element. So First element is deleted.
            delete ptr;
            if(start==NULL)
                flag=401;
            return flag;
        }

        int del_end()
        {
            int flag=0;
            node1* ptr;
            ptr = start;
            if(start->next==NULL)
            {
                delete ptr;                     //or ptr = NULL;
                flag=401;
            }
            else
            {
                while(ptr->next->next!=NULL)
                ptr=ptr->next;
                ptr->next=NULL;                 //ptr is at 2nd last element so setting its address to NULL, which will make it last element.
            }
            return flag;
        }

        void del_bef(int bef)
        {
            int search_flag=0;
            node1* ptr;
            node1* preptr;
            ptr = start;
            preptr = ptr;
            while(ptr!=NULL)
            {
                if(ptr->data==bef)
                    search_flag=1;
                ptr=ptr->next;
            }
            if(search_flag!=1)
                cout<<endl<<bef<<" is not present in the list!"<<endl;
            else
            {
                ptr=start;
                if(start->data==bef)                             //if list only consists of 1 element.
                    cout<<endl<<"No Value before "<<bef<<"!"<<endl;
                else
                {
                    while(ptr->next->data!=bef)
                    {
                        preptr=ptr;
                        ptr=ptr->next;
                    }
                    if(ptr==preptr)
                    {
                        start=ptr->next;
                        preptr->next=ptr->next;
                        delete ptr;
                    }
                    else
                    {
                        preptr->next=ptr->next;
                        delete ptr;
                    }

                }
            }
        }

        void del_aft(int aft)
        {
            int search_flag=0;
            node1* ptr;
            node1* temp;
            ptr = start;
            while(ptr!=NULL)
            {
                if(ptr->data==aft)
                    search_flag=1;
                ptr=ptr->next;
            }
            if(search_flag!=1)
                cout<<endl<<aft<<" is not present in the list!"<<endl;
            else
            {
                ptr=start;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                if(ptr->data==aft)
                    cout<<endl<<"No value after "<<aft<<"!"<<endl;
                else
                {
                    ptr=start;
                    while(ptr->data!=aft)
                        ptr=ptr->next;
                    temp=ptr->next;
                    delete ptr->next;
                    ptr->next=temp->next;
                }
            }
        }

        void del_node(int node_val)
        {
            int search_flag=0;
            node1* ptr;
            node1* temp;
            ptr = start;
            while(ptr!=NULL)
            {
                if(ptr->data==node_val)
                    search_flag=1;
                ptr=ptr->next;
            }
            if(search_flag!=1)
                cout<<endl<<node_val<<" is not present in the list!"<<endl;
            else
            {
                ptr=start;
                if(ptr->data==node_val)
                {
                    start = ptr->next;
                    delete ptr;
                }
                else
                {
                    while(ptr->next->data!=node_val)
                        ptr=ptr->next;
                    temp=ptr->next;
                    delete ptr->next;
                    ptr->next=temp->next;
                }
            }
        }

};

int main()
{
    int n,values,choice;
    A obj;
    cout<<"------------Deletion in Single Linked List-----------"<<endl<<endl;
    cout<<"------------------Create a List First-----------------"<<endl;
    cout<<endl<<"Enter List Size"<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"Enter Valid Size!"<<endl;
        return 0;
    }
    cout<<"Enter List Data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>values;
        obj.create(values);
    }

    int bef,aft,node_val,flag_1,flag_2;
    cout<<endl<<"------------MENU-------------"<<endl<<endl;
    cout<<"1. Delete First Element."<<endl<<"2. Delete Last Element."<<endl<<"3. Delete Before."<<endl<<"4. Delete After."<<endl<<"5. Delete a Node."<<endl<<"6. Display."<<endl<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        flag_1=obj.del_beg();
        if (flag_1==401)
            cout<<endl<<"List is Empty Now!"<<endl;
        else
            obj.display();
        break;

    case 2:
        flag_2 = obj.del_end();
        if (flag_2==401)
            cout<<endl<<"List is Empty Now!"<<endl;
        else
            obj.display();
        break;

    case 3:
        cout<<"Before:"<<endl;
        cin>>bef;
        obj.del_bef(bef);
        obj.display();
        break;

    case 4:
        cout<<"After:"<<endl;
        cin>>aft;
        obj.del_aft(aft);
        obj.display();
        break;
    case 5:
        cout<<endl<<"Enter Value to be DELETED"<<endl;
        cin>>node_val;
        obj.del_node(node_val);
        obj.display();
        break;
    case 6:
        obj.display();
        break;
    }
}
