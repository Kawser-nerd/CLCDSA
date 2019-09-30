#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int s;
	int e;
} table;

int cmp( const void *p, const void *q )
{
    return ((table*)p)->s - ((table*)q)->s;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	table se[n];
	for (int i = 0; i < n; ++i)
	{	
		scanf("%d%d", &se[i].s, &se[i].e);
		se[i].e*=-1;
		se[i].s -= se[i].s%5;
		if(se[i].e%5!=0) se[i].e += 5-se[i].e%5;
		if(se[i].e%100==60) se[i].e += 40;
	}
	qsort(se, n, sizeof(table), cmp);

	table ans[n];
	ans[0].s = se[0].s;
	ans[0].e = se[0].e;
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		if(se[i].s>ans[cnt].e)
		{
			cnt++;
			ans[cnt].s = se[i].s;
			ans[cnt].e = se[i].e;
		}
		else
		{
			if(ans[cnt].e<se[i].e) ans[cnt].e = se[i].e;
		}
	}
for (int i = 0; i <= cnt; ++i)
{
	printf("%04d-%04d\n", ans[i].s, ans[i].e);
}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &se[i].s, &se[i].e);
   ^