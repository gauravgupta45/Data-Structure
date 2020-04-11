#include <iostream>
using namespace std;

class Node
{
    private:
        char vertex;
        Node* next;
        Node* adj;
    public:
        Node(char vertex = '\0')
        {
            this->vertex = vertex;
            this->next = NULL;
            this->adj = NULL;
        }
        friend class LinkedGraph;
};

class LinkedGraph
{
    Node* head;
    public:
        LinkedGraph()
        {
            head = NULL;
        }
        void AddVertex(Node*);
        int ShowVertex();
        int AddAdj(char, char);
        int ShowAdj(char);
};


void LinkedGraph :: AddVertex(Node* newnode)
{
    if(head == NULL)
        head = newnode;
    else
    {
        Node* temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = newnode;
    }
}

int LinkedGraph :: ShowVertex()
{
    if(head == NULL)
    {
        cout<<endl<<"Graph is Empty! Add some vertices first."<<endl;
        return 0;
    }
    Node* temp = head;
    cout<<endl<<"Nodes of Graph are: ";
    while(temp!=NULL)
    {
        cout<<temp->vertex<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int LinkedGraph :: AddAdj(char Vertex, char Vertex_edge)
{
    if(head == NULL)
    {
        cout<<endl<<"Graph is Empty! Add some vertices first."<<endl;
        return 0;
    }
    Node* temp1 = head;
    Node* temp2;
    while(temp1->vertex!=Vertex)
    {
        temp1 = temp1->next;
        if(temp1 == NULL)
        {
            cout <<endl << "No such Vertex " <<Vertex << " in the graph!" <<endl;
            return 0;
        }
    }
    if(temp1->adj == NULL)
    {
        Node* newnode = new Node(Vertex_edge);
        temp1->adj = newnode;
    }
    else
    {
        temp2 = temp1->adj;
        while(temp2->next!=NULL)
            temp2 = temp2->next;
        Node* newnode = new Node(Vertex_edge);
        temp2->next = newnode;
    }
}
int LinkedGraph :: ShowAdj(char Vertex)
{
    if(head == NULL)
    {
        cout<<endl<<"Graph is Empty! Add some vertices first."<<endl;
        return 0;
    }
    Node* ptr = head;
    while(ptr->vertex!=Vertex)
    {
        ptr = ptr->next;
        if(ptr == NULL)
        {
            cout <<endl << "No such Vertex " <<Vertex << " in the graph!" <<endl;
            return 0;
        }
    }
    if(ptr->adj == NULL)
    {
        cout <<endl << "No Adjecent of Vertex " <<Vertex << " is present in the graph!" <<endl;
        return 0;
    }
    cout<<endl<<Vertex<<"-> ";
    ptr = ptr->adj;
    while(ptr!=NULL)
    {
        cout<<ptr->vertex<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}


int main()
{
    LinkedGraph obj1;
    Node* n;
    int size1,size2,ch;
    char val,origin,adj_elem,x;

    cout<<"------------------ #MENU# ---------------------"<<endl;

    do
    {
        cout<<endl<<"1. Add Vertex"<<endl<<"2. Add Adjecent"<<endl<<"3. Show Vertices"<<endl<<"4. Show Adjecents"<<endl<<"5. Exit"<<endl<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            //cout<<endl<<"Enter Total No. Vertex to insert in Graph: ";
            //cin>>size1;
            cout<<"Enter Vertex Data: ";
            cin>>val;
            n = new Node(val);
            obj1.AddVertex(n);
            /*for(int i=0;i<size1;i++)
            {
                cin>>val;
                n = new Node(val);
                obj1.AddNode(n);
            }
            */
            break;
        case 2:
            cout<<endl<<"Insert Adjecent at: ";
            cin>>origin;
            //cout<<"Total Edge Elements to be inserted: ";
            //cin>>size2;
            cout<<"Enter Adjecent Data: ";
            cin>>adj_elem;
            obj1.AddAdj(origin,adj_elem);
            /*for(int i=0;i<size2;i++)
            {
                cin>>edge_elem;
                obj1.AddEdge(origin,edge_elem);
            }
            */
            break;
        case 3:
            obj1.ShowVertex();
            break;
        case 4:
            cout<<endl<<"Show Adjecent of: ";
            cin>>x;
            obj1.ShowAdj(x);
            break;
        }
    }while(ch!=5);
    return 0;
}
