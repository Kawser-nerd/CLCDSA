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
	int data[1024];
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
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += data[i] != i;
	printf("Case #%d: %d.000000\n", caseID, ans);
	return 1;
}

int main()
{
	for (cas = Rint(); cas--&&read(); work(), ++caseID);
	//for (;read(); work(), ++caseID);
	return 0;
}