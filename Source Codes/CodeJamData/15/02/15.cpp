#include <cstdio>
#include <algorithm>
#include <cstring>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)

int n, a[1007];

int main(){
	int T; scanf("%d", &T);
	f(_, 1, T){
		scanf("%d", &n);
		f(i, 1, n) scanf("%d", a + i);
		int ans = 2333333;
		f(j, 1, 1000){
			int cans = j;
			f(i, 1, n) cans += (a[i] - 1) / j;
			if(cans < ans) ans = cans;
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
