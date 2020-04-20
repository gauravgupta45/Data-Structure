#include <iostream>
using namespace std;

struct Node
{
    char vertex;
    Node* adj;
    Node* next;
};

class LinkedGraph
{
    private:
        Node* head;
    public:
        LinkedGraph()
        {
            head = NULL;
        }

        void AddVertex(char);
        int ShowVertex();
        int AddAdj(char,char);
        int ShowAdj(char);
};

void LinkedGraph :: AddVertex(char Vertex)
{
    Node* newnode = new Node;
    newnode->vertex = Vertex;
    if(head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        newnode->adj = NULL;
    }

    else
    {
        Node* temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->adj = NULL;
        newnode->next = NULL;
    }
}

int LinkedGraph :: ShowVertex()
{
    Node* ptr = head;
    if(ptr == NULL)
    {
        cout<<endl<<"Graph is Empty! Add some vertices first."<<endl;
        return 0;
    }
    cout<<endl<<"Vertices present in Graph are: ";
    while(ptr!=NULL)
    {
        cout<<endl<<ptr->vertex<<" ";
        ptr = ptr->next;
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
    Node* newnode = new Node;
    newnode->vertex = Vertex_edge;
    newnode->next = NULL;
    newnode->adj = NULL;
    while(temp1->vertex!=Vertex)
    {
        temp1 = temp1->next;
        if(temp1 == NULL)
        {
            cout <<endl << "No such Vertex " <<Vertex << " in the graph!" <<endl;
            return 0;
        }
    }
    // If compiler get out from above while loop and executes following it means vertex has been found

    if(temp1->adj == NULL)
    {
        temp1->adj = newnode;
    }
    else
    {
        temp2 = temp1->adj;
        while(temp2->next != NULL)
            temp2 = temp2->next;
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
    ptr = ptr->adj;
    cout<<endl<<Vertex<<"-> ";
    while(ptr!=NULL)
    {
        cout<<ptr->vertex<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main()
{
    LinkedGraph obj;
    obj.AddVertex('A');
    obj.AddVertex('B');
    obj.AddVertex('C');
    obj.AddVertex('D');
    obj.ShowVertex();

    obj.AddAdj('A','B');
    obj.AddAdj('A','C');
    obj.AddAdj('A','D');
    obj.AddAdj('Z','B');
    obj.ShowAdj('A');
    obj.ShowAdj('B');
    obj.ShowAdj('Z');
    return 0;
}
