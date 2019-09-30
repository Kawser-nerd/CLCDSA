#include <stdio.h>

#define MAXN 10010

long N,D;
long d[MAXN], l[MAXN];
long reach[MAXN];
char ans;

int input()
{
	long i;
	scanf("%ld", &N);
	for (i=0; i<N; i++)
		scanf("%ld %ld", &d[i], &l[i]);
	scanf("%ld", &D);
	return 0;
}

int work()
{
	long i,j,tmp;
	for (i=0; i<=N; i++)
		reach[i]=-1;
	reach[0]=d[0];
	
	d[N]=D;
	l[N]=0;
	for (i=1; i<=N; i++)
	{
		for (j=0; j<i; j++) 
			if (reach[j]>=0){
				if (reach[j]>=d[i]-d[j]) {
					if (d[i]-d[j]>l[i])
						tmp=l[i];
					else 
						tmp=d[i]-d[j];
					if (tmp>reach[i]) 
						reach[i]=tmp;
				}
			}
		//printf("i=%ld %ld\n", i, reach[i]);
	}
	
	if (reach[N]<0) ans = 0;
	else ans =1;
	return 0;
}

int main() 
{
	long T,i;
	
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		input();
		work();
		printf("Case #%d: ", i+1);	
		if (ans==1) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}