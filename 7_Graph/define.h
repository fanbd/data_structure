#include <stdio.h>
typedef char VertexType; //顶点类型
typedef int EdgeType;	//边上的权值类型
#define MAXVEX 100		//最大顶点数
#define INFINITY 65535	//用65535代表无限大

typedef struct
{
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType arc [MAXVEX][MAXVEX]; //邻接矩阵,可看做边表
	int numVertexes, numEdges; //图中当前的顶点和边数
}MGraph;

/*建立无向网图的邻接矩阵表示*/
void CreatMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("输入顶点数和边数:\n");
	scanf("%d, %d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; ++i)
		scanf(&G->vexs[i]);
	for (i = 0; i < G->numVertexes; ++i)
		for (j = 0; j < G->numVertexes; ++j)
			G->arc[i][j] = INFINITY;//邻接矩阵初始化
	for (k = 0; k < G->numEdges; ++k)
	{
		printf("输入边(vi, vj)上的下标i,下标j和权w:\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
