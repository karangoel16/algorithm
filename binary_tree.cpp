#include <iostream>
//including all the headers 
namespace std{
};

int search(int data,struct node *temp);
struct node {
	int data;
	struct node *left ;
	struct node *right;
}*root;

int add(int data,node *temp=root)
{
	if(root==NULL)
	{
		root= new node();
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		if(temp->data > data)
		{
			if(temp->left==NULL)
			{
				temp->left=new node();
				temp=temp->left;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				return 0;
			}
			else
			{
				add(data,temp->left);
			}
		}
		else if(temp->data==data)
		{
			std::cout<<"\ndata already exist\n";
			return 0;
		}
		else
		{
			if(temp->right==NULL)
			{
				//std::cout<<"*"<<data;
				temp->right=new node();
				temp=temp->right;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				return 0;
				
			}
			else
			{
				add(data,temp->right);
			}
		}
	}
	return 0;
}
int display()
{
	if(root==NULL)
	{
		std::cout<<"No data exist";
		return 0;
	}
	node *temp=root;
	while(temp!=NULL)
	{
		std::cout<<"\n"<<temp->data;
		temp=temp->left;
	}
}
int search(int data,struct node *temp=root)
{
	int t=1;
	if(root==NULL)
	{
		std::cout<<"No data entered error";
		return 0;
	}
	
	else
	{
		if(temp->data==data)
		{
			std::cout<<"Data has been found";
			return 1;
		}
		else
		{
			if(temp->left!=NULL && temp->data > data)
			{
				t=search(data,temp->left);
			}
			else if(temp->right !=NULL && temp->data<data )
			{
				t=search(data,temp->right);
			}
			if(t==0)
			{
				return 0;
			}
		}
	}
	return 0;
}

//int delete(int data,struct bo)
int main ()
{
	//the code is written here 

	//std::cout<<root->right->data;
	
	add(6);
	add(1);
	add(3);
	add(2);
	add(14);
	int t=search(1);
	std::cout<<t<<"\n";
	t=search(4);
		std::cout<<t<<"\n";
	display();
	return 0;
}
