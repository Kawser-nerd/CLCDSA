#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
char A[55][55];
int main()
{
	u t=0,T,i,j,n;llu x;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u%I64u",&n,&x);
		printf("Case #%u:",t);
		if((1llu<<(n-2))<x){printf(" IMPOSSIBLE\n");continue;}
		printf(" POSSIBLE\n");
		for(i=-1;++i<n;A[i][n]='\0')for(j=-1;++j<n;)A[i][j]=i<j?'1':'0';
		if((1llu<<(n-2))>x)for(A[i=0][n-1]='0';++i<n;x>>=1)if(!(x&1))A[i][n-1]='0';
		for(i=-1;++i<n;)printf("%s\n",A[i]);
	}
	return 0;
}
