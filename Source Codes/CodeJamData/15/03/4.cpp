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
#define ford(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define reset(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()

int T;
int kali[6][6] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
int n;
long long x;
string s;
int pre[10005];
int suf[10005];
long long kecil,besar;

int mul(int a,int b)
{
	int res = 1;
	if (a < 0) res *= -1, a *= -1;
	if (b < 0) res *= -1, b *= -1;
	return (res * kali[a-1][b-1]);
}

int ubah(char x)
{
	if (x == 'i') return 2;
	if (x == 'j') return 3;
	return 4;
}

int pangkat(int x,long long y)
{
	if (y == 1) return x;
	int temp = pangkat(x,y/2);
	if (y % 2 == 0) return mul(temp,temp);
	return mul(mul(temp,temp),x);
}

int main()
{
	scanf("%d",&T);
	forn(cases,1,T)
	{
		printf("Case #%d: ",cases);
		cin >> n >> x;
		cin >> s;
		pre[0] = ubah(s[0]);
		forn(i,1,n-1)
		{
			pre[i] = mul(pre[i-1],ubah(s[i]));
		}
		if (pangkat(pre[n-1],x) != -1)
		{
			puts("NO");
			continue;
		}
		suf[n-1] = ubah(s[n-1]);
		ford(i,n-2,0)
		{
			suf[i] = mul(ubah(s[i]),suf[i+1]);
		}
		kecil = besar = -1;
		int now = 1;
		forn(i,0,min(32LL,x-1))
		{
			forn(j,0,n-1)
			{
				if (mul(now,pre[j]) == 2)
				{
					kecil = i * n + j;
					break;
				}
			}
			if (kecil != -1) break;
			now = mul(now,pre[n-1]);
		}
		now = 1;
		forn(i,0,min(32LL,x-1))
		{
			forn(j,0,n-1)
			{
				//printf("%d\n",suf[j]);
				if (mul(suf[n-1-j],now) == 4)
				{
					besar = x * n - (i * n + j) - 1;
					break;
				}
			}
			if (besar != -1) break;
			now = mul(suf[0],now);
		}
		//printf("%lld %lld\n",kecil,besar);
		puts(kecil < besar ? "YES" : "NO");
	}
	return 0;
}













