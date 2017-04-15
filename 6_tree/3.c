/*树的孩子兄弟表示法结构定义*/

typedef struct CSNode
{
	TElemType data;
	struct CSNode *fristchild, *rightsib;
} CSNode, *CSTree;
