#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define SZ(x) ((int)(x).size())

typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<string> vs; typedef long long ll;

int Q, M;
double prob[100][10];
double best[50][50000];
int cant[50];
double aux[10][50000];

bool cmp(double i, double j) {return i > j;}

int main() {
	int casos;
	cin >> casos;
	REP(caso, casos) {
		cin >> M >> Q;
		REP(i, Q) cin >> prob[i+1][0] >> prob[i+1][1] >> prob[i+1][2] >> prob[i+1][3];
		//printf("%Ld\n", 1LL<<(2*Q));
		/*if (M > (1LL<<(2*Q))) {
			printf("warning\n");
			M = 1LL<<(2*Q);
		}*/
		cant[0] = 1; best[0][0] = 1.0;
		for (int i = 1; i <= Q; i++) {
			int n = cant[i-1];
			REP(k, 4) copy(best[i-1], best[i-1] + n, aux[k]);
			REP(k, 4) REP(j, n) aux[k][j] *= prob[i][k];
			merge(aux[0], aux[0] + n, aux[1], aux[1] + n, aux[4], cmp);
			merge(aux[2], aux[2] + n, aux[3], aux[3] + n, aux[5], cmp);
			merge(aux[4], aux[4] + 2*n, aux[5], aux[5] + 2*n, best[i], cmp);
			cant[i] = min(4*n, M);
			//REP(j, cant[i]) printf("%f ", best[i][j]);
			//printf("\n");
		}
		double res  = 0.0;
		REP(i, min(cant[Q], M)) res += best[Q][i];
		cout << "Case #" << caso+1 << ": " << fixed << setprecision(6) << res << endl;
	}
	return 0;
}
