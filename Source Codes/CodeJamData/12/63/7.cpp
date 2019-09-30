#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>

using namespace std;

const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int maxn = 105;

int n;
int x[maxn], y[maxn];
char c[maxn][3];

bool check(int X1, int Y1, int X2, int Y2) {
	int u = abs(X1) + abs(Y1) - abs(X2) - abs(Y2);
	if(u!=0) return u<0;

	if(X1 != X2) return X1 > X2;

	return Y1 > Y2;
}

int dist(int X1, int Y1, int X2, int Y2) {
	return max(abs(X1 - X2), abs(Y1 - Y2));
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		fprintf(stderr, "%d\n", test);
		scanf("%d", &n);

		for(int i=0; i<n; i++) {
			scanf("%d%d%s", &x[i], &y[i], &c[i]);
		}
		
		int ansx = -1000, ansy = -1000;

		for(int dx = -400; dx <= 400; dx++) {
			for(int dy = -400; dy <= 400; dy++) {
				if(check(ansx, ansy, dx, dy)) continue;


				bool ok = true;
				for(int i=0; i<n && ok; i++) {
					int u = dist(dx, dy, x[i], y[i]);

					if(*c[i] == '.') {
						if(u%2==1) ok = false;
					} else if(*c[i]=='#') {
						if(u%2==0) ok = false;
					}
				}

				if(ok) {
					ansx = dx;
					ansy = dy;
				}
			}
		}

		printf("Case #%d: ", test);
		if(ansx == -1000) printf("Too damaged\n");
		else printf("%d %d\n", ansx, ansy);
	}
	return 0;
}