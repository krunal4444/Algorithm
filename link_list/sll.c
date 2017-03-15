#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	unsigned int num;
	struct st *next;
}ST;

void print(ST *p);
void add_beg(ST **ptr);
void add_end(ST **ptr);
void add_mid(ST **ptr);
int count(ST *p);
void delete(ST **ptr, int n);

int main(void)
{
	ST *hp = 0;
	char ch = 0;
	int i = 0;
	do{
//		add_beg(&hp);
//		add_end(&hp);
		add_mid(&hp);
				
		printf("Do you want to delete node enter the node:= ");
		scanf(" %u", &i);
		if(i != 0)
		delete(&hp, i);
		printf("Do you want to continue(Y/N):= ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
	print(hp);
	return (0);
}

void print(ST *p)
{
	while(p)
	{
		printf("%u\n", p -> num);
		p = p -> next;
	}
}

int count(ST *p)
{
	while(p)
	{
		printf("%u\n", p -> num);
		p = p -> next;
	}
}

void add_beg(ST **ptr)
{
	ST *temp;
	//allocating memory
	temp = (ST *)malloc(sizeof(ST));
	//take a data
	printf("enter the number:= ");
	scanf(" %u", &temp -> num);
	//add at the begin
	temp -> next = *ptr;
	*ptr = temp;
}

void add_end(ST **ptr)
{
	ST *temp, *temp1;
	//allocating memory
	temp = (ST *)malloc(sizeof(ST));
	//take a data
	printf("enter the number:= ");
	scanf(" %u", &temp -> num);
	//add at the end

	if(0 == *ptr)
	{
		temp -> next = *ptr;
		*ptr = temp;
	}
	else
	{
		temp1 = *ptr;
		while(temp1 -> next)
			temp1 = temp1 -> next;

		temp -> next = temp1 -> next;
		temp1 -> next = temp;
	}
}

void add_mid(ST **ptr)
{
	ST *temp, *temp1;
	//allocating memory
	temp = (ST *)malloc(sizeof(ST));
	//take a data
	printf("enter the number:= ");
	scanf(" %u", &temp -> num);
	//add at the end

	if(0 == *ptr || temp -> num < (*ptr) -> num)
	{
		temp -> next = *ptr;
		*ptr = temp;
	}
	else
	{
		temp1 = *ptr;
		while(temp1)
		{
			if(0 == temp1 -> next || temp1 -> next -> num > temp -> num)
			{
				temp -> next = temp1 -> next;
				temp1 -> next = temp;
				break;
			}
			temp1 = temp1 -> next;
		}
	}
}

void delete(ST **ptr, int n)
{
	ST *temp, *temp1;
	temp = *ptr;
	while (temp)
	{
		if (n == temp -> num)
		{
			if (temp == *ptr)
			{
				*ptr = temp -> next;
				free(temp);
				return;
			}
			else
			{
				temp1 -> next = temp -> next;
				free(temp);
				return;
			}
		}
		temp1 = temp;
		temp = temp -> next;
	}
}
