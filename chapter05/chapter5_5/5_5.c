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
		fprintf(stderr, "스택 포화 에러\n");
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
		fprintf(stderr, "스택 공백 에러\n");
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
		fprintf(stderr, "스택 공백 에러\n");
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
			//여는 괄호를 만나면 스택에 삽입
			case '(': case '[': case '{':
				push(&s, ch);
				break;
			case ')': case ']': case '}':
				//비워진 스택이면 에러
				if (is_empty(&s))
				{
					return FALSE;
				}
				else
				{
					//스택에서 꺼내와서 괄호비교 
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
	//스택이 남아있으면...
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
		printf("괄호검사 성공");
	}
	else
	{
		printf("괄호검사 실패");
	}
}

