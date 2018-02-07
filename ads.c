#include <stdio.h>
#include <stdlib.h>

struct el {
	int data;
	struct el *next;                    
	};
	
// typedef struct el LIST;

void create_the_list (struct el **head) 
{ 
	*head=NULL;
}

void insert_element(struct el **head, int n) 
{
	LIST *temp;
	LIST *p;
	
	temp=(LIST *)malloc(sizeof(LIST));
	temp->data = n;
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

void reading_long_integer (int M[])                             //KODEL AS CIA NEGALIU ISKART I SARASA?
{
	// char sign;
	int a;
	int i = 0;
	int numberOfElements = 0;
	
	while ((a != 32) || (a != 13))				//nzn del to 13, cia tik CR
	{
		scanf("%d", M[i]);
		i++;
		numberOfElements++;
	}
	
}

void creating_longint_as_a_list (struct el **head, int M[])
{
	int i = 0;
	
	create_the_list(*head);
	
	if ( M[i] == 45 )			//ascii for minus
	{
		insert_element(*head, 1);			//first element of the list shows whether the number is negative or positive (1 for negative).
	}
	else
	{
		insert_element(*head, 0);			// 0 for positive
	}
	
	for ( i = 1; i < numberOfElements; i++)
	{
		insert_element(*head, M[i]);
	}
}



int main ()
{
	char sign;
	int a;
	
	
	
	
	
	return 0;
}