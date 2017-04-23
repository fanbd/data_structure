#include <stdio.h>

typedef enum {Link, Thread} PointerTag;
typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag;
	PointerTag RTag;
} BiThrNode, *BiThrTree;

/*中序遍历进行中序线索化*/
BiThrTree pre;	//全局变量，始终指向刚刚访问过的节点
void InThreading (BiThrTree p)
{
	if (p)
	{
		InThreading (p->lchild);
		if (!p->lchild) //没有左孩子
		{
			p->LTag = Thread; //前驱线索化
			p->lchild = pre;  //左孩子指针指向前驱
		}
		if (!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;

	}
}
