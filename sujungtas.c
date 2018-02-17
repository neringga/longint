//mano INICIJAVIMAS SUDETIS DAUGYBA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "adsDovis.h"

struct el {
	int data;
	struct el *next;                    
	};
	
typedef struct el list;

void create_the_list(list **); 
void insert_element_at_the_end(list **, int , int *);
void insert_element_at_the_beggining(list **, int , int *);
void creating_longint_as_a_list (list **, char [], int *);
void addition (list *, list *, list **, int *);
void main_addition(list *, list *, list **, int *);
void multiplication (list *, list *, list **, int *);
int length_of_longint (list *);
void displayList(list *);
void delete_list(list **);
int error (int );
void subtraction(list *, list *, list **);

int main ()
{
	char M[] = "1000";
	char M1[] = "-10000"; 
	list *longNumber;
	list *longNumber2;
	list *sum, *mul, *sub;
	int fail = 0;
	
	creating_longint_as_a_list(&longNumber, M, &fail);
	
	// if ( error(fail) )
		// return 1;
	
	creating_longint_as_a_list(&longNumber2, M1, &fail);
	
	// if ( error(fail) )
		// return 1;
	
	addition(longNumber, longNumber2, &sum, &fail);

	printf("Addition = ");
	displayList(sum);
	
	multiplication(longNumber, longNumber2, &mul, &fail);
	
	printf("\nMultiplication = ");
	displayList(mul);
	
	subtraction(longNumber, longNumber2, &sub);
	printf("\nDivision = ");
	displayList(sub);
	
	return 0;
}

// int error (int a)
// {
	// if (a)
	// {
		// printf("Error");
	// }
	// return 1;
// }

void create_the_list (list **head) 
{ 
	*head=NULL;
}

void insert_element_at_the_end(list **head, int n, int *fail) 
{
	list *temp;
	list *p;
	*fail = 0;
	
	temp=(list *)malloc(sizeof(list));
	
	if (temp == NULL)
	{
		*fail = 1;
	}
	else
	{
		temp->data = n ;
		temp->next = NULL;
		
		if (*head == NULL) {
			*head = temp;
		}
		else {
			p = *head;
			
			while (p->next != NULL) {
				p = p->next;
			}
			
			p->next = temp;
		}
	
	}
}

void insert_element_at_the_beggining(list **head, int n, int *fail) 
{
	list *temp;
	*fail = 0;
	
	temp=(list *)malloc(sizeof(list));
	
	if (temp == NULL)
	{
		*fail = 1;
	}
	else
	{
		temp->data = n;
		temp->next = *head;
	
		*head = temp;
	}
	
}

void creating_longint_as_a_list (list **head, char M[], int *fail)
{
	int i = 0;
	int first_zeros = 0;
	create_the_list(head);
	
	if ( M[i] == '-' )
	{	
		insert_element_at_the_end(head, 1, fail);			//first element of the list shows whether the number is negative or positive (1 for negative).
		i = 1;
	}
	else 
	{
		insert_element_at_the_end(head, 0, fail);			// 0 for positive
	}
	
	if (*fail == 1)
	{
		return;
	}
	
	while (i < strlen(M))																
	{
		if ( ((M[i] < 48) || (M[i] > 57)) && (M[i] != '-') )
		{
			*fail = 1;
			return;
		}
		else if ((M[i] != '0') || (first_zeros == 1) || ( i+1 == strlen(M)) || ((strlen(M) == 2) && (*M = '0')))         //when person enters number with zeros at the beggining
		{
			insert_element_at_the_end(head, M[i] - 48, fail);
			i++;
			first_zeros = 1;
		}
		else
		{
			i++;
			if (M[i] != '0')
			{
				first_zeros = 1;
			}
		}
	}
	
}

int length_of_longint (list *a)                              //returns length of long int
{
	
	list *temp = a;
	int length = 0;
		
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	
	return length;
}

