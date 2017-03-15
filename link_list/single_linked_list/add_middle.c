#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	int roll_no;
	char name[10];
	float marks;
	struct st *next;
}ST;

void print(ST *ptr);
void add_mid(ST **ptr);
main()
{
	char op;
	ST *hp=0;
	do
	{
		add_mid(&hp);
		printf("do u want to add onother student detail(y/n):-");
		scanf(" %c",&op);
	}while(op == 'y' || op == 'Y');
	print(hp);
}

void add_mid(ST **ptr)
{
	ST *temp,*temp1;
	temp1=*ptr;
	temp=calloc(1,sizeof(ST));
	/////////////////////////////
	printf("enter the roll no:=");
	scanf("%d",&temp->roll_no);
	printf("enter the name:- ");
	scanf(" %s",temp->name);
//	gets(ptr->name);
	printf("enter the marks:= ");
	scanf("%f",&temp->marks);
	/////////////////////////////
	if(*ptr==0 || temp1->roll_no > temp->roll_no)
	{
		temp->next = *ptr;
		*ptr = temp;
	}
	else
	{
		temp1=*ptr;
		while(temp1)
		{
			if(temp1->next ==0 || temp->roll_no < temp1->next->roll_no )
			{
				temp->next=temp1->next;
				temp1->next = temp;
				break;
			}
			temp1=temp1->next;
		}
	}
}
void print(ST *ptr)
{
	while(ptr)
	{
		printf("%d %s %f\n",ptr->roll_no,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}
