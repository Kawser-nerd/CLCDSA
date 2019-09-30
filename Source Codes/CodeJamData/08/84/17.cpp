#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
using namespace std;

const int MODULO = 30031;

int n, k, p;

void Load()
{
	scanf("%d%d%d", &n, &k, &p);
}

class State
{
public:
	int c[11];
};

bool operator<(const State &a, const State &b)
{
	int i;
	for (i = 0; i < p; i++)
	{
		if (a.c[i] < b.c[i]) return true;
		if (a.c[i] > b.c[i]) return false;
	}
	return false;
}

map<State, int> res[1100];

int mto[50];

void ReColor(State &a)
{
	memset(mto, 0, sizeof(mto));
	int i;
	int kk = 1;
	for (i = 0; i < p; i++)
	{
		if (a.c[i] == 0) continue;
		if (mto[a.c[i]] == 0) { mto[a.c[i]] = kk; kk++; }
		a.c[i] = mto[a.c[i]];
	}
}

void CountGoes(int i, State a, int num)
{
	int j;
	for (j = 1; j <= p; j++)
	{
		if ((j < p) && (a.c[j] != 0)) continue;
		State b;
		memset(b.c, 0, sizeof(b.c));
		int k;
		for (k = 1; k < p; k++) b.c[k - 1] = a.c[k];
		b.c[j - 1] = a.c[0];
		if (b.c[0] == 0) continue;
		ReColor(b);
		if (res[i + 1].find(b) == res[i + 1].end()) res[i + 1][b] = 0;
		res[i + 1][b] = (res[i + 1][b] + num) % MODULO;
	}
}

void Solve()
{
	State be;
	memset(be.c, 0, sizeof(be.c));
	int i;
	for (i = 0; i <= n; i++) res[i].clear();
	for (i = 0; i < k; i++) be.c[i] = i + 1;
	res[0][be] = 1;
	// here we go
	for (i = 0; i < n - k; i++)
	{
		map<State, int>::iterator cur;
		for (cur = res[i].begin(); cur != res[i].end(); cur++)
		{
			CountGoes(i, cur->first, cur->second);
		}
	}
	// here we need answer
	map<State, int>::iterator cur;
	int ans = 0;
	for (cur = res[n - k].begin(); cur != res[n - k].end(); cur++)
	{
		State q = cur->first;
		int ii;
		set<int> aa;
		aa.clear();
		int f = 1;
		for (ii = n; ii >= n - k + 1; ii--)
		{
			if (q.c[ii - n + k - 1] == 0) { f = 0; break; }
			if (aa.find(q.c[ii - n + k - 1]) != aa.end()) { f = 0; break; }
			aa.insert(q.c[ii - n + k - 1]);
		}
		if (f == 1) 
		{
			ans = (ans + cur->second) % MODULO;
		}
	}
	cout << ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}