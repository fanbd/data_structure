#include "define.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/* 二叉树前序遍历递归算法*/
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return ;
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}


/* 二叉树中序遍历递归算法*/
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PreOrderTraverse(T->lchild);
	printf("%c ", T->data);
	PreOrderTraverse(T->rchild);
}

/* 二叉树后序遍历递归算法*/
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	printf("%c ", T->data);
}

/*按前序输入二叉树中结点的值 */
/* #表示空树,构造二叉树链表表示二叉树T*/
void CreateBiTree(BiTree *T)
{
	char  ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(-1);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
