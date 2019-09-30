#include<stdio.h>
#include<stdlib.h>

int DP[600][600];
int calculated[600][600];
int result[600];

int find(int n,int m)
{
	if(n<0) return 0;
	if(n==0) return 1;
	if(m<0) return 0;
	if(calculated[n][m]) return DP[n][m];
	int i,ctotal=0;
	for(i=1;i<=m;i++)
	{
		ctotal+=find(n-i,m);
		ctotal%=100003;
	}
	calculated[n][m]=1;
	return DP[n][m]=ctotal;
}

int main()
{
	int i,j,cur;
	for(i=1;i<510;i++)
	{
		cur=0;
		for(j=0;j<=i;j++)
		{
			cur+=find(j,i-j);
			cur%=100003;
		}
		result[i]=cur;
		//printf("%d %d\n",i,cur);
	}
	FILE *input=fopen("pure.in","r"),*output=fopen("pure.out","w");
	int T;
	fscanf(input," %d",&T);
	for(i=1;i<=T;i++)
	{
		fscanf(input," %d",&cur);
		fprintf(output,"Case #%d: %d\n",i,result[cur-1]);
	}
	return 0;
}
