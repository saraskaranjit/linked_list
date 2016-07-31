//Program to implement linked list
//By : Saras Karanjit
//Date : 31/7/2016
//Ref : Data Structure using C and C++

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr *,int);
int deletefromfront(nodeptr *);
void displaylist(nodeptr);

int main()
{
	nodeptr p;
    p=NULL;
    insertatfirst(&p,5);
    insertatfirst(&p,6);
    insertatfirst(&p,7);  
    displaylist(p);
    printf("--\n");
	printf("%d\n",deletefromfront(&p));
	printf("--\n");
	printf("%d\n",deletefromfront(&p));
	printf("--\n");
	printf("%d\n",deletefromfront(&p));
    printf("--\n");
	printf("%d\n",deletefromfront(&p));	  
    displaylist(p); 
}

nodeptr getnode()
{
	return (nodeptr)malloc(sizeof(struct node));
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr*p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	nodeptr ptr=p;
	while(ptr!=NULL)
	{
		printf("|\t");
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
	printf("|\n");
}

int deletefromfront(nodeptr *p)
{    
	int x;
	if (*p==NULL)
	{
		printf("List Underflow!\n");
		exit(0);
	}else
	{
		nodeptr q;
	    q=*p;
	    *p=q->next;
	    x=q->info;
	    freenode(q);
		return x;    
	}	
}
