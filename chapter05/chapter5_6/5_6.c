#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;
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

int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch, nextCh;
	StackType s;
	
	init(&s);

	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = 0;
			do {
				nextCh = exp[i+1];
				if (!(nextCh >= '0' && nextCh <= '9'))
				{
					push(&s, value);
					value = ch - '0';
					break;
				}
				else
				{
					value = value * 10 + ch - '0';
					ch = exp[++i];
				}
			} while (ch >= '0' && ch <= '9');
		
			push(&s, value);
		}
		else
		{
			//먼저 꺼내온쪽이 계산할때 뒤로...
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
				case '+': push(&s, op1 + op2); break;
				case '-': push(&s, op1 - op2); break;
				case '*': push(&s, op1 * op2); break;
				case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

void main()
{
	int result;
	printf("후위표기식 1233+49*+\n");
	result = eval("1233+49*+");
	printf("결과값 : %d\n", result);
}

