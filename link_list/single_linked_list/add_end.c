#include<stdio.h>
#include<stdlib.h>
struct empl
{
	int id;
	char name[32];
	float sl;
	struct empl *next;
};
typedef struct empl EP;
void add_end(EP **ptr);
void print(EP *ptr);

main()
{
	char ch=0;
	EP *hp=0;
	do
	{
		add_end(&hp);
		printf("do u want to add another employe detail:= ");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');
	print(hp);
}

void add_end(EP **ptr)
{
	EP *temp,*temp1;
	temp=calloc(1,sizeof(EP));
//	temp=malloc(sizeof(EP));
	//////////////////////////////
	printf("enter the id:=");
	scanf("%d",&temp->id);
	printf("enter the name:=");
	scanf(" %s",temp->name);
	printf("enter the salary:=");
	scanf("%f",&temp->sl);
	/////////////////////////////
	if(*ptr==0)
	{
		temp->next = *ptr;
		*ptr=temp;
	}
	else
	{
		temp1 = *ptr;
		while(temp1->next)
			temp1 = temp1->next;

		temp->next = temp1->next;
		temp1->next = temp;
	}
}
void print(EP *ptr)
{
	while(ptr)
	{
		printf("%d %s %f\n",ptr->id,ptr->name,ptr->sl);
		ptr=ptr->next;
	}
}
