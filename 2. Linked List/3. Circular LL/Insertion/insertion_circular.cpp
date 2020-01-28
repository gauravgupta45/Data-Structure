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
                start->next=start;
            }
            else
            {   ptr=start;
                while(ptr->next!=start)
                    ptr=ptr->next;
                ptr->next=newnode;
                newnode->next=start;
                //cout<<"Newnode add = "<<newnode<<endl;
            }
            //cout<<"Start add = "<<start<<endl;
            //cout<<"Start next add = "<<start->next<<endl;
        }

        void insert_beg(int val) // First traverse the list and make the last node point to newnode. Then point newnode to start and finally give start tag to newnode.
        {
            node1* ptr;
            node1* newnode = new node1;
            newnode->data = val;

            ptr = start;
            while(ptr->next!=start)
                ptr=ptr->next;
            ptr->next = newnode;
            newnode->next=start;
            start = newnode;

        }

        void insert_end(int val)
        {
            node1* ptr;
            node1* newnode = new node1;
            newnode->data = val;
            ptr = start;
            while(ptr->next!=start)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = start;
        }

        int insert_bef(int val, int val_bef)
        {
            int search_flag = 0;
            node1* ptr;
            node1* newnode = new node1;
            ptr = start;
            newnode->data = val;

            if(start->next == start)      //checking if the first value is val_bef or not. if not it will continue to traverse to last element to find if val_before is there in the list or not.
            {
                if(start->data == val_bef)
                    search_flag = 1;
            }
            else
            {
                ptr = ptr->next;
                while(ptr!=start)   // we are checking the first element alone becoz the while loop will always be false (ptr!=start)(we have assisgned ptr=start above!)
                {
                    if(ptr->data == val_bef || start->data == val_bef)
                        search_flag = 1;
                    ptr=ptr->next;
                }
            }
            if(search_flag == 0)
            {
                cout<<endl<<"No such value in the list!"<<endl;
                return 0;
            }
            else
            {
                ptr = start;
                if(start->data == val_bef)        //if the inputed no. is first, so while inserting before, start tag will be changed(so traverse to last node and change its next address to newnode.).
                {
                    while(ptr->next!=start)
                        ptr = ptr->next;
                    ptr->next = newnode;
                    newnode->next = start;
                    start = newnode;
                }
                else
                {
                    while(ptr->next->data != val_bef)
                        ptr = ptr->next;
                    newnode->next = ptr->next;
                    ptr->next = newnode;
                }

            }
            return 0;
        }

        int insert_aft(int val, int val_aft)
        {
            int search_flag = 0;
            node1* ptr;
            node1* newnode = new node1;
            newnode->data = val;
            ptr = start;

            if(start->next == start)      //checking if the first value is val_bef or not. if not it will continue to traverse to last element to find if val_before is there in the list or not.
            {
                if(start->data == val_aft)
                    search_flag = 1;
            }
            else
            {
                ptr = ptr->next;
                while(ptr!=start)   // we are checking the first element alone becoz the while loop will always be false (ptr!=start)(we have assisgned ptr=start above!)
                {
                    if(ptr->data == val_aft || start->data == val_aft)
                        search_flag = 1;
                    ptr=ptr->next;
                }
            }
            if( search_flag == 0)
            {
                cout<<endl<<"No such value in the list!"<<endl;
                return 0;
            }
            else
            {   ptr = start;
                while(ptr->next!=start) // let suppose inputed no. is the last element of node so if we insert after it, next address of last node must be changed.
                    ptr = ptr->next;
                if(ptr->data == val_aft)
                {
                    newnode->next = start;
                    ptr->next = newnode;
                }
                else                        // in this case next address of last node remains same, because node is being inserted in the middle. that's why we have taken 2 different cases.
                {
                    ptr = start;
                    while(ptr->data!=val_aft)
                        ptr = ptr->next;
                    newnode->next = ptr->next;
                    ptr->next = newnode;
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
    cout<<"------------Insertion in Circular Linked List-----------"<<endl<<endl;
    cout<<"--------------------Create a List First-----------------"<<endl;
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
