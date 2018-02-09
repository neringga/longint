#include<stdio.h>
#include"palyginimas.h"

struct el{
	int data;
	struct el *next;
};

typedef struct el list;

int palyginimas (list *a, list *b);

int main ()
{
	int i;
	list *a,*b;
	i=palyginimas(a,b);
	return 0;
}

int palyginimas (list *a, list *b)
{
	int lenght_a=0,lenght_b=0,sign_a,sign_b,compare;
	list *aa, *bb;
	if(a==NULL||b==NULL)
	{
		printf("vienas is skaiciu nera inicijuotas\n");
		return;
	}
	aa=a;
	bb=b;
	sign_a=a->data;
	while(a->next!=NULL)
	{
		lenght_a++;
		a=a->next;
	}
	sign_b=b->data;
	while(b->next!=NULL)
	{
		lenght_b++;
		b=b->next;
	}
	if(sign_a&&sign_b)//         kai zenklai skirtingi                    1(true)-Neigiamas, 0(false)-teigiamas
		return -1;
	if(!sign_a&&!sign_b)
		return 1;
	if(!sign_a&&!sign_b)//       kai zenklai vienodi, bet skirtingi igiai
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
	aa=aa->next;
	bb=bb->next;
	compare=aa->data-bb->data;
	while(!compare&&aa!=NULL&&bb!=NULL)//       kai ilgiai ir zenklai vienodi
	{
		compare=aa->data-bb->data;
		aa=aa->next;
		bb=bb->next;
	}
	if(compare>0)
		return 1;
	if(compare<0)
		return -1;
	return 0;
}