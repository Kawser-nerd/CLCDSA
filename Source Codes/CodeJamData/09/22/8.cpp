#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

template<class T> T abs(T x){ return x > 0 ? x : (-x); }
template<class T> T sqr(T x){ return x * x; }

void solve(int testnum)
{
	printf("Case #%d: ", testnum + 1);
	string s;
	cin >> s;
	string tmp = s;
	string res;
	if (next_permutation(all(tmp)))
		res = tmp;
	else
	{
		cerr << "2nd case\n";
		string v;
		int zc = 0;
		for (int i = 0; i < sz(s); i++)
		{
			if (s[i] != '0')
				v += s[i];
			else
				zc++;
		}
		sort(all(v));
		zc++;
		res += v[0];
		res += string(zc, '0');
		for (int i = 1; i < sz(v); i++)
			res += v[i];
	}
	cout << res;
	printf("\n");
}

int main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; it++)
	{
		solve(it);
	}
	return 0;
}
