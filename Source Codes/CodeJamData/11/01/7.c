#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
using namespace std;

typedef long long int64;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}

namespace gdata
{
	int caseID = 1;
	int cas;
	int n;
	int data[105], who[105];
}
using namespace gdata;

int read()
{
	n = Rint();
	for (int i = 1; i <= n; ++i)
	{
		char buff[8];int x;
		scanf("%s%d", buff, &x);
		who[i] = buff[0] == 'O' ? 0 : 1;
		data[i] = x;
	}
	return 1;
}

int sign(int x)
{
	if (x == 0) return 0;
	return x < 0 ? -1 : 1;
}

int work()
{
	int ans = 0;
	int pos[2] = {1, 1};
	for (int i = 1; i <= n; ++i)
	{
		int move = who[i];
		int& x = pos[move];
		int& y = pos[move^1];
		int t = abs(data[i]-x) + 1;
		int j = i + 1;
		while (j <= n && who[j] == move) ++j;
		if (j <= n)
		{
			int d = sign(data[j] - y);
			int u = min(t, abs(data[j]-y));
			y += d * u;
		}
		x = data[i];
		ans += t;
	}
	printf("Case #%d: %d\n", caseID, ans);
	return 1;
}

int main()
{
	for (cas = Rint(); cas--&&read(); work(), ++caseID);
	//for (;read(); work(), ++caseID);
	return 0;
}