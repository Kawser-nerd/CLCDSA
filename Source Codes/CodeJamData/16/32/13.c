#include<stdio.h>

int lg(int x)
{
	int i;
	for(i=0;(x>>i)>0;i++);
	return i;
}

int dp(int e)
{
	if(e<0)
		return 0;
	int i, p=1;
	for(i=0;i<e;i++)
		p*=2;
	return p;
}
int mat[50][50];
void affiche(int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d",mat[i][j]);
		printf("\n");
	}
	return;
}

int main()
{
	int t, b, m, i, j, k, l, l2, l3;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		printf("Case #%d: ",i+1);
		scanf("%d %d",&b,&m);
		if(m>(1<<(b-2)))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		else
		{
			printf("POSSIBLE\n");
			for(j=0;j<b;j++)
			{
				for(k=0;k<b;k++)
					mat[j][k]=0;
			}
			l=lg(m);
			for(j=0;j<l;j++)
			{
				for(k=j+1;k<l;k++)
					mat[j][k]=1;
				mat[j][b-1]=1;
			}
			l2=m-dp(l-1);
			l3=lg(l2);
			for(j=0;j<l3;j++)
			{
				if((l2>>j)%2)
					mat[j+1][l]=1;
			}	
			if(l2!=0)
				mat[l][b-1]=1;		
		}
		affiche(b);	
	}
	return 0;
}
