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
	int data[1005];
	int n;
}
using namespace gdata;

int read()
{
	n = Rint();
	for (int i = 1; i <= n; ++i) data[i] = Rint();
	return 1;
}

int work()
{
	int can = 0;
	for (int i = 1; i <= n; ++i) can ^= data[i];
	if (can)
	{
		printf("Case #%d: NO\n", caseID);
		return 1;
	}
	sort(data+1, data+n+1);
	int ans = 0;
	int a = 0, c = 0, s = 0;
	for (int i = n; i > 1; --i)
	{
		s += data[i];
		a ^= data[i];
		c ^= data[i];
		if (a == c)
		{
			if (s > ans) ans = s;
		}
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