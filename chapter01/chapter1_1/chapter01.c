#include <stdio.h>
#define MAX_ELEMENT 5
int score[MAX_ELEMENT] = { 5, 4, 10, 2, 5 };

int find_max_score(int n) 
{
	int i, tmp;
	tmp = score[0];
	for(i=1;i<n;i++) 
	{
		if (score[i] > tmp)
		{
			tmp = score[i];
		}
	}
	return tmp;
}
void main() {
	int result = find_max_score(5);
	printf("%d", result);
}

