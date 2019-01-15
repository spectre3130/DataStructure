#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZA_SIZE 6

typedef struct {
	short r;
	short c;
} element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->stack[++(s->top)] = item;
	}
}

element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->stack[(s->top)--];
	}
}

element peek(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->stack[(s->top)];
	}
}

element here, entry = { 1,0 };

char maze[MAZA_SIZE][MAZA_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

void push_loc(StackType *s, int r, int c)
{
	if (r < 0 || c < 0)
	{
		return;
	}
	if (maze[r][c] != '1' || maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void main()
{
	int r, c;
	StackType s;

	init(&s);

	here = entry;
	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r , c - 1);
		push_loc(&s, r , c + 1);
		if (is_empty(&s))
		{
			printf("�̷�ã�� ����\n");
			return;
		}
		else
		{
			here = pop(&s);
		}
	}

	printf("�̷�ã�� ����\n");
}
