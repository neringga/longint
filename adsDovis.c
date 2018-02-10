#include<stdio.h>
#include<stdlib.h>
#include"ADS.h"

typedef struct el list;

int compare (list *a, list *b)
{
	int lenght_a=0,lenght_b=0,sign_a,sign_b,compare;
	list *aa, *bb;
	/*if(a->next==NULL||b->next==NULL)
	{
		printf("vienas is skaiciu nera inicijuotas\n");
		return;
	}*/
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
	if(sign_a&&!sign_b)//         kai zenklai skirtingi                    1(true)-Neigiamas, 0(false)-teigiamas
		return -1;
	if(!sign_a&&sign_b)
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

void subtraction (list *a, list *b, list **c)
{
	int q,sign_a,sign_b,lenght_a,lenght_b,overflow=0,i;
	list *aa,*bb,*temp;
	/*if(a==NULL||b==NULL)
	{
		printf("Vienas is sveiku skaiciu nera inicijuotas\n");
		return;
	}
	if(*c!=NULL)
	{
		printf("Atsakymo skaicius jau yra inicijuotas\n");
		return;
	}*/
	*c=NULL;
	sign_a=a->data;
	sign_b=b->data;
	if(sign_a==sign_b)//                                                 1(true)-Neigiamas, 0(false)-teigiamas
	{
		q=compare(a,b);
		if(q)
		{
			if(q<0)
			{
				temp=aa;
				aa=bb;
				bb=temp;
			}
			aa=a;
			bb=b;
			while(a->next!=NULL)
			{
				lenght_a++;
				a=a->next;
			}
			while(b->next!=NULL)
			{
				lenght_b++;
				b=b->next;
			}
			do
			{
				a=aa->next;
			 	b=bb->next;
				for(i=1;i<lenght_a;i++)
					a=a->next;				
				for(i=1;i<lenght_b;i++)
					b=b->next;		
				temp=malloc(sizeof(list));
				temp->data=a->data-b->data-overflow;
				overflow=0;
				if(temp->data<0)
				{
					temp->data=temp->data*-1;
					overflow=1;
				}
				temp->next=*c;
				*c=temp;
				lenght_a--;
				lenght_b--;
			}while(lenght_a&&lenght_b);
			if(lenght_a)
			{
				a=aa;
			 	for(i=1;i<lenght_a;i++)
			 		a=a->next;
				temp=malloc(sizeof(list));
				temp->data=a->data;
				temp->next=*c;
				*c=temp;
			}
			while((*c)->data==0)
			{
				temp=(*c)->next;
				free(*c);
				*c=temp;
			}
			temp=malloc(sizeof(list));
			temp->next=*c;
			*c=temp;
			if(q==1)
				(*c)->data=0;
			if(q==-1)
			{
				(*c)->data=1;
				temp=aa;
				aa=bb;
				bb=temp;
			}
		 }
		 else
		 {
			*c=malloc(sizeof(list));
			(*c)->data=0;
			(*c)->next=malloc(sizeof(list));
			(*c)->next->data=0;
			(*c)->next->next=NULL;
		 }
	}
	else//        tikrinama del c elemento zenklo ir kvieciama sudeties funkcija
	{
		if(sign_a)
		{
			b->data=1;
		}
		else
		{
			b->data=0;
		}
		addition(a,b,c)
	}
}