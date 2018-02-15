//mano INICIJAVIMAS SUDETIS DAUGYBA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "adsDovis.h"

struct el {
	int data;
	struct el *next;                    
	};
	
// typedef struct el LIST;

void create_the_list(struct el **);
void insert_element_at_the_end(struct el **, int , int *);
void insert_element_at_the_beggining(struct el **, int , int *);
void creating_longint_as_a_list (struct el **, char [], int *);
void addition (struct el *, struct el *, struct el **, int *);
void main_addition(struct el *, struct el *, struct el **, int *);
void multiplication (struct el *, struct el *, struct el **, int *);
int length_of_longint (struct el *);
void displayList(struct el *);
void delete_list(struct el **);
int error (int );

int main ()
{
	char M[] = "9999";
	char M1[] = "1"; 
	struct el *longNumber;
	struct el *longNumber2;
	struct el *sum, *mul;
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

void create_the_list (struct el **head) 
{ 
	*head=NULL;
}

void insert_element_at_the_end(struct el **head, int n, int *fail) 
{
	struct el *temp;
	struct el *p;
	*fail = 0;
	
	temp=(struct el *)malloc(sizeof(struct el));
	
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

void insert_element_at_the_beggining(struct el **head, int n, int *fail) 
{
	struct el *temp;
	*fail = 0;
	
	temp=(struct el *)malloc(sizeof(struct el));
	
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

void creating_longint_as_a_list (struct el **head, char M[], int *fail)
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

int length_of_longint (struct el *a)                              //returns length of long int
{
	
	struct el *temp = a;
	int length = 0;
		
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	
	return length;
}

void main_addition (struct el *a, struct el *b, struct el **sum, int *fail)
{
	struct el *temp = a;
	struct el *temp2 = b;
	int length, length2, temp_lenght, i, sum1, overflow = 0, n;
	struct el *temp3;
	
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

void addition (struct el *longNumber, struct el *longNumber2, struct el **sum, int *fail)
{	
		
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
	// else
	// {
		
		// if ( longNumber->data == 0 )
		// {
			// subtraction(longNumber, longNumber2, sum);
		// }
		// else
		// {
			// subtraction(longNumber, longNumber2, sum);
		// }
		
	// }
	
}

void multiplication (struct el *a, struct el *b, struct el **mul, int *fail)
{
	struct el *temp ;
	struct el *temp2;
	struct el *temp3;
	struct el *x1;
	struct el *x2;
	struct el *x3;
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

void displayList(struct el *head) 
{
	struct el *p = head;
	
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

void delete_list (struct el **head)
{
	struct el *temp;
	
	while ((*head) != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		
		free(temp);
	}
	
}
