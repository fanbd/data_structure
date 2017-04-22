/*
 *前序建立二叉树并输出
 * */
#include <stdio.h>
#include <malloc.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;
void InOrderTraverse(BiTree T);
void CreatBiTree(BiTree *T);

int main()
{
	BiTree T;
	CreatBiTree(&T );
	InOrderTraverse(T);
	printf("\n");
	
	return 0;
}

void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	InOrderTraverse(T->lchild);
	InOrderTraverse(T->rchild);
}

void CreatBiTree(BiTree *T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);
	}
}
