//azariamuh

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

int inf = 1000000000;
typedef long long LL;

#define forn(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define reset(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()

int T,x,r,c;

int main()
{
	scanf("%d",&T);
	forn(cases,1,T)
	{
		printf("Case #%d: ",cases);
		scanf("%d %d %d",&x,&r,&c);
		if (r > c) swap(r,c);
		if ((r * c) % x != 0) 
		{
			puts("RICHARD");
			continue;
		}
		if (x == 1) puts("GABRIEL");
		if (x == 2) puts("GABRIEL");
		if (x == 3)
		{
			if (r < 2 || c < 2) puts("RICHARD");
			else puts("GABRIEL");
		}
		if (x == 4)
		{
			if (r < 3 || c < 4) puts("RICHARD");
			else puts("GABRIEL");
		}
		if (x == 5)
		{
			if (r < 3 || c < 5) puts("RICHARD");
			else if (r == 3 && c == 5) puts("RICHARD");
			else puts("GABRIEL");
		}
		if (x == 6)
		{
			if (r < 4 || c < 6) puts("RICHARD");
			//else if (r == 3 && c == 6) puts("RICHARD");
			else puts("GABRIEL");
		}
		if (x >= 7)
		{
			puts("RICHARD");
		}
	}
	return 0;
}













