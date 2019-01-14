#include <stdio.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef char element;
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

int check_matching(char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init(&s);

	for (i = 0; i < n; i ++)
	{
		ch = in[i];
		switch (ch)
		{
			//���� ��ȣ�� ������ ���ÿ� ����
			case '(': case '[': case '{':
				push(&s, ch);
				break;
			case ')': case ']': case '}':
				//����� �����̸� ����
				if (is_empty(&s))
				{
					return FALSE;
				}
				else
				{
					//���ÿ��� �����ͼ� ��ȣ�� 
					open_ch = pop(&s);
					if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') ||
						(open_ch == '{' && ch != '}'))
					{
						return FALSE;
					}
					break;
				}

		}
	}
	//������ ����������...
	if (!is_empty(&s))
	{
		return FALSE;
	}

	return TRUE;
}

void main()
{
	if (check_matching("{A[i+1]=0;}}") == TRUE)
	{
		printf("��ȣ�˻� ����");
	}
	else
	{
		printf("��ȣ�˻� ����");
	}
}

