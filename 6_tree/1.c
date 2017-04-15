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

