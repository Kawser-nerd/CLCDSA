#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
#include<unordered_set>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 4 * 1000 * 1000 + 47;
const int MOD = 998244353;

map<string, int> M;

void ADD(int& key, int val)
{
	key += val;
	if (key >= MOD) key -= MOD;
}

int f(const string& s)
{
	//cout << "!!" << s << endl;
	if (SZ(s) == 0) return 1;
	if (SZ(s) == 1)
	{
		if (s[0] == '1') return 2;
		return 1;
	}

	if (M.find(s) != M.end()) return M[s];

	int res = 0;
	int tmp = f(s.substr(1, SZ(s)));
	ADD(res, tmp);
	if (s[0] == '1') ADD(res, tmp);

	FOR(len, 1, SZ(s))
	{
		string cur = s.substr(0, len);

		FOR(k, 0, SZ(s) / len - 1)
		{
			FOR(i, 0, len)
			{
				cur[i] = ((cur[i] - '0') & (s[len * (k + 1) + i] - '0')) + '0';
			}

			int tmp = (f(cur) * (LL)f(s.substr(len * (k + 2), SZ(s)))) % MOD;
			ADD(res, tmp);
		}
	}

	return M[s] = res;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	cout << f(s) << endl;
	//for (auto i = M.begin(); i != M.end(); i++)
	//{
	//	cout << i->first << ": " << i->second << endl;
	//}
}