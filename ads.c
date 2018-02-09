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
void insert_element(struct el **, int );
void creating_longint_as_a_list (struct el **, char []);
void displayList(struct el *);

int main ()
{
	char M[] = "0001234567890";
	char M1[] = "-1234";  
	struct el *longNumber;
	struct el *longNumber2;
	int i;
	
	
	creating_longint_as_a_list(&longNumber, M);
	creating_longint_as_a_list(&longNumber2, M1);
	
	
	
	displayList(longNumber);
	
	return 0;
}

void create_the_list (struct el **head) 
{ 
	*head=NULL;
}

void insert_element(struct el **head, int n) 
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

void creating_longint_as_a_list (struct el **head, char M[])
{
	int i = 0;
	int first_zeros = 0;
	create_the_list(head);
	
	if ( M[i] == '-' )
	{
		insert_element(head, 1);			//first element of the list shows whether the number is negative or positive (1 for negative).
		i = 1;
	}
	else 
	{
		insert_element(head, 0);			// 0 for positive
	}
	
	while (i < strlen(M))
	{
		if ((M[i] != '0') || (first_zeros == 1) || ( i+1 == strlen(M)) )         //when person enters number with zeros at the beggining
		{
			insert_element(head, M[i] - 48);
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
			printf ("%d", p->data);
			p = p->next;
			}
			
	}
		
}