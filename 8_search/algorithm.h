#define int Status
/*顺序查找, a为数组, n为要查找的数组个数, key为要查找的关键字*/

int  Sequential_Search(int *a, int n, int key)
{
	int i;
	for (i = 1; i <= n; ++i)
		if (a[i] == key)
			return i;
	
	return 0;
}

int Sequential_Search2(int *a, int n, int key)
{
	/*有哨兵顺序查找*/
	int i;
	a[0] = key;
	i = n;
	while (a[i] != key)
		--i;
	
	return i;
}

int Binary_Search(int *a, int n, int key)
{
	/*折半查找*/
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
			high = mid-1;
		else if (key > a[mid])
			low = mid+1;
		else 
			return mid;
	}

	return 0;
}

int Fibonacci_Search(int *a, int n, int key)
{ /*斐波那契查找*/
	int low, high, mid, i, k;
	low = 1;
	high = n;
	k = 0;
	while (n >F[k]-1) //计算n位于数列的位置
		++k;
	for (i=n; i < F[k]-1; ++i) //将不满的数值补全
		a[i] = a[n];

	while (low <= high)
	{
		mid = low+F[k-1]-1; //计算当前分隔的下标
		if (key < a[mid]) //
		{
			high = mid-1;
			k = k-1;
		}
		else if (key > a[mid])
		{
			low = mid+1;
			k -= 2;
		}
		else
		{
			if (mid <= n)
				return mid;
			else 
				return n;
		}
	}

	return 0;
}

/*二叉排序树*/
typedef struct BiTNode
/*二叉树的二叉链表结点结构定义*/
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	/*
	 可递归函数，关键点在于f 是 T 的双亲结点
	 方便查找兄弟结点
	 p用来接受查找成功的结点位置
	 * */
	if (!T)
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data)
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
		return SearchBST(T->lchild, key, T, p);
	else
		return SearchBST(T->rchild, key, T, p);
}
 Status InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))
	{//find fail also the 'key' not in the tree & insert it
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)//这里的意思是T是空树
			*T = s;
		else if (key < p->data)
			p->lchild = s;
		else 
			p->rchild = s;
		return TRUE;
	}
	else
		return FALSE;//there is already a 'key' in the tree
}

/*删除二叉排序树T中关键字等于key的元素*/
Status DeleteBST(BiTree *T, int key)
{
	if (!*T)
		return FALSE;
	else
	{
		if (key == (*T)->data)
			return Delete(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}
Status Delete(BiTree *p)
{//删除结点p，并重接它的左右子树
	BiTree q, s;
	if( (*p)->rchild == NULL)	//右子树空则只需重接左子树
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if( (*p)->lchild == NULL)	//左子树空则只需重接右子树
	{
		q=*p; *p=(*p)->rchild;	free(q);
	}
	else
	{
		q=*p;  s=(*p)->lchild;
		while(s->rchild)	//转左，然后向右走到尽头
		{
			q=s;	s=s->rchild;
		}
		(*p)->data = s->data;	//s指向被删结点的直接前驱
		if (q!=*p)
			q->rchild = s->lchild;	//重接q的右子树
		else
			q->lchild=s->lchild;	//重接q的左子树
		free(s);
	}

	return TRUE;
}
