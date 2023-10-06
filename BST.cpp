#include <iostream>
#include <math.h>
#include<queue>
using namespace std;
class node{
public:
int data;
node* left;
node* right;

node(int data)
{
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};
//creating a bst
node* insertintobst(int data, node* root)
{
    //base case
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }

    //if the data is less than the root value than it goes to the left
    if(data<root->data)
    {
        root->left=insertintobst(data,root->left);
    }
    //agar mera data chota hai toh
    else
    {
        root->right=insertintobst(data,root->right);
    }
    return root;
}

void TakeInput(node* &root )
{
    int data;
    cin>>data;
    while (data!=-1)
    {
        root=insertintobst(data,root);
        cin>>data;
    }
}
void LevelOrderTraversal(node* root)
{
    
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
            q.push(temp->left);
            }
            if(temp->right)
            {
            q.push(temp->right);
            }
        }
    }
    
}
//binary tree search
bool searchinBST(node* root, int x)
{
    node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
        { return true;}
        if(temp->data>x)
        { temp=temp->left;}
        else{
            temp=temp->right;
        }
    }
    return false;
}

//through recussion
bool search(node* root, int x)
{
    //base case
    if(root==NULL)
    { return false;}
    if(root->data==x)
    { return true;}
    if(root->data>x)
    { return search(root->left,x);}
    else{
        return search(root->right,x);
    }
}


int main()
{
    node* root=NULL;
    cout<<"Enter data "<<endl;
    TakeInput(root);
    cout<<"Printing the tree"<<endl;
    LevelOrderTraversal(root);
    cout<<"Seaching in bst "<<searchinBST(root, 8)<<endl;
    return 0;
}