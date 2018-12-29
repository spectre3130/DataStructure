#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
struct 
{
	float coef;
	int expon;
} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };

int avail = 6;

char compare(int a, int b)
{
	if (a > b)
	{
		return  '>';
	}
	else if (a == b)
	{
		return '=';
	}
	else if (a < b)
	{
		return '<';
	}
}

void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be) 
	{
		switch(compare(terms[As].expon, terms[Bs].expon)) 
		{
			case '>' :
				attach(terms[As].coef, terms[As].expon);
				//printf("fuck add : %d , %d", terms[avail].coef, terms[avail].expon);
				As++;
				break;
			case '=':
				tempcoef = terms[As].coef + terms[Bs].coef;
				if (tempcoef)
				{
					attach(tempcoef, terms[As].expon);
					//printf("fuck add : %d , %d", terms[avail].coef, terms[avail].expon);
				}
				As++;
				Bs++;
				break;
			case '<':
				attach(terms[Bs].coef, terms[Bs].expon);
				//printf("fuck add : %d , %d", terms[avail].coef, terms[avail].expon);
				Bs++;
				break;
		}
	}
	for (; As <= Ae; As++)
	{
		attach(terms[As].coef, terms[As].expon);
	}
	for (; Bs <= Be; Bs++)
	{
		attach(terms[Bs].coef, terms[Bs].expon);
	}
	*Ce = avail - 1;
}

void main()
{
	int Cs, Ce;
	poly_add2(0, 2, 3, 5, &Cs, &Ce);
}