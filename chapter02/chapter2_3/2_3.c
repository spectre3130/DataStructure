#include <stdio.h>;

int factorial(int n)
{
	int i, result = 1;
	for (i = n; i >= 1; i--) 
	{
		printf("¹Ýº¹Áß... %d\n", result);
		result = result * i;
	}
	return result;
}

int main()
{
	int result = factorial(3);
	printf("%d", result);
}