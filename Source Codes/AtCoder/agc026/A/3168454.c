#include <stdio.h>

#define ARC(i, a, b) for(int i = (a); i < (b); ++i)
#define RC(i, n) ARC(i, 0, n)

int main(){
	unsigned n, a, p, ans = 0, cnt = 0;
	scanf("%u", &n);
	scanf("%u", &p);
	RC(i, n - 1){
		scanf("%u", &a);
		if(a == p) ++cnt;
		else{
			ans += (cnt + 1) / 2;
			cnt = 0;
		}
		p = a;
	}
	ans += (cnt + 1) / 2;
	printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%u", &n);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%u", &p);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u", &a);
   ^