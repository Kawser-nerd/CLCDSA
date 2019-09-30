#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define pd(x) printf("%lf\n", x)
#define ps(x) printf("%s\n", x)
 
#define INF 1000000000000000000
#define MOD 1000000007
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int compare_long(const void *a, const void *b) {
	return *(long*)a - *(long*)b;
}
 
int main() {
	long H, W;
	long tmp;
	long low, mid, high;
	long min, max;
	long ans = INF;
	long i, j;
	
	sl(H); sl(W);
	for(i=0;i<2;i++) {
		low = 1; high = H; mid = (low + high) / 2;
		while(1) {
			if(mid * W <= H * W / 3 && (mid + 1) * W > H * W / 3) {
				break;
			}
			if(mid * W < H * W / 3) {
				low = mid + 1;
				mid = (low + high) / 2;
			} else {
				high = mid - 1;
				mid = (low + high) / 2;
			}
		}
		for(j=0;j<2;j++) {
			min = max = mid * W;
			if((H - mid) % 2 && W % 2) {
				if(H - mid > W) {
					min = MIN(min, (H - mid) / 2 * W);
					max = MAX(max, ((H - mid) / 2 + 1) * W);
				} else {
					min = MIN(min, (H - mid) * (W / 2));
					max = MAX(max, (H - mid) * (W / 2 + 1));
				}
			} else {
				min = MIN(min, (H - mid) * W / 2);
				max = MAX(max, (H - mid) * W / 2);
			}
			ans = MIN(ans, max - min);
			mid++;
		}
		tmp = H; H = W; W = tmp;
	}
	
	pl(ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:30:2: note: in expansion of macro ‘sl’
  sl(H); sl(W);
  ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:30:9: note: in expansion of macro ‘sl’
  sl(H); sl(W);
         ^