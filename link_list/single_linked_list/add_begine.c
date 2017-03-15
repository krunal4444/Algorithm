#include<stdio.h>
#include<stdlib.h>
typedef struct emp
{
	int id;
	char name[32];
	float sl;
	struct emp *next;
}EP;
void print(EP *ptr);
void add_beg(EP **ptr);
int main()
{
	EP *hp=0;
	char op=0;
	do
	{
		add_beg(&hp);
		printf("do u want to add onother info of employ(y/n):=");
			scanf(" %c",&op);
	}while(op == 'Y' || op == 'y');
	print(hp);
}
void add_beg(EP **ptr)
{
	EP *temp;
	///////////////////////////
	temp=malloc(sizeof(EP));
	///////////////////////////
	printf("enter the id of employe:=");
	scanf("%d",&temp->id);
	printf("enter the employe name(max 32 char):=");
	scanf("%s",temp->name);
	printf("enter the employe salary:=");
	scanf("%f",&temp->sl);
	///////////////////////////
	temp->next=*ptr;
	*ptr=temp;
}

void print(EP *ptr)
{
	while(ptr)
	{
		printf("%d %s %f\n",ptr->id,ptr->name,ptr->sl);
		ptr=ptr->next;
	}
}
