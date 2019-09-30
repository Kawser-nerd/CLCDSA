#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long int lli;



int main(void){
	int n;
	int i;
	int j;
	lli t;
	lli p,q;
	lli x;
	lli *a;
	lli **d;
	lli ans=0;
	scanf("%d%lld",&n,&x);
	a = calloc(sizeof(lli),n);
	d = calloc(sizeof(lli*),n);
	for(i = 0;i < n;i++){
		d[i] = calloc(sizeof(lli),n);
		scanf("%lld",&a[i]);
		ans += d[i][0] = a[i];
	}
	for(i = 1;i < n;i++){
		t = i*x;
		for(j = 0;j < n;j++){
			p = a[(j-i+n)%n];
			q = d[j][i-1];
			t += d[j][i] = p<q?p:q;
		}
		ans = ans<t?ans:t;
	}
	printf("%lld\n", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&n,&x);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^