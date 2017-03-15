#include<stdio.h>
#include<stdlib.h>
unsigned int cnt=0,lim=0;
typedef struct st
{
	int Roll_no;
	char name[16];
	float marks;
	struct st *next;
}ST;
ST *hp=0;
void print(void);
void push(void);
void pop(void);
void add_beg(void);
void del_beg(void);
void del_stack(void);
main()
{
	int op;
	printf("enter the stack size:=");
	scanf("%d",&lim);
	do
	{
		printf("select the option  \n1>push\n2>pop\n3>print\n4>exit\n");
		scanf("%d",&op);
		if(op==1)
		{
			push();
		}
		else if(op==2)
		{
			pop();
		}
		else if(op==3)
		{
			print();
		}	
	}while(op==1||op==2||op==3);
	del_stack();
}
/////////////////////////////////////////////print linked list
void print()
{
	ST *p=hp;
	printf("roll no   name    marks\n");
	if(hp==0)
	{
	printf("no data in stack\n");
	return;
	}
	while(p)
	{
		printf("%d %15s %3.2f\n",(p)->Roll_no,(p)->name,(p)->marks);
		(p)=(p)->next;
	}
}
////////////////////////////////////////////push
void push(void)
{
	if(cnt==lim)
		printf("stack over-flow\n");
	else
		add_beg();
}
///////////////////////////////////////////pop
void pop(void)
{
	if(cnt==0)
		printf("stack under-flow\n");
	else
		del_beg();
}
///////////////////////////////////////////add_beg
void add_beg(void)
{
	ST *temp;
	////////////////////////////allocate dynamicaly memory
	temp=calloc(1,sizeof(ST));
	////////////////////////////add data frome user
	printf("enter the roll no:=");
	scanf("%d",&temp->Roll_no);
	printf("enter the name:=");
	scanf(" %s",temp->name);
	printf("enter the marks:=");
	scanf("%f",&temp->marks);
	////////////////////////////add_beg logic
	temp->next=hp;
	hp=temp;
	cnt++;
}
//////////////////////////////////////////del_beg logic
void del_beg(void)
{
	ST *temp;
	printf("roll no   name    marks\n");
	printf("%d %15s %3.2f\n",hp->Roll_no,hp->name,hp->marks);
	temp=hp;
	hp=hp->next;
	free(temp);
	cnt--;
}
//////////////////////////////////////////del stack
void del_stack(void)
{
	ST *p;
	printf("thank you\n");
	while(hp)
	{
		p=hp;
		hp=hp->next;
		free(p);
	}
}
