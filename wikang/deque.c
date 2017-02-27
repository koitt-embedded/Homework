#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
} queue;


queue *get_node()
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head, int data)
{
	if(!(*head))
	{
		*head = get_node();
		(*head)->data = data;
		return;
	}
	enqueue(&(*head)->link, data);
}

void print_queue(queue *head)
{
	queue *tmp = head;
	while(tmp)
	{
		printf("tmp -> data =%d\n", tmp->data);
		tmp = tmp->link;
	}
}

queue *chg_node(queue *head)
{
	queue *tmp;
	tmp = head;
	head = head->link;
	free(tmp);
	return head;
}

queue *dequeue(queue *head, int data)
{
	if(!head)
	{
		printf("Can't find data\n");
		return NULL;
	}
	else if(head->data != data)
	{
		head->link = dequeue(head->link, data);
	}
	else
	{
		head = chg_node(head);
	}
	return head;
}

int main(void)
{
	int i;
	queue *head = NULL;

	for(i = 0; i < 10; i++)
	{
		enqueue(&head, (i+1)*10);
	}
	print_queue(head);
	head = dequeue(head, 30);
	print_queue(head);
	return 0;
}
