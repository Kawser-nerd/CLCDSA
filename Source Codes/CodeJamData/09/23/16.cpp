// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;
typedef pair<short, int> PCI;
map<int, string> found[20][20];
char f[32][33];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d:\n", scen);
		int w, q;
		scanf("%d %d", &w, &q);
		for (int i=0; i<w; ++i)
			scanf("%s", f[i]);
		while(q--) {
			int want;
			queue<PCI> Q;
			scanf("%d", &want);
			bool flag = false;
			for (int i=0; i<w; ++i)
				for (int j=0; j<w; ++j) {
					found[i][j].clear();
					if (isdigit(f[i][j])) {
						found[i][j][f[i][j]-'0'] = string(1, f[i][j]);
						Q.push(PCI(i*w + j, f[i][j]-'0'));
						if (f[i][j] - '0' == want)
							flag = true;
					}
				}
			if (flag) {
				printf("%d\n", want);
				continue;
			}
			int nval;
			string ops, best;
			while(!Q.empty()) {
				PCI e = Q.front();
				Q.pop();
				int x = e.first / w;
				int y = e.first % w;
				map<int, string>::iterator it = found[x][y].find(e.second);
				assert(it != found[x][y].end());
				if (best.size() > 0 && it->second.size() >= best.size())
					break;
				for (int dx=-2; dx<=2; dx+=2) {
					int tx = x + dx;
					if (tx < 0 || tx >= w)
						continue;
					for (int dy=-2; dy<=2; dy+=2) {
						if (dx && dy || !dx && !dy)
							continue;
						int ty = y + dy;
						if (ty < 0 || ty >= w)
							continue;
						if (f[x + dx/2][y + dy/2] == '+') {
							nval = e.second + f[tx][ty] - '0';
							ops = string(1, f[tx][ty]) + "+" + found[x][y][e.second];
						}
						else {
							assert(f[x + dx/2][y + dy/2] == '-');
							nval = e.second - 2 * (f[x][y] - '0') + f[tx][ty] - '0';
							ops = string(1, f[tx][ty]) + "-" + found[x][y][e.second];
						}
						if (nval == want) {
							if (best.size() == 0 || best.size() == ops.size() && ops < best)
								best = ops;
						}
						if (found[tx][ty].find(nval) == found[tx][ty].end()) {
							found[tx][ty][nval] = ops;
							Q.push(PCI(tx * w + ty, nval));
						}
						else {
							string &s = found[tx][ty][nval];
							if (s.size() == ops.size() && ops < s)
								s = ops;
						}
					}
				}
				for (int dx=-1; dx<=1; ++dx) {
					int tx = x + dx;
					if (tx < 0 || tx >= w)
						continue;
					for (int dy=-1; dy<=1; ++dy) {
						if (abs(dx) != abs(dy))
							continue;
						int ty = y + dy;
						if (ty < 0 || ty >= w)
							continue;
						bool has_plus = false;
						bool has_minus = false;
						if (dx) {
							if (f[x + dx][y] == '+')
								has_plus = true;
							else {
								assert(f[x + dx][y] == '-');
								has_minus = true;
							}
							if (f[x][y + dy] == '+')
								has_plus = true;
							else {
								assert(f[x][y + dy] == '-');
								has_minus = true;
							}
						}
						else {
							assert(dx == 0 && dy == 0);
							for (int dx2=-1; dx2<=1; ++dx2)
								for (int dy2=-1; dy2<=1; ++dy2) {
									if (abs(dx2) + abs(dy2) != 1)
										continue;
									if (x + dx2 >= 0 && x + dx2 < w && y + dy2 >= 0 && y + dy2 < w) {
										if (f[x + dx2][y + dy2] == '+')
											has_plus = true;
										else {
											assert(f[x + dx2][y + dy2] == '-');
											has_minus = true;
										}
									}
								}
						}
						if (has_plus) {
							nval = e.second + f[tx][ty] - '0';
							ops = string(1, f[tx][ty]) + "+" + found[x][y][e.second];
							if (nval == want) {
								if (best.size() == 0 || best.size() == ops.size() && ops < best)
									best = ops;
							}
							if (found[tx][ty].find(nval) == found[tx][ty].end()) {
								found[tx][ty][nval] = ops;
								Q.push(PCI(tx * w + ty, nval));
							}
							else {
								string &s = found[tx][ty][nval];
								if (s.size() == ops.size() && ops < s)
									s = ops;
							}
						}
						if (has_minus) {
							nval = e.second - 2 * (f[x][y] - '0') + f[tx][ty] - '0';
							ops = string(1, f[tx][ty]) + "-" + found[x][y][e.second];
							if (nval == want) {
								if (best.size() == 0 || best.size() == ops.size() && ops < best)
									best = ops;
							}
							if (found[tx][ty].find(nval) == found[tx][ty].end()) {
								found[tx][ty][nval] = ops;
								Q.push(PCI(tx * w + ty, nval));
							}
							else {
								string &s = found[tx][ty][nval];
								if (s.size() == ops.size() && ops < s)
									s = ops;
							}
						}
					}
				}
			}
			assert(best.size() > 0);
			puts(best.c_str());
		}
	}
	return 0;
}
