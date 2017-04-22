/*树的双亲表示法结点结构定义*/

#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode
{
	TElemType data;
	int parent;
} PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;
} PTree;


/*树的孩子表示法结构定义*/

#define MAX_TREE_SIZE 100
typedef struct CTNode /*孩子结点*/
{
	int child;
	struct CTNode *next;
} *ChildPtr;
typedef struct /*表头结构*/
{
	TElemType data;
	ChildPtr firstchild;
} CTBox;

typedef struct /*树结构*/
{
	CTBox nodes[MAX_TREE_SIZE];/*结点数组*/
	int r, n;
}CTree;

/*树的孩子兄弟表示法结构定义*/

typedef struct CSNode
{
	TElemType data;
	struct CSNode *fristchild, *rightsib;
} CSNode, *CSTree;

/*二叉树的二叉链表结点结构定义*/

typedef struct BiTNode /*结点结构*/
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

