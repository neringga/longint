//mano INICIJAVIMAS SUDETIS DAUGYBA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct el {
	int data;
	struct el *next;                    
	};
	
// typedef struct el LIST;

void create_the_list(struct el **);
void insert_element_at_the_end(struct el **, int );
void insert_element_at_the_beggining(struct el **, int );
void creating_longint_as_a_list (struct el **, char []);
void check_before_addition (struct el *, struct el *, struct el **);
void displayList(struct el *);

int main ()
{
	char M[] = "-1001";
	char M1[] = "-309";  
	struct el *longNumber=NULL;
	struct el *longNumber2=NULL;
	struct el *sum;
	int i;
	
	
	creating_longint_as_a_list(&longNumber, M);
	creating_longint_as_a_list(&longNumber2, M1);
	//check_before_addition(longNumber, longNumber2, &sum);
	subtraction(longNumber,longNumber2,&sum);
	

	displayList(sum);
	
	return 0;
}

void create_the_list (struct el **head) 
{ 
	*head=NULL;
}

void insert_element_at_the_end(struct el **head, int n) 
{
	struct el *temp;
	struct el *p;
	
	temp=(struct el *)malloc(sizeof(struct el));
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

void insert_element_at_the_beggining(struct el **head, int n) 
{
	struct el *temp;
	struct el *p;
	
	temp=(struct el *)malloc(sizeof(struct el));
	temp->data = n;
	temp->next = *head;
	
	*head = temp;
	
	// if (*head == NULL) 
	// {
			// *head = temp;
	// }
	// else 
	// {
		// p = *head;
			
		// while (p->next != NULL) 
			// {
				// p = p->next;
			// }
			
		// p->next = temp;
	// }
	
}

void creating_longint_as_a_list (struct el **head, char M[])
{
	int i = 0;
	int first_zeros = 0;
	create_the_list(head);
	
	if ( M[i] == '-' )
	{
		insert_element_at_the_end(head, 1);			//first element of the list shows whether the number is negative or positive (1 for negative).
		i = 1;
	}
	else 
	{
		insert_element_at_the_end(head, 0);			// 0 for positive
	}
	while (i < strlen(M))
	{
		if ((M[i] != '0') || (first_zeros == 1) || ( i+1 == strlen(M)) )         //when person enters number with zeros at the beggining
		{
			insert_element_at_the_end(head, M[i] - 48);
			first_zeros = 1;
			i++;
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

void addition (struct el *a, struct el *b, struct el **sum)
{
	struct el *temp = a;
	struct el *temp2 = b;
	int lenght = 0, lenght2 = 0, temp_lenght, i, sum1, overflow = 0, n;
	struct el *temp3;
	
	while (temp != NULL)
	{
		temp = temp->next;
		lenght++;
	}
	while (temp2 != NULL)
	{
		temp2 = temp2->next;
		lenght2++;
	}
	
	if (lenght < lenght2)                     //a has to be longer than b, lenght has to be longer than lenght2
	{
		temp3 = a;
		a = b;
		b = temp3;
		temp_lenght = lenght;
		lenght = lenght2;
		lenght2 = temp_lenght;
	}
	
	
	
	while ( (lenght !=1) && (lenght2 !=1) )
	{
		temp = a;
		temp2 = b;
		
		for (i=0; i<lenght-1; i++) 
		{
			temp = temp->next;
		}
		
		for (i=0; i<lenght2-1; i++)
		{
			temp2 = temp2->next;
		}
					
		sum1 = temp->data + temp2->data + overflow;
		
		if (sum1 > 10)
		{
			overflow = 1;
			n = sum1 % 10;
		}
		else
		{
			overflow = 0;
			n = sum1;
		}
		insert_element_at_the_beggining (sum, n);

		lenght--;
		lenght2--;
		
	}

	if (lenght != 1)
	{
		while (lenght != 1)
		{
			temp = a;
			
		for (i=0; i<lenght-1; i++) 
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
		insert_element_at_the_beggining(sum, n);
		lenght--;
		}
	}
	
}

void check_before_addition (struct el *longNumber, struct el *longNumber2, struct el **sum)
{	
	create_the_list(sum);
	*sum=(struct el *)malloc(sizeof(struct el));
	(*sum)->next = NULL;
	
	if ( (longNumber->data == 0) && (longNumber2->data == 0) || ((longNumber->data == 1) && (longNumber2->data == 1)) )
	{

		addition(longNumber, longNumber2, sum);
		
		if (longNumber->data == 0)
		{
			insert_element_at_the_beggining(sum, 0);
		}
		else
		{
			insert_element_at_the_beggining(sum, 1);
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
			longNumber->data = 0;
			subtraction(longNumber, longNumber2, sum);
			longNumber->data = 1;
		}
		
	}
	
}

void displayList(struct el *head) 
{
	struct el *p = head;
	
	if (p == NULL) 
	{
		printf("Sarasas nesukurtas");
	}
	else 
	{
		
		while (p != NULL)
			{
			printf ("%d ", p->data);
			p = p->next;
			}
	}
		
}
