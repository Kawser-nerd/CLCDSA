#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll N;
int B;
int M[1000];

ll countThem(ll t)
{
	ll ans = 0;
	ji(B) ans += (t + M[i] - 1) / M[i];
	return ans;
}

int main()
{
	nrint(T)
	for (int test = 1; test <= T; test++)
	{
		rint(B);
		rlong(N);
		ji(B) rint(M[i]);
		ll lo = 0;
		ll hi = (ll) 1e15;
		while (lo < hi)
		{
			ll mid = (lo + hi + 1) / 2;
			if (countThem(mid) < N)
				lo = mid;
			else
				hi = mid - 1;
		}
		ll T = lo;
		N -= countThem(T);
		int timeLeft[B];
		ji(B) timeLeft[i] = T % M[i];
		int last = -1;
		jk(N)
		{
			int idx = 0;
			ji(B) if (timeLeft[i] < timeLeft[idx])
				idx = i;
			int t = timeLeft[idx];
			ji(B) timeLeft[i] -= t;
			timeLeft[idx] = M[idx];
			last = idx;
		}
		printf("Case #%d: %d\n", test, last + 1);
	}
}
