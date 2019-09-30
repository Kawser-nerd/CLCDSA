#include<cstdio>

const int dx[]={0,1,1,1};
const int dy[]={1,0,1,-1};

char a[55][55];
int n,K;
char stack[55];
int top;

bool solve( char t )
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=0;k<4;k++)
	{
		int num = 0;
		while( num<K && a[i+dx[k]*num][j+dy[k]*num]==t ) num++;
		if( num==K ) return true;
	}
	return false;
}
int main()
{
	int Te,T=0;
	scanf("%d",&Te);
	while( Te-- )
	{
		T++;printf("Case #%d: ",T);
		scanf("%d%d",&n,&K);gets(a[0]);
		for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++) a[i][j]='.';

		for(int i=1;i<=n;i++)
		{
			gets(a[n+2]);
			for(int j=1;j<=n;j++)
				a[j][n+1-i] = a[n+2][j-1];
		}

		for(int j=1;j<=n;j++)
		{
			top = 0;
			for(int i=1;i<=n;i++) if(a[i][j]!='.')
			{
				stack[++top] = a[i][j];
				a[i][j] = '.';
			}
			for(int i=1;i<=top;i++)
				a[ n-top+i ][j] = stack[i];
		}

		int ans = solve('R')+2*solve('B');
		if( ans==0 ) puts("Neither");else
			if( ans==1 ) puts("Red");else
			if( ans==2 ) puts("Blue");else
			puts("Both");
	}
	return 0;
}
