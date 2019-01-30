#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}

void display(TreeNode *p)
{
	if (p != NULL)
	{
		printf("(");
		display(p->left);
		printf("%s", p->key.word);
		display(p->right);
		printf(")");
	}
}

TreeNode *search(TreeNode *root, element key)
{
	
	TreeNode *p = root;
	while (p != NULL) 
	{
		switch (compare(key, p->key)) {
			case -1: p = p->left; break;
			case 0: return p;
			case 1: p = p->right; break;
		}
	}
	return p;
}

void insert_node(TreeNode **root, element key)
{
	TreeNode *p, *t;
	TreeNode *n;

	t = *root;
	p = NULL;
	while (t != NULL) {
		if (compare(key, t->key) == 0) 
		{
			return;
		}

		p = t;

		if (compare(key, t->key) < 0)
		{
			t = t->left;
		}
		else 
		{
			t = t->right;
		}

		n = (TreeNode *)malloc(sizeof(TreeNode));
		if (n == NULL)
		{
			return;
		}

		n->key = key;
		n->left = n->right = NULL;

		if (p != NULL)
		{
			if (compare(key, p->key)<0)
			{
				p->left = n;
			}
			else
			{
				p->right = n;
			}
		}
		else
		{
			*root = n;
		}
	}
}

void delete_node(TreeNode **root, element key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	p = NULL;
	t = *root;
	
	while (t != NULL && compare(t->key,  key) != 0)
	{
		p = t;
		t = (compare(t->key, key) < 0) ? t->left : t->right;
	}

	if (t = NULL)
	{
		printf("key is not in the tree");
		return;
	}

	//�ܸ���� �� ���
	if ((t->left == NULL) && (t->right == NULL))
	{
		if( p != NULL) 
		{
			if (p->left == t)
			{
				p->left = NULL;
			}
			else
			{
				p->right = NULL;
			}
		}
		else
		{
			*root = NULL;
		}
	} 
	//�ϳ��� �ڽĸ� ���� ���
	else if ((t->left == NULL) || (t->right == NULL))
	{
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL)
		{
			if (p->left == t)
			{
				p->left = child;
			}
			else
			{
				p->right = child;
			}
		}
	}
	//�� ���� �ڽ��� ������ ���
	else
	{
		succ_p = t;
		succ = t->right;

		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = succ->left;
		}
		
		if (succ_p->left == succ)
		{
			succ_p->left = succ->right;
 		}
		else
		{
			succ_p->right = succ->right;
		}

		t->key = succ->key;
		t = succ;
	}

	free(t);
}

void help()
{
	printf("***************\n");
	printf("i:�Է�\n");
	printf("d:����\n");
	printf("s:Ž��\n");
	printf("p:���\n");
	printf("q:����\n");
	printf("***************\n");
}

void main()
{
	char command;
	element e;
	TreeNode *root = NULL;
	TreeNode *tmp;

	do {
		help();
		command = getchar();
		fflush(stdin);
		switch (command) {
			case 'i' :
				printf("�ܾ�:");
				gets_s(e.word, 32);
				//printf("�ǹ�:");
				//gets_s(e.meaning, 32);
				insert_node(&root, e);
				break;
			case 'd':
				printf("�ܾ�:");
				gets_s(e.word, 32);
				delete_node(&root, e);
				break;
			case 'p':
				display(root);
				printf("\n");
				break;
			case 's':
				printf("�ܾ�:");
				gets_s(e.word, 32);
				tmp = search(root, e);
				if (tmp != NULL)
				{
					printf("�ǹ�:%s\n", e.meaning);
				}
				break;
		} 
	} while (command != 'q');
}
