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

int T,n;
string s;

int main()
{
	scanf("%d",&T);
	forn(cases,1,T)
	{
		scanf("%d",&n);
		cin >> s;
		int cek = 0;
		int ans = 0;
		forn(i,0,s.size()-1) {
			if (cek < i) {
				++ans;
				cek = i;
			}
			cek += s[i] - '0';
		}
		printf("Case #%d: %d\n",cases,ans);
	}
	return 0;
}













