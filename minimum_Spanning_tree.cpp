#include <iostream>

struct node{
	int node_name;
	struct node *link[4];
	int weight [4];
}*head;

int add(int data,int *n)
{
	int i;
	if(head==NULL)
	{
		head=new node();
		head->node_name=data;
		i=0;
		while(i<4)
		{
			head->link[i++]=NULL;
		}
	}
}
