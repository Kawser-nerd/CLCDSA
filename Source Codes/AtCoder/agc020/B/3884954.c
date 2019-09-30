#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	long long int k, s[200050] = {},left,right,memo=0;
	scanf("%lld", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &s[i]);
	}
	if (s[k]!=2) { printf("-1"); return 0; }
	left = 2;
	right = 2;
	for (int i = k - 1; i > 0; i--) {
      
		left = (((left-1) / s[i]) + 1)*s[i];
		right = (((right+s[i+1]-1) / s[i]))*s[i];
      if(right<left){printf("-1"); return 0;}
	}
	printf("%lld %lld", left, right + s[1] - 1);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &k);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &s[i]);
   ^