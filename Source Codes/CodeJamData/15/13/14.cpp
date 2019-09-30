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


template<typename T>
struct pt
{
	T x, y;

	pt() {}
	pt(const T& a, const T& b) : x(a), y(b) {}

	pt operator + (const pt& P) const
	{
		return {x + P.x, y + P.y};
	}
	pt operator - (const pt& P) const
	{
		return {x - P.x, y - P.y};
	}
	pt operator * (const T& s) const
	{
		return {x * s, y * s};
	}
	T operator * (const pt& P) const
	{
		return x * P.x + y * P.y;
	}
	T operator ^ (const pt& P) const
	{
		return x * P.y - y * P.x;
	}
	T dot(const pt& P) const
	{
		return (*this) * P;
	}
	T cross(const pt& P) const
	{
		return (*this) ^ P;
	}
	T norm2() const
	{
		return x * x + y * y;
	}
	double angle() const
	{
		return atan2(y, x);
	}
	bool operator < (const pt& P) const
	{
		if (x != P.x)
			return x < P.x;
		else
			return y < P.y;
	}
};
typedef pt<ll> lpt;

const double PI = acos(-1);

int N;
lpt pts[3000];

int main()
{
	nrint(T);
	// int T = 14;
	for (int test = 1; test <= T; test++)
	{
		rint(N);
		// N = 3000;
		ji(N)
		{
			rlong(pts[i].x);
			rlong(pts[i].y);
		}
		// ji(N)
		// {
		// 	pts[i].x = i;
		// 	pts[i].y = i * 7;
		// }
		int ans[N];
		ji(N)
		{
			vector<pair<double, lpt> > V;
			jj(N) if (i != j)
			{
				lpt o = pts[j];
				double angle = (o - pts[i]).angle();
				while (angle < 0) angle += PI * 2;
				V.pb({angle, o});
				V.pb({angle + PI * 2, o});
			}
			sort(V.begin(), V.end());
			int pos = 0;
			ans[i] = INF;
			jj(V.size())
			{
				if (V[j].first >= PI * 2)
					break;
				while (pos < V.size() && (V[pos].first < V[j].first + PI / 2 || ((V[j].second - pts[i]) ^ (V[pos].second - pts[i])) > 0))
					pos++;
				ans[i] = min(ans[i], pos - j - 1);
			}
		}
		if (N == 1) ans[0] = 0;
		printf("Case #%d:\n", test);
		ji(N) printf("%d\n", ans[i]);
	}
}