void main_addition (list *a, list *b, list **sum, int *fail)
{
	list *temp = a;
	list *temp2 = b;
	int length, length2, temp_lenght, i, sum1, overflow = 0, n;
	list *temp3;
	
	create_the_list(sum);
	
	length = length_of_longint(a);
	length2 = length_of_longint(b);
	
	if (length < length2)                     //a has to be longer than b, length has to be longer than length2
	{
		temp3 = a;
		a = b;
		b = temp3;
		temp_lenght = length;
		length = length2;
		length2 = temp_lenght;
	}
	
	while ( (length !=1) && (length2 !=1) )
	{
		
		temp = a;
		temp2 = b;
		
		for (i=0; i<length-1; i++) 
		{
			temp = temp->next;
		}
		
		for (i=0; i<length2-1 ; i++)
		{
			temp2 = temp2->next;
		}
					
		sum1 = temp->data + temp2->data + overflow;
		overflow = 0;
		
		if (sum1 > 9)
		{
			overflow = 1;
			n = sum1 % 10;
		}
		else
		{
			// overflow = 0;
			n = sum1;
		}
		insert_element_at_the_beggining (sum, n, fail);
		
		if (*fail == 1)
		{
			return;
		}

		length--;
		length2--;
		
	}
	
	// if (overflow != 0)
		// {
			// insert_element_at_the_beggining(sum, overflow, fail);
		// }

	if (length != 1)
	{
		while (length != 1)
		{
			temp = a;
			
		for (i=0; i<length-1; i++) 
		{
			temp = temp->next;
		}
			
		sum1 = temp->data + overflow;
		
		if (sum1 == 10)
		{
			overflow = 1;
			n = 0;
		}
		else
		{
			overflow = 0;
			n = sum1;
		}
		insert_element_at_the_beggining(sum, n, fail);
		
		if (*fail == 1)
		{
			return;
		}
		
		length--;
		}
	}
	
	if (overflow != 0)
	{
		insert_element_at_the_beggining(sum, overflow, fail);
	}
	
}

void addition (list *longNumber, list *longNumber2, list **sum, int *fail)
{	
	list *temp;
		
	if ( (longNumber->data == 0) && (longNumber2->data == 0) || ((longNumber->data == 1) && (longNumber2->data == 1)) )
	{

		main_addition(longNumber, longNumber2, sum, fail);
		if (*fail == 1)
		{
			return;
		}
		
		if (longNumber->data == 0)
		{
			insert_element_at_the_beggining(sum, 0, fail);
		}
		else
		{
			insert_element_at_the_beggining(sum, 1, fail);
		}
		if (*fail == 1)
		{
			return;
		}
		
	}
	else
	{
		
		if ( longNumber->data == 0 )
		{
			longNumber2->data = 0;
			subtraction(longNumber, longNumber2, sum);
			longNumber2->data = 1;
		}
		else
		{
			// temp = longNumber;
			// longNumber = longNumber2;
			// longNumber2 = temp;
			longNumber->data = 0;
			subtraction(longNumber2, longNumber, sum);
			longNumber->data = 1;
			// insert_element_at_the_beggining(sum, 1, fail);
		}
		
	}
	
}

