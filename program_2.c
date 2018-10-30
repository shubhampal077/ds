#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <assert.h> 
struct node  
{ 
  int data; 
  struct node *next; 
}; 
  
// This function prints contents of linked list starting from  
// the given node 
void printlist(struct node *n) 
{ 
	if(n==NULL)
	{
		printf("list is empty\n");
		return;
	}
  while (n != NULL) 
  { 
     printf(" %d ", n->data); 
     n = n->next; 
  } 
  printf("\n");
} 
void push(struct node** head_ref,int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}
void insertafter(struct node** head_ref,int item,int new_data)
{
	struct node *p,*tmp;
	p=(*head_ref);
	while(p!=NULL)
    {
 
        if(p->data==item)
        {
 
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->data=new_data;
            tmp->next=p->next;
            p->next=tmp;
            return;
        }
        p=p->next;
    }
    printf("item not found\n");
}
void append(struct node** head_ref,int new_data)
{
	struct node *p,*tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=new_data;
	p=(*head_ref);
	if(p==NULL)
	{
		*head_ref=tmp;
		tmp->next=NULL;
		return;
	}
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=tmp;
	tmp->next=NULL;
	
}
void delete(struct node **head_ref,int key)
{
	struct node *tmp,*p;
	p=*head_ref;
	if(p==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(p->next!=NULL)
	{
		if(p->next->data==key)
		{
			tmp=p->next;
			p->next=tmp->next;
			free(tmp);
		}
		p=p->next;
	}
}
void deleteafter(struct node **head_ref,int pos)
{
	struct node *tmp,*p;
	int i;
	p=*head_ref;
	if(pos==1)
	{
		(*head_ref)=p->next;
		free(p);
		return;
	}
	for(i=1;p!=NULL && i<=pos-2;i++)
	{
		p=p->next;
	}
	if(p==NULL || p->next==NULL)
	{
		printf("position is more than no. of nodes\n");
		return;
	}
	tmp=p->next;
	p->next=tmp->next;
	free(tmp);
}
void deletelist(struct node **head_ref)
{
	struct node *current=(*head_ref);
	struct node *next;
	while(current!=NULL)
	{
		next=current->next;
		free(current);
		current=next;
	}
	*head_ref=NULL;
}
int getcounti(struct node *head)//iterative
{
	int count=0;
	struct node *current=head;
	while(current!=NULL)
	{
		count++;
		current=current->next;
	}
	return count;
}
int getcountr(struct node *head)
{
	if(head==NULL)
		return 0;
    else 
    return (1+getcountr(head->next));
}
bool searchi(struct node *head,int x)
{
	struct node *current=head;
	while(current!=NULL)
	{
		if(current->data==x)
			return true;
		current=current->next;
	}
	return false;
}
bool searchr(struct node *head,int x)
{
	if(head==NULL)
		return false;
	if(head->data==x)
		return true;
	return searchr(head->next,x);	
}
int getnthi(struct node *head,int index)
{
	struct node *current=head;
	int count =1;
	while(current!=NULL)
	{
		if(count==index)
			return current->data;
		count++;
		current=current->next;
	}
	printf("there are lesser elements than index\n");
}
int getnthr(struct node *head,int n)
{
	if(n==1)
		return head->data;
	return getnthr(head->next,n-1);
}
int main()
{
	int x=6;
	struct node* head=NULL;
	append(&head,6);
	push(&head,7);
	push(&head,1);
	append(&head,4);
	insertafter(&head,7,9);
	printlist(head);
	delete(&head,7);
	append(&head,2);
	//printf("no of elements is : %d\n",getcountr(head));
	deleteafter(&head,5);
	//printf("no of elements is : %d\n",getcountr(head));
	printlist(head);
	//searchr(head,x)?printf("yes"):printf("no");
	printf("element at 3 rd index is : %d\n",getnthr(head,4));
	return 0;
}
