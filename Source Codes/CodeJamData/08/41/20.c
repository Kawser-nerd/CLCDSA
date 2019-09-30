#include <stdio.h>
#include <stdlib.h>

#define INF 999999999

inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
inline int norm(int a) {return min(INF, a);}

typedef struct
{
	int type;
	int l,r;
	int inspect0;
	int inspect1;

} Node;
Node Tree[20000];


inline int inspectAND(int X, int V)
{
	if(V)
		return norm(inspect(Tree[X].l, 1) + inspect(Tree[X].r, 1));
	else
		return min(inspect(Tree[X].l, 0), inspect(Tree[X].r, 0));
}

inline int inspectOR(int X, int V)
{
	if(V)
		return min(inspect(Tree[X].l, 1), inspect(Tree[X].r, 1));
	else
	{
		return norm(inspect(Tree[X].l, 0) + inspect(Tree[X].r, 0));
	}
}

int inspect(int X, int V)
{
	if (V == 0 && Tree[X].inspect0 != -1) return Tree[X].inspect0;
	if (V == 1 && Tree[X].inspect1 != -1) return Tree[X].inspect1;

	// Leaf case already precomputed
	
	int ret;

	if(Tree[X].type & 1) // changeable
	{
		if(Tree[X].type & (1<<1))
			ret = min(inspectAND(X, V), inspectOR(X,V)+1);
		else
			ret = min(inspectAND(X, V)+1, inspectOR(X,V));
	}
	else
	{
		if(Tree[X].type & (1<<1))
			ret = inspectAND(X, V);
		else
			ret = inspectOR(X,V);
	}
	
	if(V)
		return Tree[X].inspect1 = ret;
	else
		return Tree[X].inspect0 = ret;
}

inline void process()
{
	int M, V;
	scanf("%d %d", &M, &V);

	int i;
	int G, C, L;
	int parent;
	for (i = 0; i < (M-1)/2; i ++)
	{
		scanf("%d %d", &G, &C);
		Tree[i].type = 0 + (G<<1) + (C<<0);
		Tree[i].inspect1 = -1;
		Tree[i].inspect0 = -1;
		if(i)
		{
			if ((i+1)&1)
			{
				Tree[(i-1)/2].r = i;
			} else
			{
				Tree[(i-1)/2].l = i;
			}
		}
	}

	for (; i < M; i ++)
	{
		scanf("%d", &L);
		parent = (i-1)/2;
		Tree[i].type = 1<<2;
		Tree[i].l = L;
		if(L == 0)
		{
			Tree[i].inspect0 = 0;
			Tree[i].inspect1 = INF;
		}
		else
		{
			Tree[i].inspect0 = INF;
			Tree[i].inspect1 = 0;
		}

		if ((i+1)&1)
			Tree[parent].r = i;
		else
			Tree[parent].l = i;
	}
	/*
	for(i = 0; i < M; i ++)
	{
		printf("Node %i ",i);
		if (Tree[i].type & (1<<2))
		{
			printf("leaf %i\n", Tree[i].l);
			continue;
		}
		if(Tree[i].type & (1<<1))
			printf("AND ");
		else
			printf("OR ");

		if(Tree[i].type & (1<<0))
			printf("changeable ");

		printf("; Left %i ", Tree[i].l);
		printf("Right %i ", Tree[i].r);

		printf("\n");
	}*/

	int ret = inspect(0, V);

	if(ret == INF)
		printf("IMPOSSIBLE\n");
	else
		printf("%i\n", ret);
}

int main()
{
	int N;
	scanf("%d",&N);

	int i;
	for(i = 0; i < N; i ++)
	{
		printf("Case #%i: ", i+1);
		process();
	}
}
