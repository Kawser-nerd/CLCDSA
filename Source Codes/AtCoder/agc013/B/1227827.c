#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tag_vertex_t
{
	int id, is_passed;
	int edge_num, *edge;
}vertex_t;


#define N_MAX 100000
#define M_MAX 100000

int n, m;
vertex_t vertex[N_MAX+1];
int result[N_MAX];
int result_num;


void result_init(void)
{
	result_num=0;
}


void result_push_back(int x)
{
	result[result_num++]=x;
}


void result_push_front(int x)
{
	memmove(result+1, result, sizeof(result[0])*result_num);
	result[0]=x;
	result_num++;
}


int result_pop_back(void)
{
	if(result_num<=0) return -1;
	return result[--result_num];
}


void edge_add(vertex_t *vert, int to)
{
	vert->edge=realloc(vert->edge, sizeof(int)*(vert->edge_num+1));
	vert->edge[vert->edge_num++]=to;
}


void vertex_zero(vertex_t *vert)
{
	free(vert->edge);
	memset(vert, 0, sizeof(*vert));
}


void trace(int s, void (*func)(int))
{
	int i;

	for(;;)
	{
		func(s);
		vertex[s].is_passed=1;
		for(i=0;i<vertex[s].edge_num;i++)
		{
			if(vertex[vertex[s].edge[i]].is_passed) continue;
			break;
		}
		if(i>=vertex[s].edge_num) break;
		s=vertex[s].edge[i];
	}
}


int main(void)
{
	int a, b, i, c=0;

	while(scanf("%d%d", &n, &m)==2)
	{
		result_init();
		for(i=0;i<n;i++)
		{
			vertex_zero(&vertex[i]);
		}

		for(i=0;i<m;i++)
		{
			scanf("%d%d", &a, &b);
			edge_add(&vertex[a], b);
			edge_add(&vertex[b], a);
			c=a;
		}

		trace(c, result_push_front);
		result_pop_back();
		trace(c, result_push_back);

		printf("%d\n%d", result_num, result[0]);
		for(i=1;i<result_num;i++) printf(" %d", result[i]);
		printf("\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:96:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &a, &b);
    ^