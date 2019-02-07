#include < stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef int element;

typedef struct QueueNode {
	element item;
	struct QueueNode *link;
} QueueNode;

typedef struct {
	QueueNode *front, *rear;
} QueueType;

typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
	int n; //정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}
	
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

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

void bfs_list(GraphType *g, int v)
{
	GraphNode *w;
	QueueType q;
	init(&q);
	visited[v] = TRUE;
	printf("%d ", v);
	enqueue(&q, v);
	while (!is_empty(&q))
	{
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link)
		{
			if (!visited[w->vertex])
			{
				visited[w->vertex] = TRUE;
				printf("%d ", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
	}
}

main()
{
	int i;
	GraphType g;

	graph_init(&g);

	for (i = 0; i < 4; i++)
	{
		insert_vertex(&g, i);
	}

	insert_edge(&g, 0, 1);
	insert_edge(&g, 1, 0);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 3, 0);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 1);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 3, 1);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 3, 2);
	bfs_list(&g, 0);
}
