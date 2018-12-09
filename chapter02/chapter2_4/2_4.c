#include <stdio.h>
 
double involution_loop(double x, int n)
{
	int i;
	double r = 1.0;
	for (i = 0; i < n; i++)
	{
		r = r * x;
	}
	return r;
}

double involution_recursive(double x, int n)
{
	if (n == 0) 
	{
		return 1;
	} 
	else if (n % 2 == 0)
	{
		return involution_recursive(x*x, n / 2);
	}
	else
	{
		return x * involution_recursive(x*x, (n - 1) / 2);
	}
}



void main()
{
	double result1 = involution_loop(2, 10);
	printf("반복 결과 : %5.0f\n", result1);

	double result2 = involution_recursive(2, 10);
	printf("순환 결과 : %5.0f\n", result2);
}
