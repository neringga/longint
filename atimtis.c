#include<stdio.h>
#include<stdlib.h>
#include"suma.h"

struct el{
	int data;
	struct el *next;
};

typedef struct el list;

void atimtis(list *a, list *b, list **c)
{
	if(a==NULL||b==NULL)
	{
		printf("Vienas is sveiku skaiciu nera inicijuotas\n");
		return;
	}
	if(*c!=NULL)
	{
		printf("Atsakymo skaicius jau yra inicijuotas\n");
		return;
	}
	
}