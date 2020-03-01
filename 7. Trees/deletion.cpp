#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};


class A
{
    public:
        node* insert(node* root, int val)
        {
            if(root == NULL)
            {
                root = new node();
                root->data = val;
                root->left = NULL;
                root->right = NULL;
            }

            else if(val <= root->data)
                root->left = insert(root->left,val);
            else
                root->right = insert(root->right,val);
            return root;
        }

        node* largest_node(node* root)
        {
            if(root == NULL || root->right == NULL)
                return root;
            else
                return largest_node(root->right);
        }
        void delete_node(node* root,int val)
        {
            node* temp = new node();
            if(root == NULL)
            {
                cout<<"Value not Found!"<<endl;
                return;
            }
            else if(val < root->data)
                delete_node(root->left,val);
            else if(val > root->data)
                delete_node(root->right,val);

            else if(root->left && root->right)                  //case in which node has two child
            {
                temp = largest_node(root->left);
                root->data = temp->data;
                delete_node(root->left,temp->data);
            }

            else                                                //case in which node has one or no child
            {
                if(root->left == NULL && root->right == NULL)   //no child
                    root = NULL;
                else if(root->left != NULL)                     //either left child
                    root->left = NULL;
                else                                            //or right child only
                    root->right = NULL;
            }
            delete temp;
        }
        void Preorder(node* root)
        {
            if(root == NULL)
                return;
            cout<<root->data<<endl;
            Preorder(root->left);
            Preorder(root->right);
        }

        void Inorder(node* root)
        {
            if(root == NULL)
                return;
            Inorder(root->left);
            cout<<root->data<<endl;
            Inorder(root->right);
        }

        void Postorder(node* root)
        {
            if(root == NULL)
                return;
            Postorder(root->left);
            Postorder(root->right);
            cout<<root->data<<endl;
        }

};


int main()
{
    A obj;
    int n,val;
    node* root = NULL;
    cout<<"Enter Tree Size:"<<endl;
    cin>>n;
    cout<<"Enter Data:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        root = obj.insert(root,val);
    }

    int del_val;
    cout<<endl<<"Enter Value to be Deleted: "<<endl;
    cin>>del_val;
    obj.delete_node(root,del_val);
    cout<<endl<<"Content of Tree: "<<endl;
    cout<<endl<<"--------------# Pre-Order #--------------"<<endl;
    obj.Preorder(root);
    cout<<endl<<"--------------# In-Order #--------------"<<endl;
    obj.Inorder(root);
    cout<<endl<<"--------------# Post-Order #--------------"<<endl;
    obj.Postorder(root);




}
