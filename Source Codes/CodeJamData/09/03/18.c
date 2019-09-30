#include<stdio.h>

int tc;

int i,j,k,l;
int t;
char *welcome="welcome to code jam";
int wl=19;

int main()
{
	int N;

	scanf("%d\n", &N);

	for (tc=1; tc<=N; tc++)
	{
		char str[501];
		int count[501]={0};
		int pcount[501]={1,0};
		int *prev,*curr,*tmp;
		int zero = 0,newzero;
		prev=pcount; curr=count;
		
		i=-1;
		do
		{
			i++;
			scanf("%c",str+i);
		}while (str[i]!='\n');
		str[i]=0;
//		printf("%s\n", str);

		for (k=0;k<19;k++)
		{
//			printf("LOKING for %c(%d)\n", welcome[k],zero);
			newzero = -1;
			for (j=0; j<i; j++)
			{
				if (str[j]==welcome[k])
				{
					t=0;	
					if (j==0 && k==0)
						t=1;
					for (l=j-1; l>=zero; l--)
						t += prev[l];
					if (newzero == -1 && t!=0)
						newzero = j;
					curr[j]=t%10000;
				}
			}
			if (newzero!=-1)
				zero = newzero;
/*			for (j=0; j<i; j++)
				printf("%d ",prev[j]);
			printf("\n");
			for (j=0; j<i; j++)
				printf("%d ", curr[j]);
			printf("\n");
*/			tmp=prev;
			prev=curr;
			curr=tmp;
			for (j=0; j<i; j++)
				curr[j]=0;
		}

		t=0;
		for (k=0;k<i;k++)
			t+=prev[k];
		printf("Case #%d: %04d\n",tc, t%10000);
	}
}
