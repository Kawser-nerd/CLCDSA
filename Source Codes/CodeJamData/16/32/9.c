#include <stdio.h>

int main()
{
	unsigned int T,tcase,B,nodes;
	unsigned long long M,i,j,count,cut;

	scanf("%u",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%u %llu",&B, &M);
		count = 1;
		count <<= (B-2);
		if(count<M)
		{
			printf("Case #%u: IMPOSSIBLE\n",tcase);
			continue;
		}
		count = 1;
		nodes = 2;
		while(count<M)
		{
			count <<= 1;
			nodes++;
		}
		cut = count-M;

		printf("Case #%u: POSSIBLE\n",tcase);
		for(i=1;i<=B;i++)
		{
			for(j=1;j<=B;j++)
			{
				int d,jOriginal;

				jOriginal=j;
				if(j==nodes && nodes!=B)
					j++;
				else if(j==B)
					j=nodes;
				d=1;
				if(i>=j || i>=nodes || j>nodes)
					d=0;
				else if(i==1 && j<nodes && (cut & (1LL<<(nodes-1-j))))
					d=0;
				printf("%d",d);
				j=jOriginal;
			}
			printf("\n");
		}
	}

	return 0;
}

