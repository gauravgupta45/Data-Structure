#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <iterator>
#include <cmath>
using namespace std;

// int c = 1;                     // This is for directed and undirected graph operation
queue <char> f_q;
// In C++ programming, this is a keyword that refers to the current instance/object of the class. There can be 3 main usage of this keyword in C++.

// #1 It can be used to pass current object as a parameter to another method.
// #2 It can be used to refer current class instance variable.
// #3 It can be used to declare indexers.

// Here we are using this pointer to refer to current class instance variable.

// In BST, BFS is just a Level by Level Traversal, and DFS is just a Preorder Traversal

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
        char getname(Node* t)
        {
            return t->vertex;
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
        void ShowVertex();
        void AddAdj(char, char);
        void ShowAdj(char);
        void bfs();
        void dfs();
};

void LinkedGraph :: AddVertex(Node* newnode)
{
    if(head == NULL)
        head = newnode;
    else
    {
        Node* temp = new Node;
        temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = newnode;
    }
}

void LinkedGraph :: ShowVertex()
{
    if(head == NULL)
    {
        cout << endl << "Graph is Empty! Add some vertices first." << endl;
        return;
    }
    cout << endl << "Nodes of Graph are: ";
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->vertex << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedGraph :: AddAdj(char Vertex, char Vertex_edge)
{
    if(head == NULL)
    {
        cout <<endl <<"Graph is Empty! Add some vertices first." << endl;
        return;
    }
    Node* temp1 = head;
    Node* temp2;
    while(temp1->vertex!=Vertex)
    {
        temp1 = temp1->next;
        if(temp1 == NULL)
        {
            cout << endl << "No such Vertex " << Vertex << " in the graph!" << endl;
            return;
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
    // Uncomment the followed line if you want the graph to be undirected. (Use it when w/o menu interface.)
//         if(c==1)
//     {
//         c++;
//         AddAdj(Vertex_edge,Vertex);
//         c--;
//     }

}

void LinkedGraph :: ShowAdj(char Vertex)
{
    if(head == NULL)
    {
        cout << endl << "Graph is Empty! Add some vertices first."<< endl;
        return;
    }
    Node* ptr = head;
    while(ptr->vertex != Vertex)
    {
        ptr = ptr->next;
        if(ptr == NULL)
        {
            cout << endl << "No such Vertex " << Vertex << " in the graph!" << endl;
            return;
        }
    }
    if(ptr->adj == NULL)
    {
        cout <<endl << "No Adjecent of Vertex " << Vertex << " is present in the graph!" << endl;
        return;
    }
    ptr = ptr->adj;
    cout << endl << "Adjecent of " << Vertex << " -> ";
    while(ptr!=NULL)
    {
        cout << ptr->vertex << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void LinkedGraph :: bfs()
{
    // Get the number of vertices (n) in Graph, so that we can create a queue of that size.
    int n = 0;
    Node* ptrforsize = head;
    while(ptrforsize != NULL)
    {
        ptrforsize = ptrforsize->next;
        n++;
    }
    int visited[n] = {0};

    // Getting the user defined start point.
    char start_data;
    cout << endl << "Enter Starting Vertex: ";
    cin >> start_data;
    // Inserting the start vertex in the queue.
    f_q.push(start_data);

    // Find the index of current vertex, so that we can mark it visited in visited array.
    Node* ptrforindex = head;
    int index = 0;
    while(ptrforindex->vertex != start_data)
    {
        ptrforindex = ptrforindex->next;
        index++;
    }
    visited[index] = 1;

    // Traversing the whole graph from the start node, which user entered, untill the queue becomes empty.
    cout << endl << "BFS traversal is: ";
    while(!f_q.empty())
    {
        Node* ptrforvertex = head;
        cout << f_q.front() << " ";

        while(ptrforvertex->vertex != f_q.front())
            ptrforvertex = ptrforvertex->next;

        //Removing the front elem as we have now address of its adj elemnts.
        f_q.pop();

        // Traversing through the adjecent of front elem of queue considering it has atleast 1 adj. And put all its adj to the queue and there index too in visited array.
        ptrforvertex = ptrforvertex->adj;
        while(ptrforvertex != NULL)
        {
            // Finding the index of current vertex, so that we can put it into visited array. Basically we are providing each node an index, which can be used to diffrentiate them.
            ptrforindex = head;
            index = 0;
            while(ptrforindex->vertex != ptrforvertex->vertex)
            {
                index++;
                ptrforindex = ptrforindex->next;
            }

            // Checking if the index of current elem that we got from above, is in the visited arr or not.
            if(visited[index] == 0)
            {
                visited[index] = 1;
                f_q.push(ptrforvertex->vertex);
            }
            ptrforvertex = ptrforvertex -> next;
        }
    }
    cout << endl;
}


void LinkedGraph :: dfs()
{
    cout << endl << "Wait for few days :)" << endl;
}


int main()
{
    LinkedGraph obj1;
    Node* n;

    cout<<"------------------ #MENU# ---------------------"<<endl;
    int ch;
    do
    {

    char val,origin,adj_elem,x;
        cout<<endl<<"1. Add Vertex"<<endl<<"2. Add Adjecent"<<endl<<"3. Show Vertices"<<endl<<"4. Show Adjecents"<<endl<<"5. BFS Traversal"<<endl<<"6. DFS Traversal"<<endl<<"7. Exit"<<endl<<endl;
        cin >> ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter Vertex Data: ";
            cin >> val;
            n = new Node(val);
            obj1.AddVertex(n);
            break;

        case 2:
            cout<<endl<<"Insert Adjecent at: ";
            cin >> origin;
            cout << "Enter Adjecent Data: ";
            cin >> adj_elem;
            obj1.AddAdj(origin,adj_elem);
            obj1.AddAdj(adj_elem,origin);       // This is done to make the graph directed.
            break;

        case 3:
            obj1.ShowVertex();
            break;

        case 4:
            cout<<endl<<"Show Adjecent of: ";
            cin>>x;
            obj1.ShowAdj(x);
            break;

        case 5:
            cout << endl << "BFS Traversal is :"<< endl;
            obj1.bfs();
            break;

        case 6:
            cout << endl << "DFS Traversal is :"<< endl;
            obj1.dfs();
            break;
        }
    }while(ch!=7);

    // n = new Node('H');
    // obj1.AddVertex(n);
    // n = new Node('B');
    // obj1.AddVertex(n);
    // n = new Node('D');
    // obj1.AddVertex(n);
    // n = new Node('M');
    // obj1.AddVertex(n);
    //
    // obj1.AddAdj('H','B');
    // obj1.AddAdj('H','M');
    // obj1.AddAdj('H','D');
    //
    // obj1.ShowVertex();
    //
    // obj1.ShowAdj('H');
    // obj1.ShowAdj('B');
    // obj1.ShowAdj('D');
    // obj1.ShowAdj('M');
    //
    // obj1.bfs();

    return 0;
}
