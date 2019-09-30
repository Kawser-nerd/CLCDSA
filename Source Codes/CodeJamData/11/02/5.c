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
	map<int, int> cvt;
	map<int, int> opp;
	int is_base[256];
}
using namespace gdata;
void init()
{
	const char* bs = "QWERASDF";
	for (int i = 0; bs[i]; ++i) is_base[bs[i]] = 1;
}
int read()
{
	cvt.clear(), opp.clear();
	int a = Rint();
	for (int i = 0; i < a; ++i)
	{
		char buff[8];scanf("%s", buff);
		int a = buff[0], b = buff[1], c = buff[2];
		cvt[a<<10|b] = c;
		cvt[b<<10|a] = c;
	}
	a = Rint();
	for (int i = 0; i < a; ++i)
	{
		char buff[8];scanf("%s", buff);
		int a = buff[0], b = buff[1];
		opp[a<<10|b] = 1;
		opp[b<<10|a] = 1;
	}
	return 1;
}

int work()
{
	int ans[1024] = {0};
	int n = Rint();
	char buff[1024];scanf("%s", buff);
	int top = 0;
	for (int i = 0; buff[i]; ++i)
	{
		int ok = 0;
		ans[top] = buff[i];
		if (top > 0)
		{
			int hash = (ans[top] * 1024) | ans[top-1];
			map<int, int>::iterator where = cvt.find(hash);
			if (where != cvt.end())
			{
				ans[top-1] = where->second;
				ok = 1;
			}
		}
		if (ok) continue;
		int clr = 0;
		if (is_base[ans[top]])
		for (map<int, int>::iterator curr = opp.begin(); curr != opp.end(); ++curr)
		{
			if (ans[top] == (curr->first & 1023))
			{
				int can = 0;
				int dest = curr->first >> 10;
				for (int i = 0; i < top; ++i) if (ans[i] == dest) {can = 1;break;}
				if (can) {clr = 1;break;}
			}
		}
		if (clr) top = 0;
		else ++top;
	}
	printf("Case #%d: [", caseID);
	if (top == 0) {puts("]");return 1;}
	printf("%c", ans[0]);
	for (int i = 1; i < top; ++i) printf(", %c", ans[i]);
	puts("]");
	return 1;
}

int main()
{
	init();
	for (cas = Rint(); cas--&&read(); work(), ++caseID);
	//for (;read(); work(), ++caseID);
	return 0;
}