void multiplication (list *a, list *b, list **mul, int *fail)
{
	list *temp ;
	list *temp2;
	list *temp3;
	list *x1;
	list *x2;
	list *x3;
	int i, mul1, overflow = 0, n, length, length2, temp_length, m, m1, x;
	
	create_the_list(mul);
	
	temp = a->next;
	temp2 = b->next;
	
	length = length_of_longint(a);
	length2 = length_of_longint(b);
	
	if (length < length2)                     //a has to be longer than b, length has to be longer than length2
	{
		temp3 = a;
		a = b;
		b = temp3;
		temp_length = length;
		length = length2;
		length2 = temp_length;
	}
	
	m1 = length2 ;
	
	create_the_list(&x2);
	
	while (m1 != 1)                        //nes vienas elemntas nurodo skaiciaus zenkla
	{
		create_the_list(&x1);
		
		temp2 = b;
		
		for (i=0; i<m1 - 1; i++)
		{
			temp2 = temp2->next;
		}
		
		overflow = 0;
		m = length;
		
		while (m != 1)
		{
			temp = a;
			
			for (i=0; i<m - 1; i++)
			{
				temp = temp->next;
			}
			
			mul1 = temp->data * temp2->data + overflow;
			overflow = 0;
			
			if (mul1 > 9)
			{
				overflow = mul1 /10;
				n = mul1 % 10;
			}
			else
			{
				n = mul1;
			}
			
			insert_element_at_the_beggining (&x1, n, fail);
		
			if (*fail == 1)
			{
				return;
			}
			
			m--;
		}
		
		if (overflow != 0)
		{
			insert_element_at_the_beggining(&x1, overflow, fail);
		}
		
		if (m1 != length2)				//kadangi reiks padaugint kiekviena sk is atitinkamai desimt n-uoju, reikia tikrint koks n laipsnis
		{
			x = length2 - m1;
			
			for (i = 0; i<x; i++)
			{
				insert_element_at_the_end(&x1, 0, fail);
			}
		}
		
		if ((a->data == 1) || (b->data == 1))
		{
			insert_element_at_the_beggining(&x1, 1, fail); 
		}
		else
		{
			insert_element_at_the_beggining(&x1, 0, fail);
		}
		
		if (m1 == length2)
		{
			x2 = x1;

		}
		else 
		{
			addition(x1,x2,&x3,fail);
			x2 = x3;
		}

		m1--;
	}
	
	*mul = x2; 
	
}

void displayList(list *head) 
{
	list *p = head;
	
	if (p->data == 1)
	{
		printf("-");
		p = p->next;
	}
	else
	{
		p = p->next;
	}
	
	if (p == NULL) 
	{
		printf("Fail1");
	}
	else if (p->data == 0)
	{
		printf("%d", 0);
	}
	else 
	{
		
		while (p != NULL)
			{
			printf ("%d", p->data);
			p = p->next;
			}
			
	}
		
}

void delete_list (list **head)
{
	list *temp;
	
	while ((*head) != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		
		free(temp);
	}
	
}

int compare (list *a, list *b)
{
	int lenght_a=0,lenght_b=0,sign_a,sign_b,compare;
	list *aa, *bb;
	if(a==NULL||b==NULL)
		return 3;
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

int subtraction (list *a, list *b, list **c)
{
	int q=0,sign_a,sign_b,lenght_a=0,lenght_b=0,overflow=0,i, fail;
	list *aa,*bb,*temp;
	if(a==NULL||b==NULL)
		return 3;
	if(*c!=NULL)
		return 4;
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
				if(temp==NULL)
				{
					while(*c!=NULL)
					{
						temp=(*c)->next;
						free(*c);
						*c=temp;
					}
					return 1;
				}
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
				if(temp==NULL)
				{
					while(*c!=NULL)
					{
						temp=(*c)->next;
						free(*c);
						*c=temp;
					}
					return 1;
				}
				if(overflow)
				{
					temp->data=a->data-overflow;
					if(temp->data<0)
					{
						temp->data+=10;
						overflow=1;
					}
					else
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
			if(temp==NULL)
			{
				while(*c!=NULL)
				{
					temp=(*c)->next;
					free(*c);
					*c=temp;
				}
				return 1;
			}
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
			if(*c==NULL)
				return 1;
			(*c)->data=0;
			(*c)->next=malloc(sizeof(list));
			if((*c)->next==NULL)
			{
				free(*c);
				return 1;
			}
			(*c)->next->data=0;
			(*c)->next->next=NULL;
		 }
	}
	else//        tikrinama del c elemento zenklo ir kvieciama sudeties funkcija
	{
		if(sign_a)
		{
			b->data=1;
			q=addition(a,b,c,&fail);
			b->data=0;
			if(q)
				return q;
		}
		else
		{
			b->data=0;
			q=addition(a,b,c, &fail);
			b->data=1;
			if(q)
				return q;
		}
	}
}

