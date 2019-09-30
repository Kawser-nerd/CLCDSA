#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int l,r;
} point;

point d[2000];

int cmp(const void *a,const void *b)
{
	return ((point *)a)->l-((point *)b)->l;
}

int main()
{
	int t,test;int i,j,count;
	int n;
	scanf("%d",&test);
	for (t=1;t<=test;++t)
	{
		scanf("%d",&n);
		for (i=0;i<n;++i)
			scanf("%d%d",&d[i].l,&d[i].r);
		qsort(d,n,sizeof(point),cmp);
		count=0;
		for (i=0;i<n;++i)
			for (j=i-1;j>=0;j--)
				if (d[i].l>d[j].l && d[i].r<d[j].r)
					++count;
		printf("Case #%d: %d\n",t,count);
	}	 
}
