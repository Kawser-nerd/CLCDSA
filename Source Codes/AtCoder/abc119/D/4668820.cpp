#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <ctime>
#include <random>
#include <bitset>
#include <climits>
#include <cstring>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define ll long long
#define eps 1e-8
#define inf 1e17
using namespace std;

int main() {
	speed;
	ll a, b, q, x, v;
	cin >> a >> b >> q;
	set<ll>s, t;
	for (int i = 0; i < a; ++i) {
		cin >> v;
		s.insert(v);
	}
	for (int i = 0; i < b; ++i) {
		cin >> v;
		t.insert(v);
	}
	for (int i = 0; i < q; ++i) {
		cin >> x;
		auto q = s.lower_bound(x), w = t.lower_bound(x), pq = q, pw = w;
		if (q == s.begin())
			pq = s.end();
		else
			--pq;
		if (w == t.begin())
			pw = t.end();
		else
			--pw;
		ll ans = inf;
		if (q != s.end() && pw != t.end())
			ans = min({ans, min(*q - x, x - *pw) + *q - *pw, });
		if (pq != s.end() && w != t.end())
			ans = min({ ans, min(*w - x, x - *pq) + *w - *pq });
		if (q != s.end() && w != t.end())
			ans = min(ans, max(*w - x, *q - x));
		if (pq != s.end() && pw != t.end())
			ans = min(ans, max(x - *pw, x - *pq));
		cout << ans << '\n';
	}
}