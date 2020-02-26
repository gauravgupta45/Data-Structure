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
        void Preorder(node* root)
        {
            if(root == NULL)
            {
                return;
            }
            cout<<root->data<<endl;
            Preorder(root->left);
            Preorder(root->right);
        }

        void Inorder(node* root)
        {
            if(root == NULL)
            {
                return;
            }
            Inorder(root->left);
            cout<<root->data<<endl;
            Inorder(root->right);
        }

        void Postorder(node* root)
        {
            if(root == NULL)
            {
                return;
            }
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
    cout<<endl<<"Content of Tree: "<<endl;
    cout<<endl<<"--------------# Pre-Order #--------------"<<endl;
    obj.Preorder(root);
    cout<<endl<<"--------------# In-Order #--------------"<<endl;
    obj.Inorder(root);
    cout<<endl<<"--------------# Post-Order #--------------"<<endl;
    obj.Postorder(root);
}
