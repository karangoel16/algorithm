//this code is written for hackerrank for AVL trees
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct node
{
int val;            //value
struct node* left;  //left child
struct node* right; //right child
int ht;             //height of the node
} node;
int height(struct node *root)
{
    //this is to find the height
    if(root==NULL)
    {
        return -1;
    }
    int left_ht=0;
    int right_ht=0;
    left_ht=abs(height(root->left));
    right_ht=abs(height(root->right));
    root->ht=left_ht-right_ht;
    if(left_ht>=right_ht)
        return left_ht+1;
    else
        return right_ht+1;
}
node * correction(struct node *root)
{
    if(root->ht==-2)
    {
        struct node *parent=root->right;
        if(parent==NULL)
        {
            cerr<<"This is not possible";
        }
        if(parent->ht==-1)
        {
            //this is rr case
            struct node * parent_child=parent->left;
            struct node * grand_child=parent->right;
            root->right=parent_child;
            parent->left=root;
            height(parent);
            return parent;
        }
        if(parent->ht==1)
        {
            //this is rl case
            struct node * parent_child=parent->right;
            struct node * child=parent->left;
            struct node * gc_right=child->right;
            struct node * gc_left=child->left;
            child->right=parent;
            parent->left=gc_right;
            child->left=root;
            root->right=gc_left;
            height(child);
            return child;
        }
    }
    else if(root->ht==2)
    {
        struct node *parent=root->left;
        if(parent==NULL)
        {
            cerr<<"this is not possible";
        }
        if(parent->ht==1)
        {
            //this is ll case
            struct node * parent_child=parent->right;
            struct node * child=parent->left;
            root->left=parent_child;
            parent->right=root;
            height(parent);
            return parent;
        }
        if(parent->ht==-1)
        {
            //this is lr case
            struct node * parent_child=parent->left;
            struct node * child=parent->right;
            struct node * gc_right=child->right;
            struct node * gc_left=child->left;
            child->left=parent;
            parent->right=gc_left;
            child->right=root;
            root->left=gc_right;
            height(child);
            return child;
        }
    }
    return root;
}
node *insert(node * root,int new_val)
{
    if(root==NULL)
    {
        root=new node();
        root->val=new_val;
        height(root);
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else
    {
        if(root->val<new_val)
        {
            root->right=insert(root->right,new_val);

        }
        else if(root->val>new_val)
        {
            root->left=insert(root->left,new_val);
        }
    }
    height(root);
    return correction(root);
}

int display(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    std::cout<<root->val<<"\t"<<root->ht<<"\n";
    display(root->right);
    display(root->left);
}
int main()
{
    node *head;
    head=NULL;
    head=insert(head,3);
    head=insert(head,2);
    head=insert(head,4);
    head=insert(head,5);
    head=insert(head,6);
    //head=insert(head,7);
    display(head);
    height(head);
    return 0;
}
