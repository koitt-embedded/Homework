#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};
typedef struct node Queue;

Queue *get_node()
{
	Queue *tmp;
	tmp = (Queue *)malloc(sizeof(Queue));
	tmp -> link = NULL;
	return tmp;
}


void enqueue(Queue **head, int data)
{
	if(!(*head))
	{
		*head = get_node();
		(*head) -> data = data;
		return;
	}
	enqueue(&(*head)-> link, data);
}

void print_enqueue(Queue *head)
{
	Queue *tmp;
	tmp = head;

	while(tmp)
	{
		printf("tmp -> data = %d\n", tmp -> data);
		tmp = tmp -> link;
	}

}

Queue *chg_node(Queue *head)
{
	Queue *tmp;
	tmp = head;
	head = head -> link;
	free(tmp);

	return head;
}

void *dequeue(Queue *head, int data)
{
	if(!head)
	{
		printf("can not find");
		return NULL;
	}
	else if(head -> data != data)
	{
		head -> link = dequeue(head -> link, data);
	}
	else
	{
		head = chg_node(head);
	}
	return head;
}

int main(void)
{
	Queue *head = NULL;
	int i;
	for(i=0; i<10; i++)
	{
		enqueue(&head,(i+1)*10);
	}
	//print_enqueue(head);
	head = dequeue(head, 40);
	print_enqueue(head);

	return 0;
}
