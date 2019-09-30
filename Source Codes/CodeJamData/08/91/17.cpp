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

int N;
int w[6000][4];
set<int> pos;
int ord[6000];
int fen[30000];

const int MAX = 10000;

bool cmp(int i, int j) {
	return w[i][1] < w[j][1];
};

void add(int x) {
	while (x <= 20000) {
		fen[x]++;
		x += x & (-x);
	}
}

int get(int x) {
	int r = 0;
	while (x) {
		r += fen[x];
		x &= x-1;
	}
	return r;
}

int check(int ca, int cb, int cc) {
	if (ca < 0 || cb < 0 || cc < 0) return 0;
	/*cout << ca << " "  << cb << " "  << cc << endl;
	cout << get(cc+1) << endl;*/
	return get(cc+1);
}

int main() {
	int casos, res;
	cin >> casos;
	REP(caso, casos) {
		cin >> N;
		REP(i, N) REP(j, 3) cin >> w[i][j];
		pos.clear(); pos.insert(0); pos.insert(MAX);
		REP(i, N) pos.insert(w[i][0]), ord[i] = i;
		sort(ord, ord+N, cmp);
		res = 0;
		FOREACH(it, pos) {
			int vala = *it;
			int valb = 0;
			CLEAR(fen, 0);
			REP(i, N) {
				if (w[ord[i]][0] > vala) continue;
				valb = max(valb, w[ord[i]][1]);
				add(w[ord[i]][2]+1);
				res = max(res, check(vala, valb, MAX - vala - valb));
			}
		}
		cout << "Case #" << caso+1 << ": " << res << endl;
	}
	return 0;
}
