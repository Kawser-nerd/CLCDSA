#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> pii;

struct node
{
	int r, c, k;
	node(int r = 0, int c = 0, int k = 0): r(r), c(c), k(k) {}
	bool operator < (const node & K) const
	{
		if (k != K.k) return k > K.k;
		if (r != K.r) return r < K.r;
		return c < K.c;
	}
};

char f[512][512+1];
int  b[512][512];
int n, m;

vector<pii> solve()
{
	map<int, int> mres;
	
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
		{
			b[i][j] = 1;
			if (i < n -1 && j < m - 1)
			{
				int k = min(min(b[i+1][j], b[i][j+1]), b[i+1][j+1]);
				if (f[i+1][j+1] == f[i][j] && f[i+1][j] == f[i][j+1] && f[i][j] != f[i+1][j])
					b[i][j] = k + 1;
			}
		}
	
	set<node> s;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		node K;
		K.r = i; K.c = j; K.k = b[i][j];
		s.insert(K);
	}
	
	while (s.size())
	{
		node K = *s.begin();
		mres[K.k]++;
		for (int i = K.r - K.k; i < K.r + K.k; i++)
			for (int j = K.c - K.k; j < K.c + K.k; j++)
			{
				if (i < 0 || j < 0 || b[i][j] == 0) continue;
				if (K.r <= i && K.c <= j)
				{
					node D(i, j, b[i][j]);
					s.erase(s.find(D));
					b[i][j] = 0;
				}
				else
				{
					node D(i, j, b[i][j]);
					s.erase(s.find(D));
					int z = max(0, min(i + b[i][j] - K.r, j + b[i][j] - K.c));
					b[i][j] -= z;
					D.k = b[i][j];
					s.insert(D);
				}
			}
	}
	
	vector<pii> res;
	for (map<int, int>::iterator im = mres.begin(); im != mres.end(); im++)
		res.push_back(make_pair(im->first, im->second));
	return res;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	//freopen("C-small.in", "r", stdin);
	//freopen("C-small.out", "w", stdout);
	
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		cin >> n >> m;
		memset(f, 0, sizeof f);
		for (int i = 0; i < n; i++)
		{
			char s[200];
			cin >> s;
			for (int j = 0; j < m / 4; j++)
			{
				int z = s[j] >= 'A' ? s[j] - 'A' + 10 : s[j] - '0';
				for (int k = 0; k < 4; k++)
					f[i][j*4+3-k] = (z & (1 << k)) ? 1 : 0;
			}
		}
		vector<pii> res = solve();
		cout << "Case #" << test << ": " << res.size() << endl;
		sort(res.begin(), res.end());
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++)
			cout << res[i].first << ' ' << res[i].second << endl;
	}
	
	return 0;
}