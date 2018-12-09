#include <stdio.h>;

int fib(int n)
{
	if (n < 2) return n;
	int i, tmp, current = 1, last = 0;
	for (i = 2; i <= n; i++)
	{
		tmp = current;
		current += last;
		last = tmp;
	}
	return current;
}

void main()
{
	int result = fib(10);
	printf("fib result : %d", result);
}