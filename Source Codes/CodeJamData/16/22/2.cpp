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

string C, J;
bool ord;
typedef pair<ll, pair<ll, ll>> Val;
Val memo[21][2];
Val rec(int i, int borrow) {
	Val &r = memo[i][borrow];
	if(r.first != -1) return r;
	if(i == C.size()) {
		if(borrow != 0)
			return r = Val(INFL, mp(INFL, INFL));
		else
			return r = Val(0, mp(0, 0));
	}
	r = Val(INFL, mp(INFL, INFL));
	char cd = C[C.size() - 1 - i], jd = J[J.size() - 1 - i];
	rep(c, 10) rep(j, 10) {
		if(cd != '?' && cd != c + '0') continue;
		if(jd != '?' && jd != j + '0') continue;
		int x = (!ord ? c - j : j - c) - borrow;
		int nb = 0;
		if(x < 0) x += 10, nb = 1;
		Val t = rec(i + 1, nb);
		if(t.first != INFL)
			amin(r, Val(t.first * 10 + x, mp(t.second.first * 10 + c, t.second.second * 10 + j)));
	}
	return r;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ++ ii) {
		cin >> C >> J;
		Val ans(INFL, mp(INFL, INFL));
		rep(k, 2) {
			ord = k != 0;
			mset(memo, -1);
			Val t = rec(0, 0);
			amin(ans, t);
		}
		string anss;
		{
			ll x = ans.second.second;
			rep(i, C.size()) {
				anss += char('0' + x % 10);
				x /= 10;
			}
		}
		anss += ' ';
		{
			ll x = ans.second.first;
			rep(i, C.size()) {
				anss += char('0' + x % 10);
				x /= 10;
			}
		}
		reverse(all(anss));
		printf("Case #%d: %s\n", ii + 1, anss.c_str());
	}
	return 0;
}
