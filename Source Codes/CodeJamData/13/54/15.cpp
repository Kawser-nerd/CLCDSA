#include <cstdio>
#include <cstring>

int T, n;
int a[30];
double opt[1100000];
char st[50];
double calc(int sta)
{
	double ans = 0;
	if (opt[sta]>-.5) return opt[sta];
	if (sta==(1<<n)-1) return opt[sta]=0;
	for (int i=0;i<n;++i)
	{
		int j=i;
		int step = 0;
		while (sta&(1<<j)){
			j=j+1;
			++step;
			if (j==n) j=0;
		}
		ans = ans + ((n-step)+calc(sta+(1<<j)))/(n+0.);
	}
	return opt[sta]=ans;
}
int main()
{
	scanf("%d", &T);
	for (int I=1;I<=T;++I)
	{
		scanf(" %s", st);
		n=strlen(st);
		for (int i=0;i<n;++i)
			if (st[i]=='X') a[n-i-1]=1;
			else a[n-i-1]=0;
		int stu = 0;
		for (int i=0;i<n;++i)
			stu=stu*2+a[i];
		//printf("%d %d\n", n, stu);
		for (int i=0;i<(1<<n);++i)
			opt[i]=-2;
		double ans = calc(stu);
		printf("Case #%d: %.9lf\n", I, ans);
	}
}
