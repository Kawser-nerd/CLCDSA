#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 512;
const double INF = 1e+100;

int n;
double speed;
double pos[SIZE];
double vel[SIZE];

struct Guy {
	double pos;
	double vel;
	bool operator< (const Guy &other) const {
		if (vel != other.vel)
			return vel > other.vel;
		return fabs(pos) > fabs(other.pos);
	}
};
vector<Guy> arr[2];
double res[SIZE][SIZE];
int k[2];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%lf%d", &speed, &n);
		for (int i = 0; i < n; i++)
			scanf("%lf", &pos[i]);
		for (int i = 0; i < n; i++)
			scanf("%lf", &vel[i]);

		arr[0].clear();
		arr[1].clear();
		for (int i = 0; i<n; i++) {
			Guy g;
			g.vel = vel[i];
			g.pos = fabs(pos[i]);
			if (pos[i] < 0)
				arr[0].push_back(g);
			else
				arr[1].push_back(g);
		}

		for (int t = 0; t < 2; t++) {
			sort(arr[t].begin(), arr[t].end());
			k[t] = arr[t].size();

			for (int i = 0; i < k[t]; i++)
				Ef("[%0.1lf %0.1lf] ", arr[t][i].vel, arr[t][i].pos);
			Ef("\n");
		}
		
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				res[i][j] = INF;

		double ans = INF;
		res[0][0] = 0.0;	
		int z[2];
		for (z[0] = 0; z[0] <= k[0]; z[0]++)
			for (z[1] = 0; z[1] <= k[1]; z[1]++) {
				double nowt = res[z[0]][z[1]];
				if (nowt >= sqrt(INF))
					continue;
				Ef("%d %d: %0.3lf\n", z[0], z[1], nowt);
				for (int s = 0; s < 2; s++) {
					double maxDt = 0.0;
					double critPos = 0.0;
					for (int d = 1; z[s] + d <= k[s]; d++) {
						int nz0 = z[0] + (s==0 ? d : 0);
						int nz1 = z[1] + (s==1 ? d : 0);

						int last = z[s] + d - 1;
						const auto &g = arr[s][last];
						double dt = (g.pos + g.vel * nowt) / (speed - g.vel);
						maxDt = max(maxDt, dt);
/*						if (dt > maxDt) {
							maxDt = dt;
							critPos = g.pos + g.vel * (nowt + dt);
						}*/
						double cAt = speed * maxDt;

                        double nres = nowt + maxDt;
                        if (nz0 == k[0] && nz1 == k[1])
                        	ans = min(ans, nres);
                        else {
                        	nres += cAt / speed;
                        	auto &xx = res[nz0][nz1];
                        	xx = min(xx, nres);
						}
                        //Ef("%d %d (%d %d):  %0.3lf -> %0.3lf\n", z[0], z[1], s, d, nowt, nres);
					}
				}
			}

		printf("Case #%d: %0.12lf\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
