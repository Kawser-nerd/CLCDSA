/*
 NOTE:
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <set>
#define MP make_pair
#define F first
#define S second
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;

string s; 
int k;
string rk[11];
string hp[7];
int st = 0;


int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
 	ios::sync_with_stdio(false);
	cin >> s >> k;
	for (int i = 1; i <= 10; i ++)
		rk[i] = (char)('z' + 1);
	for (int i = 0; i < s.size(); i ++) {
		string t = "";
		st = min(5, (int)(s.size() - i));
		for (int j = 1; j <= st; j ++)
			hp[j] = s.substr(i, j);
		sort(hp + 1, hp + st + 1);
		for (int j = 1; j <= 5; j ++)
			rk[j + 5] = (char)('z' + 1);
		for (int j = 1; j <= st; j ++)
			rk[j + 5] = hp[j];
		sort(rk + 1, rk + 10 + 1);
		for (int j = 10; j >= 2; j --)
			if (rk[j] == rk[j - 1])
				rk[j] = (char)('z' + 1);
		sort(rk + 1, rk + 10 + 1);
	}
	cout << rk[k] << endl;
	return 0;
}
/*
*/