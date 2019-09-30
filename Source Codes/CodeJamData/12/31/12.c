#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define max(X,Y) ((X)>(Y)?(X):(Y))
#define min(X,Y) ((X)<(Y)?(X):(Y))

typedef struct IntNodeTag
{
	int info;
	struct IntNodeTag *next;
} *IntNode;

void * new (size_t size);
void delete (void * p);
IntNode pushInt (int s, IntNode a);
int popInt (IntNode * pa);

int main()
{
	int i,j,k,curr,tcase,T,N,M[1000],res,nb[1000][10];
	char v[1000];
	IntNode st=NULL;
	
	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d",M+i);
			for(j=0;j<M[i];j++)
			{
				scanf("%d",nb[i]+j);
				nb[i][j]--;
			}
		}
		res=0;
		for(i=0;i<N && !res;i++)
		{
			if(M[i]<2)
				continue;
			for(j=0;j<N;j++)
				v[j]=0;
			while(st)
				popInt(&st);
			v[i]=1;
			st=pushInt(i,st);
			while(st && !res)
			{
				curr=popInt(&st);
				for(k=0;k<M[curr];k++)
				{
					if(v[nb[curr][k]])
					{
						res=1;
						break;
					}
					v[nb[curr][k]]=1;
					st=pushInt(nb[curr][k],st);
				}
			}
		}

		printf("Case #%d: %s\n",tcase,res?"Yes":"No");
	}


	return 0;
}

void * new (size_t size)
{
	void * result = malloc(size);

	if (result == NULL)
		fprintf(stderr,"Out of memory!\n");
	return result;
}

void delete (void * p)
{
	if (p != NULL)
		free(p);
}

IntNode pushInt (int s, IntNode a)
{
	IntNode p;

	p = (IntNode) new(sizeof(struct IntNodeTag));
	p->info = s;
	p->next = a;
	return p;
}

int popInt (IntNode * pa)
{
	int res;
	IntNode t;

	if (pa==NULL || (*pa)==NULL)
		return -1;
	else
	{
		t = *pa;
		res = t->info;
		*pa = t->next;
		delete(t);
		return res;
	}
}
