//left
//dll_queue
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
void en_queue(void);
void de_queue(void);
void add_end(void);
void del_beg(void);
void del_queue(void);
main()
{
	int op;
	printf("enter the queue size:=");
	scanf("%d",&lim);
	do
	{
		printf("select the option  \n1>en_queue\n2>de_queue\n3>print\n4>exit\n");
		scanf("%d",&op);
		if(op==1)
		{
			en_queue();
		}
		else if(op==2)
		{
			de_queue();
		}
		else if(op==3)
		{
			print();
		}	
	}while(op==1||op==2||op==3);
	del_queue();
}
/////////////////////////////////////////////print linked list
void print()
{
	ST *p=hp;
	printf("roll no   name    marks\n");
	if(hp==0)
	{
	printf("no data in queue\n");
	return;
	}
	while(p)
	{
		printf("%d %15s %3.2f\n",(p)->Roll_no,(p)->name,(p)->marks);
		(p)=(p)->next;
	}
}
////////////////////////////////////////////push
void en_queue(void)
{
	if(cnt==lim)
		printf("queue is full\n");
	else
		add_end();
}
///////////////////////////////////////////pop
void de_queue(void)
{
	if(cnt==0)
		printf("queue is empty\n");
	else
		del_beg();
}
///////////////////////////////////////////add_beg
void add_end(void)
{
	ST *temp,*temp1;
	////////////////////////////allocate dynamicaly memory
	temp=calloc(1,sizeof(ST));
	////////////////////////////add data frome user
	printf("enter the roll no:=");
	scanf("%d",&temp->Roll_no);
	printf("enter the name:=");
	scanf(" %s",temp->name);
	printf("enter the marks:=");
	scanf("%f",&temp->marks);
	////////////////////////////add_end logic
	if(hp==0)
	{
	temp->next=hp;
	hp=temp;
	cnt++;
	}
	else
	{
	temp1=hp;

	while(temp1->next)
	temp1=temp1->next;

	temp->next=temp1->next;
	temp1->next=temp;
	cnt++;
	}
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
void del_queue(void)
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
