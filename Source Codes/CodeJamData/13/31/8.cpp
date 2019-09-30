#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int n;
string str;
int sum[1000100];
int nxt[1000100];

bool is_co( char ch )
{
	if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return false;
	return true;
}

void sol()
{
	int ans = 0;
	int z = SZ(str);
	FOR(a,0,z-1) FOR(b,a,z-1)
	{
		int mx = 0;
		int co = 0;
		FOR(c,a,b)
		{
			if (is_co(str[c])) co++;
			else co = 0;
			mx = max( mx, co );
		}
		if (mx>=n) ans++;
	}
	cout << ans;
}

void sol2()
{
	int z = SZ(str);
	FOR(a,1,z)
	{
		sum[a] = sum[a-1];
		if (is_co(str[a-1])) sum[a]++;
	}

	FOR(a,1,z-n+1)
	{
		nxt[a] = nxt[a-1];
		if (sum[a+n-1]-sum[a-1]==n) nxt[a] = a;
	}

	LL ans = 0;
	FOR(a,1,z-n+1) ans += nxt[a];

	cout << ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	FOR(a,1,T)
	{
		cin >> str >> n;
		cout << "Case #" << a << ": ";
		//sol();
		//cout << " ";
		sol2();
		cout << "\n";
	}

	return 0;
}
