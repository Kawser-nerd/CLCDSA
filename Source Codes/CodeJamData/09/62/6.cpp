#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define fi first
#define se second

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)

#define MP make_pair
#define pb push_back

#define sqr(x) ((x)*(x))

struct Point {
	double x, y;	
};

int n;
Point a[1000010];
double best;
Point b[1000010];
int nb;

double dist(Point a, Point b) {
	return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));	
}

bool cmp1(Point a, Point b) {
	return a.x < b.x;
}

bool cmp2(Point a, Point b) {
	return a.y < b.y;	
}

void go(int l, int r) {
	if(r - l + 1 <= 3) {
		best <?= dist(a[l], a[l+1]) + dist(a[l+1], a[l+2]) + dist(a[l+2], a[l]);
		return;
	}
	if(r - l + 1 < 3) return;

	int mid = (l+r) / 2;
	double xmid = a[mid].x;
	go( l, mid);
	go( mid + 1, r);
	
	nb = 0;
	for(int i=l;i<=r;++i) if(abs(a[i].x - xmid) <= best) b[nb++] = a[i];
	
	sort( b, b + nb, cmp2);
	for(int i=0;i<nb;++i) for(int j=i+1;j<nb;++j) {
		if(b[j].y - b[i].y >= best) break;
		for(int k=j+1;k<nb;++k) {
			if(b[k].y - b[j].y >= best) break;
			best <?= dist( b[i], b[j]) + dist(b[j], b[k]) + dist(b[k], b[i]);	
		}	
	}
}

int main() {
    int ntest;
    scanf("%d", &ntest);
    for(int test=1;test<=ntest;++test) {
		scanf("%d", &n);
		for(int i=0;i<n;++i) scanf("%lf%lf", &a[i].x, &a[i].y);
		best = 1e11;
		sort(a, a+n, cmp1);
		go(0, n-1);
		printf("Case #%d: %.10f\n", test, best);
    }
    return 0;
}
