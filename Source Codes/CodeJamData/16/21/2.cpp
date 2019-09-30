#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	string strs[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	int cnts[10][26] = {};
	int masks[26] = {};
	rep(d, 10) {
		for(char c : strs[d])
			++ cnts[d][c - 'A'];
	}

	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ++ ii) {
		string S;
		cin >> S;

		int rem[26] = {};
		for(char c : S)
			++ rem[c - 'A'];
		int ord[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
		string ans;
		rep(i, 10) {
			int d = ord[i];
			while(1) {
				bool ok = true;
				rep(a, 26) ok &= rem[a] >= cnts[d][a];
				if(!ok) break;
				ans += char('0' + d);
				rep(a, 26) rem[a] -= cnts[d][a];
			}
		}
		sort(all(ans));

		printf("Case #%d: %s\n", ii + 1, ans.c_str());
	}
	return 0;
}
