#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TLong long long

typedef struct {
	TLong a;	// price
	TLong b;	// limit
} store;

int comp(const void *p,const void *q){
    return ((store *)p)->a - ((store*)q)->a;
}

int main(int argc, char const *argv[])
{
	TLong n,m;
	TLong t_price = 0;
	TLong temp;
	store st[100000];
	scanf("%lld%lld",&n,&m);
	for (TLong i = 0; i < n; ++i)	scanf(" %lld%lld", &st[i].a, &st[i].b);

	qsort(st,n,sizeof(store),comp);
	for (int i = 0; (i < n && m > 0); ++i)
	{
		temp = (st[i].b <= m) ? st[i].b : m;
		t_price += st[i].a * temp;
		m -= temp;
	}
	printf("%lld\n",t_price);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:25:32: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (TLong i = 0; i < n; ++i) scanf(" %lld%lld", &st[i].a, &st[i].b);
                                ^