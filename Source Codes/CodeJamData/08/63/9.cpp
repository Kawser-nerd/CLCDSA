#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 15;
const double AIM = 1000000;

int main() {
	map<double, double, greater<double> > pMap[2];
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n, x;
		double p;
		scanf("%d%lf%d", &n, &p, &x);
		pMap[0].clear();
		pMap[0][AIM] = 1.0;
		pMap[0][0] = 0.0;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			int next = !cur;
			map<double, double, greater<double> >::const_iterator iu, id;
			pMap[next] = pMap[cur];
			for (iu = pMap[cur].begin(); iu != pMap[cur].end() && iu->first > 0; ++iu) {
				for (id = iu, ++id; id != pMap[cur].end(); ++id) {
					//printf("%d %lf %lf\n", i + 1, (id->first + iu->first) / 2.0, p * iu->second + (1 - p) * id->second); 
					double & np = pMap[next][(id->first + iu->first) / 2.0];
					np = max(np, p * iu->second + (1 - p) * id->second);
				}
			}
			cur = next;
		}
		printf("Case #%d: %.7lf\n", caseIndex, pMap[cur].lower_bound(x)->second);
		
	}

	return 0;
}
