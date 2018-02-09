#include<stdio.h>
#include"palyginimas.h"

struct el{
	int data;
	struct el *next;
};

typedef struct el list;

int palyginimas (list *a, list *b)
{
	int lenght_a=0,lenght_b=0,sign_a,sign_b;
	list *aa, *bb;
	if(a==NULL||b==NULL)
	{
		printf("vienas is skaiciu nera inicijuotas\n");
		return;
	}
	aa=a;
	bb=b;
	sign_a=a->el;
	while(a->next!=NULL)
	{
		lenght_a++;
		a=a->next;
	}
	sign_b=b->el;
	while(b->next!=NULL)
	{
		lenght_b++;
		b=b->next;
	}
	if(sign_a&&sign_b)//         1(true)-Neigiamas, 0(false)-teigiamas
		return -1;
	if(!sign_a&&!sign_b)
		return 1;
	if(!sign_a&&!sign_b)
	{
		if(lenght_a>lenght_b)
			return 1;
		if(lenght_a<lenght_b)
			return -1;
	}
	if(sign_a&&sign_b)
	{
		if(lenght_a>lenght_b)
			return -1;
		if(lenght_a<lenght_b)
			return 1;
	}
	if(!sign_a&&!sign_b)//liko tik atvejai kai ilgiai ir zenklai vienodi
	{
		
	}
}