int division(list *a, list *b, list **c, list **d)
{
	int q,sign_a,sign_b;
	list *quotient,*temp,*temp2;
	if(a==NULL||b==NULL)
		return 3;
	if(*c!=NULL||*d!=NULL)
		return 4;
	if(!b->next->data)
		return 2;
	if(!a->next->data)
	{
		*c=malloc(sizeof(list));
		if(*c==NULL)
			return 1;
		(*c)->data=0;
		(*c)->next=malloc(sizeof(list));
		if((*c)->next==NULL)
		{
			free (*c);
			return 1;
		}
		(*c)->next->data=0;
		(*c)->next->next=NULL;
		*d=malloc(sizeof(list));
		if(*d==NULL)
			return 1;
		(*d)->data=0;
		(*d)->next=malloc(sizeof(list));
		if((*d)->next==NULL)
		{
			free (*d);
			return 1;
		}
		(*d)->next->data=0;
		(*d)->next->next=NULL;
	}
	else
	{
		sign_a=a->data;
		sign_b=b->data;
		temp=malloc(sizeof(list));
		if(temp==NULL)
			return 1;
		*d=temp;
		temp->data=a->data;
		a=a->next;
		while(a!=NULL)
		{
			temp->next=malloc(sizeof(list));
			if(temp->next==NULL)
			{
				while(*d!=NULL)
				{
					temp=(*d)->next;
					free(*d);
					*d=temp;
				}
				return 1;
			}
			temp=temp->next;
			temp->data=a->data;
			a=a->next;
		}
		temp->next=NULL;
		(*d)->data=0;
		b->data=0;
		q=compare(*d,b);
		quotient=malloc(sizeof(list));
		if(quotient==NULL)
		{
			while(*d!=NULL)
			{
				temp=(*d)->next;
				free(*d);
				*d=temp;
			}
			return 1;
		}
		quotient->data=0;
		quotient->next=NULL;
		*c=quotient;
		while(q>=0)
		{
			(*c)->data++;
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
					if(quotient->next==NULL)
					{
						while(*d!=NULL)
						{
							temp=(*d)->next;
							free(*d);
							*d=temp;
						}
						while(*c!=NULL)
						{
							temp=(*c)->next;
							free(*c);
							*c=temp;
						}
						return 1;
					}
					quotient=quotient->next;
					quotient->data=1;
					quotient->next=NULL;
				}
			}
			q=0;
			q=subtraction(*d,b,&temp);
			if(q)
				return q;
			while(*d!=NULL)
			{
				temp2=(*d)->next;
				free(*d);
				*d=temp2;
			}
			*d=temp;
			q=compare(*d,b);
		}
		quotient=*c;
		*c=NULL;
		do
		{
			temp=malloc(sizeof(list));
			if(temp==NULL)
			{
				while(*d!=NULL)
				{
					temp=(*d)->next;
					free(*d);
					*d=temp;
				}
				while(*c!=NULL)
				{
					temp=(*c)->next;
					free(*c);
					*c=temp;
				}
				while(quotient!=NULL)
				{
					temp=quotient->next;
					free(quotient);
					quotient=temp;
				}
				return 1;
			}
			temp->next=*c;
			*c=temp;
			(*c)->data=quotient->data;
			temp=quotient->next;
			free(quotient);
			quotient=temp;
		}while(quotient!=NULL);
		temp=malloc(sizeof(list));
		if(temp==NULL)
		{
			while(*d!=NULL)
			{
				temp=(*d)->next;
				free(*d);
				*d=temp;
			}
			while(*c!=NULL)
			{
				temp=(*c)->next;
				free(*c);
				*c=temp;
			}
			return 1;
		}
		if(sign_a==sign_b)//                                                 1(true)-Neigiamas, 0(false)-teigiamas
		{
			temp->data=0;
			(*d)->data=0;
		}
		else
		{
			temp->data=1;
			(*d)->data=1;
		}
		temp->next=*c;
		*c=temp;
		b->data=sign_b;
	}
}
