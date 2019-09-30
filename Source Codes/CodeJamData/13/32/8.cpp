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

int X, Y;

PAR do_moves( string str )
{
	int t=1;
	int x=0, y=0;
	FA(a,str)
	{
		if (str[a]=='N') y+=t;
		else if (str[a]=='S') y-=t;
		else if (str[a]=='E') x+=t;
		else x-=t;
		t++;
	}
	return make_pair( x, y );
}

void sol()
{
	string ans;

	FOR(a,1,X) ans = ans + "WE";
	FOR(a,X,-1) ans = ans + "EW";
	FOR(b,1,Y) ans = ans + "SN";
	FOR(b,Y,-1) ans = ans + "NS";

	ass( make_pair(X, Y) == do_moves( ans ) );

	cout << ans;
}

bool reacheble( int x, int y, int moves )
{
	int dist = (moves*(moves+1))/2;
	int dxy = abs(x)+abs(y);
	return (dxy <= dist && (dist&1) == (dxy&1));
}

void sol2()
{
	FOR(z,1,10000)
		if (reacheble( X, Y, z ))
		{
			string ans;
			int cx = X, cy = Y;
			DFOR(zz,z,1)
			{
				if ( reacheble( cx-zz, cy, zz-1 ) )
				{
					cx -= zz;
					ans += "E";
				}
				else if ( reacheble( cx+zz, cy, zz-1 ) )
				{
					cx += zz;
					ans += "W";
				}
				else if ( reacheble( cx, cy-zz, zz-1 ) )
				{
					cy -= zz;
					ans += "N";
				}
				else if ( reacheble( cx, cy+zz, zz-1 ) )
				{
					cy += zz;
					ans += "S";
				}
				else ass( false );
			}
			reverse( ans.begin(), ans.end() );

			ass( make_pair(X, Y) == do_moves( ans ) );

			cout << ans;
			return;
		}
	ass( false );
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	FOR(a,1,T)
	{
		cin >> X >> Y;
		cout << "Case #" << a << ": ";
		sol2();
		cout << "\n";
	}

	return 0;
}
