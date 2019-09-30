#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using D = double;
using ii = pair<int, int>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

struct tsob
{
	ld x;
	int d;
	int id;
};

inline bool operator<(const tsob &a, const tsob &b)
{
	return a.x < b.x;
}

vector<tsob> sobs;
priority_queue<pair<int, int>> cur, todel;
set<int> ans;
set<int> open;

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 1; T <= NT; T++)
	{
		printf("Case #%d:", T);
		
		int n, ri;
		scanf("%d%d", &n, &ri);
		ld r = (ld)ri / 1000000;
		sobs.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) if (i || j)
			{
				ld angle = atan2(j, i);
				ld d = sqrt((ld)i * i + (ld)j * j);
				ld dif = asin(r / d);
				sobs.pb({angle - dif, i + j, i * n + j});
				sobs.pb({angle + dif, i + j, i * n + j});
			}
		}
		sort(all(sobs));
		ld last = -1e100;
		ans.clear();
		while (!cur.empty()) cur.pop();
		while (!todel.empty()) todel.pop();
		for (auto s : sobs)
		{
			if (s.x - last > 1e-10)
			{
				while (!cur.empty() && !todel.empty() && todel.top().se == cur.top().se)
				{
					todel.pop();
					cur.pop();
				}
				if (!cur.empty()) ans.insert(cur.top().se);
			}
			last = s.x;
			int id = s.id;
			if (open.count(id))
			{
				todel.push({-s.d, id});
				open.erase(id);
			} else
			{
				cur.push({-s.d, id});
				open.insert(id);
			}
		}
		printf(" %d\n", ans.size());
		
		fprintf(stderr, "%d/%d tests completed!\n", T, NT);
	}

}
