#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))

#define MOD 2


lli exeuclid(lli a,lli aa,lli x,lli xx,lli y,lli yy){
	lli q;
	if(a == 0) return aa > 0 ? xx : -xx;
	q = aa / a;
	return exeuclid(aa - q * a,a,xx - q * x,x,yy - q * y,y);
}

lli invarse(lli x){
	return exeuclid(MOD,x,0,1,1,0);
}

lli det(lli **a,int n){
	lli d = 1.0;
	lli buf;
	int j;
	for(int i = 0;i < n;i++){
		if(a[i][i] == 0){
			lli *swap;
			swap = a[i];
			for(j = i + 1;j < n;j++) if(a[j][i] != 0) break;
			if(j == n) return 0;
			a[i] = a[j];
			a[j] = swap;
		}
		for(j = i + 1;j < n;j++){
			buf = a[j][i];
			for(int k = i;k < n;k++){
				a[j][k] -= a[i][k]*buf;
				a[j][k] = abs(a[j][k]) % MOD;
			}
		}
		d *= a[i][i];
		d %= MOD;
	}
	return d;
}

int main(void){
	int n;
	lli **s;
	char *st;
	char *ans[] = {"Even","Odd"};

	int i,j;
	int r;
	scanf("%d",&n);
	s = calloc(sizeof(lli*),n);
	st = calloc(sizeof(char),n);
	for(i=0;i<n;i++){
		s[i] = calloc(sizeof(lli),n);
		scanf("%s",st);
		for(j=0;j<n;j++){
			s[i][j] = st[j] - '0';
		}
	}
	r = (int)det(s,n);
	//printf("%d\n", r);
	printf("%s\n", ans[abs(r) % 2]);


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:64:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",st);
   ^