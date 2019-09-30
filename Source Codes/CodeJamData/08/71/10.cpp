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

vi sons[2000];
map<string, int> name;
int M, N;

int get_id(string x) {
	if (name.find(x) == name.end()) {
		int g = SZ(name);
		name[x] = g;
	}
	return name[x];
}

int go(int x) {
	if (SZ(sons[x]) == 0) return 1;
	int res = SZ(sons[x]) + 1;
	vi vals;
	REP(i, SZ(sons[x])) vals.pb(go(sons[x][i]));
	sort(all(vals));
	reverse(all(vals));
	REP(i, SZ(sons[x])) res = max(res, i + vals[i]);
	return res;
}

int main() {
	string a;
	int casos;
	cin >> casos;
	REP(caso, casos) {
		name.clear();
		REP(i, 2000) sons[i].clear();
		cin >> N;
		REP(i, N) {
			cin >> a;
			int source = get_id(a);
			cin >> M;
			REP(j, M) {
				cin >> a;
				if (isupper(a[0])) {
					sons[source].pb(get_id(a));
				}
			}
		}
		cout << "Case #" << caso+1 << ": " << go(0) << endl;
	}
	return 0;
}
