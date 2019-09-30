#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

struct Point {
	int x, y;
};

double sqr(double x) {
	return x*x;
}

double dist(Point a, Point b) {
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

double p(Point a, Point b, Point c) {
	return dist(a,b) + dist(b,c) + dist(c,a);
}

double minPsimple(const vector<Point> &pts) {
	unsigned int i1=0, i2=1;
	double minDist = dist(pts[0], pts[1]);
	for (unsigned int i=0; i<pts.size(); i++)
		for (unsigned int j=0; j<i; j++)
			if (dist(pts[i],pts[j])<minDist) {
				i1 = i;
				i2 = j;
				minDist = dist(pts[i],pts[j]);
			}

	double best = 1E20;
	for (unsigned int i=0; i<pts.size(); i++)
		if (i!=i1 && i!=i2)
			if (dist(pts[i1],pts[i])+dist(pts[i2],pts[i])<best)
				best = dist(pts[i1],pts[i])+dist(pts[i2],pts[i]);
	best += minDist;
	for (unsigned int a=0; a<pts.size(); a++) {
		for (unsigned int b=0; b<a; b++)
			if (dist(pts[a],pts[b])<best)
			for (unsigned int c=0; c<b; c++) {
				double res = p(pts[a],pts[b],pts[c]);
				if (res<best) best = res;
			}
	}
	return best;
}

int main() {
	int T;
	freopen("b.in", "r", stdin);
	FILE *fo = fopen("b.out", "w");
	scanf("%d", &T);
	vector<Point> pts;
	for (int t=1; t<=T; t++) {
		int n;
		pts.clear();
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			Point p;
			scanf("%d%d", &p.x, &p.y);
			pts.push_back(p);
		}
		double slow = minPsimple(pts);
		//printf("slow: %lf\n", slow);
		fprintf(fo, "Case #%d: %.16lf\n", t, slow);
		fflush(fo);
		printf("%d/%d\n", t, T);
	}
	fclose(fo);
	return 0;
}
