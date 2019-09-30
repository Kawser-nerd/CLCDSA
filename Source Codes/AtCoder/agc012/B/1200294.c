#include<stdio.h>
#include<string.h>


typedef struct tag_edge_t
{
	int to;
	struct tag_edge_t *next;
}edge_t;

typedef struct
{
	int dp[11];
	edge_t *edge;
}node_t;

typedef struct
{
	int v, d, c, id;
}paint_t;


node_t node[100000+1];
paint_t paint[100000+1];
edge_t g_edge[100000*2];
int edge_num;


void node_edge_add(int a, int b)
{
	edge_t *edge;

	edge=&g_edge[edge_num++];
	edge->next=node[a].edge;
	edge->to=b;
	node[a].edge=edge;

	edge=&g_edge[edge_num++];
	edge->next=node[b].edge;
	edge->to=a;
	node[b].edge=edge;
}


void solve(paint_t paint)
{
	edge_t *edge;

	if(node[paint.v].dp[paint.d]) return;
	node[paint.v].dp[paint.d]=paint.id;
	if(paint.d==0) return;

	paint.d--;
	edge=node[paint.v].edge;
	for(;edge;edge=edge->next)
	{
		paint.v=edge->to;
		solve(paint);
	}
}


int max(int a, int b)
{
	if(a>b) return a;
	return b;
}

int main(void)
{
	int N, M, a, b, Q;
	int i, j, result;

	while(scanf("%d%d", &N, &M)==2)
	{
		memset(node, 0, sizeof(node));
		edge_num=0;

		for(i=0;i<M;i++)
		{
			scanf("%d%d", &a, &b);
			node_edge_add(a, b);
		}
		scanf("%d", &Q);
		for(i=1;i<=Q;i++)
		{
			scanf("%d%d%d", &paint[i].v, &paint[i].d, &paint[i].c);
			paint[i].id=i;
		}
		for(i=Q;i>0;i--)
		{
			solve(paint[i]);
		}
		for(i=1;i<=N;i++)
		{
			result=0;
			for(j=0;j<=10;j++)
			{
				result=max(result, node[i].dp[j]);
			}
			printf("%d\n", paint[result].c);
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:81:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &a, &b);
    ^
./Main.c:84:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &Q);
   ^
./Main.c:87:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d", &paint[i].v, &paint[i].d, &paint[i].c);
    ^