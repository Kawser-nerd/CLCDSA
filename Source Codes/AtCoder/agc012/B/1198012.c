#include<stdio.h>
#include<stdlib.h>

#define N_MAX 100000
#define M_MAX 100000
#define Q_MAX 100000

typedef struct tag_edge_t
{
	int from, to;
	struct tag_edge_t *next;
}edge_t;

typedef struct
{
	int id, c, x, d, y;
	edge_t *edge;
}node_t;

typedef struct
{
	int v, d, c, x;
}cmd_t;


#define QUE_SIZE Q_MAX*10

node_t node[N_MAX+1];
edge_t edge[M_MAX*2];
cmd_t cmd[Q_MAX];
cmd_t que[QUE_SIZE];
int que_start, que_end;
int g_count;

void que_init(void)
{
	que_start=que_end=0;
}

int que_push(cmd_t cmd)
{
	que[(que_end++)%QUE_SIZE]=cmd;
	if(que_end>=que_start+QUE_SIZE)
	{
		printf("que_start=%d\n", que_start);
		printf("que_end=%d\n", que_end);
		exit(1);
	}
	return 1;
}


int que_pop(cmd_t *cmd)
{
	if(que_end<=que_start) return 0;

	*cmd=que[(que_start++)%QUE_SIZE];
	if(que_start>=QUE_SIZE)
	{
		que_start-=QUE_SIZE;
		que_end-=QUE_SIZE;
	}
	return 1;
}


void paint(cmd_t cmd)
{
	edge_t *edge;
	cmd_t cmd2;

	que_init();
	que_push(cmd);
	while(que_pop(&cmd))
	{
		if(node[cmd.v].x==cmd.x) continue;
		if(node[cmd.v].x<0) g_count++;

		if(node[cmd.v].x<cmd.x)
		{
			node[cmd.v].c=cmd.c;
			node[cmd.v].x=cmd.x;
			node[cmd.v].d=cmd.d;
		}
		else
		{
			if(node[cmd.v].d>=cmd.d) continue;
		}

		if(cmd.d<1) continue;

		cmd2=cmd;
		cmd2.d--;
		edge=node[cmd.v].edge;
		for(;edge;edge=edge->next)
		{
			if(node[edge->to].x==cmd.x) continue;
			if(node[edge->to].y==cmd.x) continue;
			cmd2.v=edge->to;
			node[edge->to].y=cmd.x;
			que_push(cmd2);
		}
	}
//	printf("\n");
}


int cmp(const void *pa, const void *pb)
{
	const cmd_t *a, *b;
	a=pa;
	b=pb;
	if(a->d>b->d) return -1;
	return a->d<b->d;
}


int cmp2(const void *pa, const void *pb)
{
	const cmd_t *a, *b;
	a=pa;
	b=pb;
	if(a->d<b->d) return -1;
	return a->d>b->d;
}


int main(void)
{
	int N, M, Q;
	int a, b;
	int i;

	while(scanf("%d%d", &N, &M)==2)
	{
		for(i=1;i<=N;i++)
		{
			node[i].id=i;
			node[i].c=0;
			node[i].edge=NULL;
			node[i].x=-1;
			node[i].y=-1;
		}
		for(i=0;i<M;i++)
		{
			scanf("%d%d", &a, &b);
			edge[i*2  ].next=node[a].edge;
			edge[i*2  ].from=a;
			edge[i*2  ].to=b;
			node[a].edge=&edge[i*2  ];
			edge[i*2+1].next=node[b].edge;
			edge[i*2+1].from=b;
			edge[i*2+1].to=a;
			node[b].edge=&edge[i*2+1];
		}
		scanf("%d", &Q);
		for(i=0;i<Q;i++)
		{
			scanf("%d%d%d", &cmd[i].v, &cmd[i].d, &cmd[i].c);
			cmd[i].x=i;
		}
//		qsort(cmd, Q, sizeof(cmd_t), cmp2);
//		for(i=0;i<Q;i++) printf("cmd %d,%d,%d,%d\n", cmd[i].v, cmd[i].d, cmd[i].c, cmd[i].x);
		g_count=0;
		for(i=Q-1;i>=0;i--)
		{
			paint(cmd[i]);
			if(g_count>=N) break;
		}
		for(i=1;i<=N;i++) printf("%d\n", node[i].c);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:146:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &a, &b);
    ^
./Main.c:156:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &Q);
   ^
./Main.c:159:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d", &cmd[i].v, &cmd[i].d, &cmd[i].c);
    ^