#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

inline int sqr(int x) { return x * x; }

const int maxn = 1005;
const ld inf = 1e9;

int x[maxn], y[maxn], z[maxn];
int vx[maxn], vy[maxn], vz[maxn];
bool can[maxn];
set<int> gr[maxn];
vector<pair<ld, pair<int, int>>> sobs;
set<pair<ld, int>> cool;
ld t[maxn];
int n, S;
int kv[maxn];

inline pair<ld, ld> gettms(int a, int b, ld d)
{
	int A = sqr(vx[a] - vx[b]) + sqr(vy[a] - vy[b]) + sqr(vz[a] - vz[b]);
	int B = 2 * ((vx[a] - vx[b]) * (x[a] - x[b]) + (vy[a] - vy[b]) * (y[a] - y[b]) + (vz[a] - vz[b]) * (z[a] - z[b]));
	int C = sqr(x[a] - x[b]) + sqr(y[a] - y[b]) + sqr(z[a] - z[b]);
	if (A == 0)
	{
		assert(B == 0);
		if (C > d * d) return {0, -1};
		return {0, inf};
	}
	ld D = (ld)B * B - 4 * A * (C - d * d);
	if (D < 0) return {0, -1};
	D = sqrt(abs(D));
	ld t1 = (-B - D) / 2 / A;
	ld t2 = (-B + D) / 2 / A;
	if (t2 < 0) return {0, -1};
	t1 = max(t1, (ld)0);
// 	cout << "gettms " << a << ' ' << b << ' ' << d << ' ' << t1 << ' ' << t2 << endl;
	return {t1, t2};
}

int cnt = 0;

void go(int cur)
{
	if (can[cur]) return;
	can[cur] = true;
	cnt++;
	for (auto t : gr[cur]) go(t);
}

bool cann(ld d)
{
// 	cout << "cann " << d << endl;
	sobs.clear();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			auto tms = gettms(i, j, d);
			if (tms.fi < tms.se)
			{
// 				cout << "add " << tms.fi << ' ' << tms.se << endl;
				sobs.pb({tms.fi, {i, j}});
				sobs.pb({tms.se, {i, j}});
			}
		}
	}
	sort(all(sobs));
	for (int i = 0; i < n; i++)
	{
		can[i] = false;
		kv[i] = 0;
		gr[i].clear();
	}
	can[0] = true;
	t[0] = 0;
	cool.clear();
	cool.insert({0, 0});
	for (auto s : sobs)
	{
// 		cout << s.fi << ' ' << s.se.fi << ' ' << s.se.se << endl;
		while (!cool.empty() && cool.begin()->fi < s.fi - S)
		{
			can[cool.begin()->se] = false;
			cool.erase(cool.begin());
		}
		int a = s.se.fi;
		int b = s.se.se;
		if (gr[a].count(b))
		{
			gr[a].erase(b);
			gr[b].erase(a);
			kv[a]--;
			kv[b]--;
			
			if (kv[a] == 0)
			{
				t[a] = s.fi;
				cool.insert({s.fi, a});
			}
			if (kv[b] == 0)
			{
				t[b] = s.fi;
				cool.insert({s.fi, b});
			}
		} else
		{
			gr[a].insert(b);
			gr[b].insert(a);
			if (kv[a] == 0 && can[a]) cool.erase({t[a], a});
			if (kv[b] == 0 && can[b]) cool.erase({t[b], b});
			kv[a]++;
			kv[b]++;
			if (can[a] || can[b])
			{
				go(a);
				go(b);
			}
		}
		if (can[1]) return true;
	}
	return false;
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
		scanf("%d%d", &n, &S);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d%d", &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
		}
		ld l = 0;
		ld r = 3000;
		for (int IT = 0; IT < 100; IT++)
		{
			ld m = (l + r) / 2;
			if (cann(m)) r = m;
			else l = m;
		}
		printf(" %.9lf\n", (double)r);
		
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    cerr << cnt << endl;
    return 0;
}
