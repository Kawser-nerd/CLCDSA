#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <fstream>
#include <list>
using namespace std;
#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int
int tests;
int n;
string s[111];
double f[111],g[111],h[111];
int tot[111];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>tests;
	for(int tk=1;tk<=tests;++tk)
	{
		cin>>n;
		rp(i,n)
			cin>>s[i];
		rp(i,n)
			f[i]=g[i]=h[i]=tot[i]=0;
		rp(i,n)
			rp(j,n)
			if (s[i][j]!='.')
				tot[i]++;
		rp(i,n)
		{
			rp(j,n)
				if (s[i][j]=='1')
					f[i]++;
			if (tot[i])
				f[i]/=tot[i];
		}
		rp(i,n)
		{
			rp(j,n)
				if (s[i][j]!='.')
			{
				int tt=0;
				double cn=0;
				rp(k,n)
					if (k!=i)
					{
						if (s[j][k]!='.')
							tt++;
						if (s[j][k]=='1')
							cn++;
					}
				if (tt)
					cn/=tt;
				g[i]+=cn;
			}
			if (tot[i])
				g[i]/=tot[i];
		}
		rp(i,n)
		{
			rp(j,n)
				if (s[i][j]!='.')
					h[i]+=g[j];
			if (tot[i])
				h[i]/=tot[i];
		}
		cout<<"Case #"<<tk<<":\n";
		rp(i,n)
			printf("%0.9lf\n",0.25*f[i]+0.5*g[i]+0.25*h[i]);
	}
}
