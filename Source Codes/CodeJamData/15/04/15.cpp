#include <cstdio>
#include <algorithm>
#include <cstring>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)

typedef long long LL;

int ans[22][22][22];
// 1 - first win
// 0 - first lose
// -1 - not calculated yet

int main(){
	memset(ans, 0xff, sizeof(ans));
	int cnt = 0;
	f(x, 1, 20) f(r, 1, 20) f(c, 1, 20) if(ans[x][r][c] == -1){
		if(ans[x][c][r] != -1) ans[x][r][c] = ans[x][c][r];
		else if(x >= 7) ans[x][r][c] = 1;
		else if(r * c % x != 0) ans[x][r][c] = 1;
		else if(r < x && c < x) ans[x][r][c] = 1;
		else if(r >= x && c >= x) ans[x][r][c] = 0;
		else if(x == 1) ans[x][r][c] = 0;
		else if(x == 2) ans[x][r][c] = 0;
		else if(x == 3) ans[x][r][c] = (r <= 1);
		else if(x == 4) ans[x][r][c] = (r <= 2);
		else if(x == 5){
			if(r <= 2) ans[x][r][c] = 1;
			else if(r == 3) ans[x][r][c] = (c < 10);
			else ans[x][r][c] = 0;
		}else ans[x][r][c] = (r <= 3);
	}
	f(x, 1, 20) f(r, 1, 20) f(c, 1, 20) if(ans[x][r][c] < 0 || ans[x][r][c] > 1) printf("WTF?\n");
	int T; scanf("%d", &T);
	f(_, 1, T){
		int x, l, r; scanf("%d%d%d", &x, &l, &r);
		if(ans[x][l][r]) printf("Case #%d: RICHARD\n", _);
		else printf("Case #%d: GABRIEL\n", _);
	}
	return 0;
}
