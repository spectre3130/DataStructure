#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct QueueNode {
	element item;
	struct QueueNode *link;
} QueueNode;

typedef struct {
	QueueNode *front, *rear;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q)
{
	q->front = q->rear = NULL;
}

int is_empty(QueueType *q)
{
	return (q->front == NULL);
}

int is_full(QueueType *q)
{
	return 0;
}

void enqueue(QueueType *q, element item)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if (temp == NULL)
	{
		error("메모리를 할당할 수 없습니다.");
	}
	else
	{
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q))
		{
			q->front = temp;
			q->rear = temp;
		}
		else
		{
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

element dequeue(QueueType *q)
{
	QueueNode *temp = q->front;
	
	element item;
	if (is_empty(q))
	{
		error("큐가 공백 상태입니다.");
	}
	else
	{
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL)
		{
			q->rear = NULL;
		}
		free(temp);
		return item;
	}
}

void main()
{
	QueueType q;
	init(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));

}