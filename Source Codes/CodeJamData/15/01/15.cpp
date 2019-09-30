#include <cstdio>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)

char a[233333];

int main(){
	int T; scanf("%d", &T);
	f(_, 1, T){
		int n; scanf("%d%s", &n, a + 1);
		int s = 0, ans = 0;
		f(i, 1, n){
			s += (a[i] - '0');
			if(s < i){
				ans += i - s; s = i;
			}
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
