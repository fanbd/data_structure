#include <stdio.h>

#define LH +1	//左高
#define EH 0	//等高
#define RH -1	//右高

typedef struct BiTNode
{
	int data;
	int bf;	//平衡因子
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void R_Rotate(BiTree *p)
{
/*对以p为根的二叉排序树作右旋处理
 * 处理之后p指向新的树根结点，即旋转处理之前的左子树的根节点*/
	BiTree L;
	L=(*p)->lchild;	//L指向p的左子树根节点
	(*p)->lchild = L->rchild;	//L的右子树挂接为p的左子树
	L->rchild = (*p);
	*p = L;			//p指向新的根节点
}

void L_Rotate(BiTree *p)
{
	BiTree R;
	R = (*p)->rchild;
	(*p)->rchild = R->lchild;	//如果R左子树空也没事
	R->lchild = (*p);
	(*p) = R;
}

void LeftBalance(BiTree *T)
{
/*对以指针T所指结点为根的二叉树作左平衡旋转处理
 * 本算法结束时，指针T指向新的根节点
 */
	
	
	
	
	BiTree L, Lr;
	L = (*T)->lchild;
	switch(L->bf)
	{
		case LH:
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			Lr = L->rchild;
			switch(Lr->bf)
			{
				case LH:
					(*T)->bf = RH;
					L->bf = EH;
					break;
				case EH:
					(*T)->bf = L->bf = EH;
					break;
				case RH:
					(*T)->bf = EH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
	}

}
