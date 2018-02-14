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
	if(compare>0&&!sign_a)
		return 1;
	if(compare>0&&sign_a)
		return -1;
	if(compare<0&&!sign_a)
		return -1;
	if(compare<0&&sign_a)
		return 1;
	return 0;
}

void subtraction (list *a, list *b, list **c)
{
	int q,sign_a,sign_b,lenght_a=0,lenght_b=0,overflow=0,i;
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
		a->data=0;
		b->data=0;
		q=compare(a,b);
		a->data=sign_a;
		b->data=sign_b;
		if(q)
		{
			if(q<0)
			{
				temp=a;
				a=b;
				b=temp;
			}
			aa=a;
			bb=b;
			while((a=a->next)!=NULL)
				lenght_a++;
			while((b=b->next)!=NULL)
				lenght_b++;
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
					temp->data=temp->data+10;
					overflow=1;
				}
				temp->next=*c;
				*c=temp;
				lenght_a--;
				lenght_b--;
			}while(lenght_b);
			while(lenght_a)
			{
				a=aa->next;
			 	for(i=1;i<lenght_a;i++)
					a=a->next;
				temp=malloc(sizeof(list));
				if(overflow)
				{
					temp->data=a->data-overflow;
					overflow=0;
				}
				else
					temp->data=a->data;
				temp->next=*c;
				*c=temp;
				lenght_a--;
			}
			while((*c)->data==0)
			{
				temp=*c;
				*c=temp->next;
				free(temp);
			}
			temp=malloc(sizeof(list));
			temp->next=*c;
			*c=temp;
			if(q==1&&!sign_a)
				(*c)->data=0;
			if(q==1&&sign_a)
				(*c)->data=1;
			if(q==-1&&!sign_a)
				(*c)->data=1;
			if(q==-1&&sign_a)
				(*c)->data=0;
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
			addition(a,b,c);
			b->data=0;
		}
		else
		{
			b->data=0;
			addition(a,b,c);
			b->data=1;
		}
	}
}

int division(list *a, list *b, list **c, list **d)
{
	int q,sign_a,sign_b;
	list *quotient,*temp;
	if(!b->next->data)
	{
		return 1;
	}
	if(!a->next->data)
	{
		*c=malloc(sizeof(list));
		(*c)->data=0;
		(*c)->next=malloc(sizeof(list));
		(*c)->next->data=0;
		(*c)->next->next=NULL;
		*d=malloc(sizeof(list));
		(*d)->data=0;
		(*d)->next=malloc(sizeof(list));
		(*d)->next->data=0;
		(*d)->next->next=NULL;
	}
	else
	{
		sign_a=a->data;
		sign_b=b->data;
		temp=malloc(sizeof(list));
		*d=temp;
		temp->data=a->data;
		temp=temp->next;
		a=a->next;
		while(a!=NULL)
		{
			temp=malloc(sizeof(list));
			temp->data=a->data;
			temp=temp->next;
			a=a->next;
		}
		(*d)->data=0;
		b->data=0;
		q=compare(*d,b);
		quotient=malloc(sizeof(list));
		quotient->data=0;
		quotient->next=NULL;
		*c=quotient;
		while(q>=0)
		{
			if((*c)->data==10)
			{
				quotient=*c;
				while(quotient->next!=NULL&&quotient->data==10)
				{
					quotient->data=0;
					quotient=quotient->next;
					quotient->data++;
				}
				if(quotient->next==NULL&&quotient->data==10)
				{
					quotient->data=0;
					quotient->next=malloc(sizeof(list));
					quotient=quotient->next;
					quotient->data=1;
					quotient->next=NULL;
				}
			}
			(*c)->data++;
			subtraction(*d,b,&temp);
			while(*d!=NULL)
			{
				free(*d);
				*d=(*d)->next;
			}
			*d=temp;
			q=compare(*d,b);
		}
		quotient=*c;
		*c=NULL;
		do
		{
			temp=malloc(sizeof(list));
			temp->next=*c;
			*c=temp;
			(*c)->data=quotient->data;
			free(quotient);
			quotient=quotient->next;
		}while(quotient!=NULL);
		temp=malloc(sizeof(list));
		if(sign_a==sign_b)//                                                 1(true)-Neigiamas, 0(false)-teigiamas
			temp->data=0;
		else
			temp->data=1;
		temp->next=*c;
		*c=temp;
	}
	return 0;
}
