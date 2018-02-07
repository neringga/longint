#include<stdio.h>
#include<stdlib.h>
#include"suma.h"

struct list{
	int el;
	struct list *kitas;
};

void atimtis(list *a, list *b, list **c)
{
	int atimtis,perpildymas=0;
	list *laikinas;
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
	*c=malloc(sizeof(list));
	laikinas=*c;
	do{
	}while(a->kitas!=NULL&&b->kitas!=NULL);
	
}