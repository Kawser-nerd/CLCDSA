#include <bits/stdc++.h>

#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)

#define LL long long
#define Ldouble long double
#define PI 3.1415926535897932384626

#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int t, n, m;
char g[105][105], ans[105][105];
int ro[105], co[105], d1[205], d2[205];

int res[405][405];
int q[405], l, r, pv[405], vis[405], rec[205];
int M, E;

bool bfs(){
	l = 0;
	q[r = 1] = 0;
	
	FI(i, 0, E) pv[i] = -1, vis[i] = 0;
	pv[0] = -2; vis[0] = 1;
	
	while(l < r){
		int cur = q[++l];
		FI(i, 0, E){
			if(!vis[i] && res[cur][i] > 0){
				q[++r] = i;
				vis[i] = 1;
				pv[i] = cur;
			}
		}
	}
	
	if(pv[E] == -1) return false;
	
	int U = E;
	while(U){
		if(U > M) rec[U - M] = pv[U];
		res[pv[U]][U]--;
		res[U][pv[U]]++;
		U = pv[U];
	}
	return true;
}

void solve2(){
	M = n + n;
	E = M + M + 1;
	memset(res, 0, sizeof(res));
	memset(rec, -1, sizeof(rec));
	FI(i, 1, n) FI(j, 1, n) if(d1[i + j] == 0 && d2[i + (n - j)] == 0){
		res[i + j][M + i + (n - j)] = 1;
	}
	
	FI(i, 1, M){
		if(d1[i] == 0) res[0][i] = 1;
		if(d2[i] == 0) res[M + i][E] = 1;
	}
	
	
	while(bfs());
	
	FI(i, 1, n) FI(j, 1, n) if(rec[i + (n - j)] == i + j){
		if(ans[i][j] == '.') ans[i][j] = '+';
		else ans[i][j] = 'o';
	}
	
	
	
	return;
}

void solve(){
	FI(i, 1, n) ro[i] = co[i] = 0;
	FI(i, 0, n + n) d1[i] = d2[i] = 0;
	
	FI(i, 1, n) FI(j, 1, n){
		ans[i][j] = g[i][j];
		if(ans[i][j] == '+' || ans[i][j] == 'o'){
			d1[i + j] = 1;
			d2[i + (n - j)] = 1;
		}
		if(ans[i][j] == 'x' || ans[i][j] == 'o'){
			ro[i] = 1;
			co[j] = 1;
		}
	}
	
	//At least, the row/col part can be easily done :)
	FI(i, 1, n) FI(j, 1, n){
		if(ans[i][j] == '.' || ans[i][j] == '+'){
			if(ro[i] == 0 && co[j] == 0){
				ro[i] = co[j] = 1;
				if(ans[i][j] == '.') ans[i][j] = 'x';
				else ans[i][j] = 'o';
			}
		}
	}
	
	//The diagonal part is tricky! Need to use flow...
	solve2();
	
	int dif = 0, score = 0;
	FI(i, 1, n) FI(j, 1, n){
		if(ans[i][j] != g[i][j]) dif++;
		if(ans[i][j] == '+') score++;
		else if(ans[i][j] == 'x') score++;
		else if(ans[i][j] == 'o') score += 2;
	}
	printf("%d %d\n", score, dif);
	FI(i, 1, n) FI(j, 1, n){
		if(ans[i][j] != g[i][j]){
			printf("%c %d %d\n", ans[i][j], i, j);
		}
	}
}

int main(){
	freopen("D-large.in", "r", stdin);
	freopen("D2.out", "w", stdout);
	scanf("%d", &t);
	FI(tt, 1, t){
		scanf("%d %d", &n, &m);
		FI(i, 1, n) FI(j, 1, n) g[i][j] = '.';
		FI(i, 1, m){
			char a;
			int b, c;
			scanf("\n%c %d %d", &a, &b, &c);
			g[b][c] = a;
		}
		printf("Case #%d: ", tt);
		solve();
	}
	return 0;
}

