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
            newnode->data = value;
            if(start == NULL)
            {
                start = newnode;
                start->next = start;
            }
            else
            {
                ptr = start;
                while(ptr->next != start)
                    ptr = ptr->next;
                ptr->next = newnode;
                newnode->next = start;
            }
        }

        int del_beg()
        {
            node1* ptr;
            if(start->next == start) // this is the case in which only one element is present in the list.
            {
                //delete start;
                start->data = int(NULL);
                //cout<<start->data<<endl;
                return 1;
            }
            else
            {
                ptr = start;
                while(ptr->next != start)
                    ptr = ptr->next;
                ptr->next = start->next;
                ptr = start;
                start = start->next;
                delete ptr;
                return 0;
            }
        }

        int del_end()
        {
            node1* ptr;
            if(start->next == start)
            {
                start->data = int(NULL);
                return 1;
            }
            else
            {
                ptr = start;
                while(ptr->next->next != start)
                    ptr = ptr->next;
                delete ptr->next;
                ptr->next = start;
                return 0;
            }
        }

        int del_bef(int val_bef)
        {
            int search_flag = 0;
            node1* ptr;
            node1* preptr;
            node1* temp;

            if(start->data == val_bef)
            {
                cout<<endl<<"No value before "<<start->data<<"!"<<endl;
                return 0;
            }

            ptr = start->next;
            while(ptr!=start)
            {
                if(ptr->data == val_bef)
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
                if(start->next->data == val_bef)
                {
                    ptr = start;
                    while(ptr->next != start)
                        ptr = ptr->next;
                    temp = ptr->next;
                    ptr->next = start->next;
                    start = start->next;
                    delete temp;
                }
                else
                {
                    ptr = start;
                    preptr = ptr;
                    while(ptr->next->data != val_bef)
                    {
                        preptr = ptr;
                        ptr = ptr->next;
                    }
                    preptr->next = ptr->next;
                }
            }
            return 0;
        }

        int del_aft(int val_aft)
        {
            int search_flag=0;
            node1* ptr;
            node1* temp;

            //This is the case in which the input value is not in the list. So we've to traverse the list to find if the no. entered is present or not.
            //so we are checking that if first element is val_aft or not.

            if(start->next == start)
            {
               if(start->data == val_aft)
                    search_flag = 1;
            }

            else
            {
                ptr = start->next;
                while(ptr!=start)
                {
                    if(ptr->data == val_aft || start->data == val_aft)
                        {
                            search_flag = 1;
                            //cout<<"search flag = 1"<<endl;
                        }
                    ptr=ptr->next;
                }
            }

            if (search_flag == 0)
            {
                cout<<endl<<"No such value in the list!"<<endl;
                return 0;
            }
            else
            {
                //this is the case in which list contains only one node
                if(start->next == start)
                {
                    cout<<endl<<"No value After "<<start->data<<"!"<<endl;
                    return 0;
                }

                else
                {
                // this is the case in which input value is equal to last node value (there is no value after last node so we have to print "no value after ptr->data")
                    ptr = start;
                    while(ptr->next!= start)    //moving ptr to the last node to check if the input value is of last node or not.
                    ptr = ptr->next;
                    if(ptr->data == val_aft)
                    {
                        cout<<endl<<"No value After "<<ptr->data<<endl;
                        return 0;
                    }
                }

                while(ptr->next->next != start)     //this is the case in which input value is equal to the second last node value. in this case start last element will be deleted.
                    ptr = ptr->next;
                if(ptr->data == val_aft)
                    {
                        delete ptr->next;
                        ptr->next = start;
                    }
                else
                {
                    ptr = start;
                    while(ptr->data != val_aft)
                        ptr = ptr->next;
                    temp = ptr->next->next;
                    delete ptr->next;
                    ptr->next = temp;
                }
            }
            return 0;
        }

        void display()
        {
            cout<<endl<<"List is:"<<endl;
            node1* ptr;
            ptr=start;
            cout<<ptr->data<<endl;
            ptr=ptr->next;
            while(ptr!=start)
            {
                cout<<ptr->data<<endl;
                ptr=ptr->next;
            }
        }
};



int main()
{
    int n,value;
    A obj;
    cout<<"------------Deletion in Circular Linked List-----------"<<endl<<endl;
    cout<<"-------------------Create a List First-----------------"<<endl;
    cout<<endl<<"Enter List Size:"<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"Enter valid size!"<<endl;
        return 0;
    }
    cout<<endl<<"Enter List Values:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        obj.create(value);
    }

    int choice,val_bef,val_aft,flag_1,flag_2;
    cout<<endl<<"------------MENU-------------"<<endl<<endl;
    cout<<"1. Delete First Element."<<endl<<"2. Delete Last Element."<<endl<<"3. Delete Before."<<endl<<"4. Delete After."<<endl<<"5. Display."<<endl<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        flag_1 = obj.del_beg();
        if(flag_1 == 1)
            cout<<endl<<"List is Empty now!"<<endl;
        else
            obj.display();
        break;

    case 2:
        flag_2 = obj.del_end();
        if(flag_2 == 1)
            cout<<endl<<"List is Empty now!"<<endl;
        else
            obj.display();
        break;

    case 3:
        cout<<endl<<"Before:"<<endl;
        cin>>val_bef;
        obj.del_bef(val_bef);
        obj.display();
        break;

    case 4:
        cout<<endl<<"After:"<<endl;
        cin>>val_aft;
        obj.del_aft(val_aft);
        obj.display();
        break;

    case 5:
        obj.display();
        break;
    }
    return 0;
}
