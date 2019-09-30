#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


long long mod = 1e9 + 7;
long long Mod(long long x)
{
	return x % mod;
}

struct Train
{
	bool innerLetter[30];
	int sl, el;
	Train() : innerLetter(), sl(), el() {}

	void print()
	{
		return;
		fprintf(stderr, "%c ", sl + 'a');
		for (int i = 0; i < 30; i++)
			if (innerLetter[i] )
				fprintf(stderr, "%c", i + 'a');
		fprintf(stderr, " %c\n", el + 'a');
	}
	void read()
	{
		char s[1005];
		scanf("%s", s);
		int len = strlen(s);
		sl = s[0] - 'a';
		el = s[len - 1] - 'a';
		memset(innerLetter, 0, sizeof innerLetter);
		for (int i = 1; i < len - 1; i++)
		{
			if (s[i] != s[0] && s[i] != s[len - 1] )
				innerLetter[s[i] - 'a'] = true;
			if (s[i] == s[0] && s[i] != s[i - 1] )
				innerLetter[s[i] - 'a'] = true;
			if (s[i] == s[len - 1] && s[i] != s[i + 1] )
				innerLetter[s[i] - 'a'] = true;
		}
	}
	bool hasInnerInter(Train A)
	{
		for (int i = 0; i < 30; i++)
		{
			if (innerLetter[i] && A.innerLetter[i] )
				return true;
			if (innerLetter[i] && A.sl == i)
				return true;
			if (innerLetter[i] && A.el == i)
				return true;
			if (A.innerLetter[i] && sl == i)
				return true;
			if (A.innerLetter[i] && el == i)
				return true;
		}
		if (A.sl == sl || A.el == el)
			return true;
		return false;
	}
	bool hasAnyInner()
	{
		for (int i = 0; i < 30; i++)
			if (innerLetter[i] )
				return true;
		return false;
	}
} train[105];


long long fact[105];

void init()
{
	fact[0] = 1;
	for (int i = 1; i < 105; i++)
		fact[i] = Mod(fact[i - 1] * i);
}

bool hasIn[105];
bool used[105];
vector <int> g[105];
int countFull[30];
bool letterUsed[30];

long long solve()
{
	for (int i = 0; i < 105; i++)
		g[i].clear();
	memset(hasIn, 0, sizeof hasIn);
	memset(countFull, 0, sizeof countFull);
	memset(used, 0, sizeof used);
	memset(letterUsed, false, sizeof letterUsed);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		train[i].read();
		train[i].print();
	}
	for (int i = 0; i < n; i++)
	{
		if (train[i].innerLetter[train[i].sl] || train[i].innerLetter[train[i].el] )
			return 0;
		if (train[i].sl == train[i].el && train[i].hasAnyInner() )
			return 0;
		if (train[i].sl == train[i].el)
		{
			countFull[train[i].sl]++;
			//fprintf(stderr, "!i = %d, %d, count = %d\n", i, train[i].sl, countFull[train[i].sl] );
			used[i] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] )
			continue;
		letterUsed[train[i].sl] = true;
		letterUsed[train[i].el] = true;
		for (int j = 0; j < n; j++)
		{
			if (used[j] )
				continue;
			if (i == j)
				continue;
			if (train[i].hasInnerInter(train[j] ) )
				return 0;
			if (train[i].el == train[j].sl)
			{
				g[i].push_back(j);
				hasIn[j] = true;
			}
		}
	}
	int K = 0;
	for (int i = 0; i < n; i++)
	{
		if (used[i] || hasIn[i] )
			continue;
		K++;
		int v = i;
		used[v] = true;
		while (g[v].size() > 0)
		{
			if (g[v].size() > 1)
				return 0;
			v = g[v][0];
			if (used[v] )
				return 0;
			used[v] = true;
		}
	}
	for (int i = 0; i < 30; i++)
		if (countFull[i] != 0 && !letterUsed[i] )
			K++;
	for (int i = 0; i < n; i++)
		if (!used[i] )
			return 0;
	//fprintf(stderr, "cf[0] = %d\n", countFull[0] );
	long long ans = fact[K];
	for (int i = 0; i < 30; i++)
		ans = Mod(ans * fact[countFull[i] ] );
	return ans;
}


char str[100500];
bool testS(string s)
{
	bool was[250];
	memset(was, 0, sizeof was);
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (was[s[i] ] && s[i - 1] != s[i] )
			return false;
		was[s[i] ] = true;
	}
	return true;
}
long long stupidSolve()
{
	int n;
	scanf("%d", &n);
	vector <string> s;
	vector <int> v;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		s.push_back(string(str) );
		v.push_back(i);
	}
	long long ans = 0;
	int id = 0;
	do
	{
		id++;
		//if (id % 10000 == 0)
		//	fprintf(stderr, "id = %d\n", id);
		string cur = "";
		for (int i = 0; i < n; i++)
		{
			cur += s[v[i] ];
		}
		if (testS(cur) )
			ans++;
	}
	while (next_permutation(v.begin(), v.end() ) );
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		fprintf(stderr, "Case #%d:\n\n", i);
		printf("Case #%d: ", i);
		printf("%lld", solve() );
		printf("\n");
		fprintf(stderr, "\n");
	}



	return 0;
}