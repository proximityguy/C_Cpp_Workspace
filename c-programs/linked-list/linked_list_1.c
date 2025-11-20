// VARIOUS OPERATIONS OF DYNAMIC LINK LIST//

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

struct link_list
{
	int data;
	struct link_list *next;
};

typedef struct link_list list;

// LIST IS NAME OF STRUCTURE , IT IS NOT STRUCTURE VARIABLE//
// CREAT IS A FUNCTION WHICH WILL RETURN STRUCTURE TYPE DATA//

list *creat()
{
	int n, i;
	list *head, *q, *r;
	printf("\nENTER TOTAL NO OF NODE :");
	scanf("%d", &n);
	printf("\n enter the value of node :");
	// FIRST NODE IS CREATING//
	head = (list *)malloc(sizeof(list));
	scanf("%d", &(head->data));
	head->next = NULL;
	// ASSIGNING ADDRESS OF HEAD IN [Q] , BECAUSE HEAD SHOULD NOT BE LOST//
	// WE WILL ACCESS OUR NODE THROUGH [Q]//
	q = head;
	for (i = 1; i < n; i++)
	{
		r = (list *)malloc(sizeof(list));
		scanf("%d", &(r->data));
		r->next = NULL;
		q->next = r;
		q = r;
	}
	return head;
}

/*DISPLAY IS ACCEPTING THE ADDRESS OF HEAD NODE, [P] IS A STRUCTURE
		TYPE DATA POINTER,DISPLAY WILL RETURN NOTHING.*/

void display(list *p)
{
	list *t;
	t = p;
	printf("\n\n");
	while (p != NULL)
	{
		printf("%d-->", p->data);

		p = p->next;
	}
	printf("NULL\n\n");

	p = t;
}

// INSERTION OF NODE AT LAST//
list *insert_last(list *p)
{
	list *q, *nu_node;
	q = p;
	printf("\n enter the data value :");
	nu_node = (list *)malloc(sizeof(list));
	scanf("%d", &(nu_node->data));
	while (p->next != NULL)
		p = p->next;
	if (p->next == NULL)
	{
		p->next = nu_node;
		nu_node->next = NULL;
	}
	return q;
}

list *insert_first(list *p)
{
	list *nu_node;

	nu_node = (list *)malloc(sizeof(list));
	printf("\n INSERTING NODE AT 1ST POSITION...\n");
	printf("\n enter the data 	:");
	scanf("%d", &(nu_node->data));
	nu_node->next = p;
	printf("\n AFTER ISERTION AT 1ST POSITION. \n");
	return nu_node;
}

list *insert_any(list *p)
{
	list *q, *nu_node, *temp;
	int pos, i;
	q = p;
	printf("\n enter the position of insertion \n 0<pos<n:");
	scanf("%d", &pos);
	for (i = 1; i < pos; i++)
		p = p->next;
	temp = p->next;
	nu_node = (list *)malloc(sizeof(list));
	printf("\n enter the node value   :");
	scanf("%d", &(nu_node->data));
	p->next = nu_node;
	nu_node->next = temp;
	return q;
}

list *del_first(list *p)
{
	list *del_info;
	del_info = p;
	p = p->next;
	free(del_info);
	return p;
}

list *del_any(list *p)
{
	list *del_info, *head, *prev;
	int pos, i;
	head = p;
	scanf("%d", &pos);
	del_info = p->next;
	for (i = 1; i < (pos - 1) && (p != NULL); i++)
	{
		p = del_info;
		del_info = del_info->next;
	}
	p->next = del_info->next;
	del_info->next = NULL;
	free(del_info);
	return head;
}

void reverse_print(list *p)
{
	list *temp, *save, *now;
	save = p;
	temp = NULL;
	if (p == NULL)
	{
		printf("\n\nLIST IS EMPTY..!!\nPress any key....");
		getch();
		return;
	}
	printf("\n\n-----------------------------------------------\n\n");
	printf("\nORIGINAL LIST IS...");
	display(p);
	printf("\nREVERSE OF LIST...");
	while (temp != p)
	{
		now = p;
		while (now->next != temp)
			now = now->next;
		printf("%d-->", now->data);
		temp = now;
	}
	printf("\n-------------------------------------------------\n\n");
	p = save;
}


int main()
{
	struct link_list *p;
	int choice;
	// clrscr();
	p = NULL;
	printf("\n\n\tPROGRAM VARIOS OPERATIONS ON SINGLE LINK-LIST\n ");
	printf("\t_________________________________________________\n");
	// textcolor(WHITE);
	cprintf("\nLINK-LIST OPERATIONs");
	while (choice)
	{
		printf("\n1.CREATION OF LINK-LIST\n2.DISPLAY OF LIST"
			   "\n3.INSERTION AT 1ST POSITION.\n4INSERTION AT LAST POSITION\n"
			   "5.INSERTION AT ANY POSITION.\n6.DELITION OF 1ST NODE"
			   "\n7.DELETION OF LAST NODE\n8.INSERTION AFTER SPECIFIED "
			   "POSITION\n9.INSERTION IN A SORTED LIST\n[10].PRINTING REVERSE"
			   "OF THE LIST press [R\\r]..\n\n");
		// textcolor(YELLOW);
		cprintf("PRESS [X\\x] TO EXIT");
		printf("\npress [C\\c] clear the screen.\n");
		// textcolor(WHITE);
		printf("\n\n ENTER THE CHOICE FOR DESIRED OPERATION :");
		//	scanf("%d",&choice);
		choice = getche();
		switch (choice)
		{
		case 49:
			p = creat(); // ascii value of 0 is 48 //
			break;
		case 50:
			display(p);
			break;
		case 51:
			p = insert_first(p);
			break;
		case 52:
			p = insert_last(p);
			break;
		case 53:
			p = insert_any(p);
			break;
		case 54:
			p = del_first(p);
			break;
		case 55:
			p = del_any(p);
			break;
		case 'r':
			reverse_print(p);
			break;
		case 'c':
			// clrscr();
			break;
		case 'x':
			exit(0);
			break;
		case 'R':
			reverse_print(p);
			break;
		case 'C':
			// clrscr();
			break;
		case 'X':
			exit(0);
			break;
		default:
			printf("\n INVALLID CHOICE OR FUNCTION"
				   "IS NOT DEFIND.\n");
		}
	}

	return 0;
}
