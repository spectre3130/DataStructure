#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element list[MAX_LIST_SIZE];
	int length;
} ArrayListType;

// error
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//list init
void init(ArrayListType *L)
{
	L->length = 0;
}

//if a list is empty? return 1
//otherwise return 0
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}
//if a list is full? return 1
//otherwise return 0
int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

//list output
void display(ArrayListType *L)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		printf("%d\n", L->list[i]);
	}
}
/*
L: arrayList pointer
position: 삽입될 위치
item: 삽입되는 아이템
*/

void add(ArrayListType *L, int position, element item)
{
	if(!is_full(L) && (position >=0) && (position <= L->length)) 
	{
		int i;
		for (i = (L->length - 1); i >= position; i--)
		{
			L->list[i + 1] = L->list[i];
		}
		L->list[position] = item;
		L->length++;
	}
}
/*
L: arrayList pointer
position: 삭제될 위치
return: 삭제된 아이템
*/
element delete(ArrayListType *L, int position)
{
	int i;
	element item;

	if (position < 0 || position >= L->length)
	{
		error("error");
	}
	item = L->list[position];
	for (i = position; i < L->length - 1; i++)
	{
		L->list[i] = L->list[i + 1];
	}
	L->length--;
	return item;
}

void main()
{
	ArrayListType list1;
	ArrayListType *plist;

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	element item = delete(&list1, -1);
	display(&list1);

	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);
	free(plist);
}
