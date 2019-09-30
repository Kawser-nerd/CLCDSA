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

struct point {
	double x, y;
} p[10000];

double dist(point a, point b) {
	a.x -= b.x; a.y -= b.y;

	return sqrt(a.x * a.x + a.y * a.y);
}

point get(point a, point b) {
	double d = dist(a, b);
	double v = atan2(a.y - b.y, a.x - b.x);

	v -= pi / 2;

	point res = b;
	res.x += cos(v) * d;
	res.y += sin(v) * d;

	return res;
}

point o;
double ans;
int n, m;

void dfs(point now, int m) {
	if(dist(now, o) > ans) ans = dist(now, o);

	if(m==0) {
		return;
	}

	for(int i=0; i<n; i++) {
		dfs(get(now, p[i]), m-1);
	}
}

vector<int> v;

bool dfs2(point now, int m) {
	if(fabs(dist(now, o) - ans) < 1e-7) {
		for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
		printf("\n");
		return true;
	}

	if(m==0) {
		return false;
	}

	for(int i=0; i<n; i++) {
		v.push_back(i);
		dfs2(get(now, p[i]), m-1);
		v.pop_back();
	}

	return false;
}

int a[4];

int main() {
	
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		fprintf(stderr, "%d\n", test);
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		
		o.x = o.y = 0; ans = 0;

		for(a[0]=0; a[0]<n; a[0]++) for(a[1]=0; a[1]<n; a[1]++) for(a[2]=0; a[2]<n; a[2]++) for(a[3]=0; a[3]<n; a[3]++) {
			point now; now.x = now.y = 0;
			for(int i=0; i<m; i++) {
				now = get(now, p[a[i%4]]);

				if(dist(now, o) > ans) ans = dist(now, o);
			}
		}

		printf("Case #%d: %.10lf\n", test, ans);
	}
	return 0;
}