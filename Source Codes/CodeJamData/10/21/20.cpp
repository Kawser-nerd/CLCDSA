#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

set<string> S;

void Solve()
{
	S.clear();
	S.insert("");
	char ts[1000];
	gets(ts);
	int n, m;
	sscanf(ts, "%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		gets(ts);
		S.insert(string(ts));
	}
	int res = 0;
	for (int it = 0; it < m; it++)
	{
		gets(ts);
		string s;
		for (int i = 0; ts[i]; i++)
		{
			if (ts[i] == '/')
			{
				if (!S.count(s)) S.insert(s), res++;
			}
			s += ts[i];
		}
		if (!S.count(s)) S.insert(s), res++;
	}
	cout << res << "\n";
}

int main()
{
	char ts[100];
	gets(ts);
	int nc;
	sscanf(ts, "%d", &nc);
	for (int it = 0; it < nc; it++)
	{
		printf("Case #%d: ", it + 1);
		Solve();
	}
	return 0;
}
