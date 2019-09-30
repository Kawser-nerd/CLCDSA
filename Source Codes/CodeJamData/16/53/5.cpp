#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n,s;

struct aster {
	double x, y,z,vx,vy,vz;
};

aster aa[1100];
double dist[1100];
int mark[1100];

void read() {
	scanf("%d %d", &n, &s);
	REP(i,n) scanf("%lf %lf %lf %lf %lf %lf", &aa[i].x, &aa[i].y, &aa[i].z, &aa[i].vx, &aa[i].vy, &aa[i].vz);
}

double len(const aster &a, const aster &b) {
	double dx = a.x-b.x;
	double dy = a.y-b.y;
	double dz = a.z-b.z;
	return sqrt(dx*dx+dy*dy+dz*dz);
}

void solve() {
	REP(i,n) {
		mark[i] = 0;
		dist[i] = 1e18;
	}
	dist[0] = 0;

	REP(it,n) {
		int b = -1;
		REP(i,n) if (!mark[i]) {
			if (b == -1 || dist[i] < dist[b]) b = i;
		}

		mark[b] = 1;
		REP(i,n) {
			dist[i] = min(dist[i], max(dist[b], len(aa[b], aa[i])));
		}
	}

	printf("%.15f\n", dist[1]);
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
	if (argc > 1) {
		stringstream ss; ss << argv[1]; ss >> myMod;
		ss.str(""); ss.clear();
		ss << argv[2]; ss >> howMany;
	}

	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		read();
		if (i % howMany == myMod) {
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}