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
int pos[222];
int cnt[222];
int n,d;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>tests;
	for(int tk=1;tk<=tests;++tk)
	{
		cerr<<tk<<endl;
		cin>>n>>d;
		rp(i,n)
			cin>>pos[i]>>cnt[i];
		long double high=1e30;
		long double low=0;
		rp(iter,200)
		{
			long double mid=(high+low)/2.;
			if (mid<1)
				mid=mid;
			long double last=-1e100;
			bool ok=1;
			rp(i,n)
				if (ok)
					rp(j,cnt[i])
					{
						long double nend=pos[i]-mid;
						if (nend<last+d)
							nend=last+d;
						if (nend>pos[i]+mid)
						{
							ok=0;
							break;
						}
						last=nend;
					}
			if (ok)
				high=mid;
			else
				low=mid;
		}
		cout<<"Case #"<<tk<<": ";
		printf("%0.9lf\n",(double)(high+low)/2.);
	}
}
