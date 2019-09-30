#include <stdio.h>

#define N 20
int f;
long a[N];
int b1[N], b2[N];

int output(int p1, int p2)
{
	int i;
	for (i=0; i<p1; i++)
		printf("%ld ", a[b1[i]]);
	printf("\n");
	for (i=0; i<p2; i++)
		printf("%ld ", a[b2[i]]);
	printf("\n");
}

int dfs(int now, int p1, int p2, long s1, long s2)
{
	if (f==1) return 0;
	if (now==N) return 0;
	if ((s1>0) && (s1==s2)) {
		f=1;
		output(p1,p2);
		return 0;
	}
	
	dfs(now+1,p1,p2,s1,s2);
	if (f==1) return 0;
	b1[p1]=now;
	dfs(now+1,p1+1,p2,s1+a[now],s2);
	if (f==1) return 0;
	if (p1!=0) {
		b2[p2]=now;
		dfs(now+1,p1,p2+1,s1,s2+a[now]);
	}
	return 0;
}

int main() 
{
	int T,i,j,n;
	
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		scanf("%d", &n);
		for (j=0; j<n; j++) {
			scanf("%ld", &a[j]);
		}
		
		printf("Case #%d:\n", i+1);		
		f=0;
		dfs(0,0,0,0,0);
		if (f==0) printf("Impossible\n");
	}
	return 0;
}