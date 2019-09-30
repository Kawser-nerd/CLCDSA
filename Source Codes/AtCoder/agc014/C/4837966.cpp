#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#define LL long long
#define MP make_pair
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
int n,m,k;
char c[810][810];
int s1,s2;
int res=0;
priority_queue< pair<PII, PII> > pq;
int d1[4]={0,0,1,-1};
int d2[4]={1,-1,0,0};
PII d[810][810];
inline bool ok(int x,int y)
{
	return x>=0 && y>=0 && x<n && y<m;
}
int main()
{
	cin >>n>>m>>k;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin >>c[i][j];
			if (c[i][j]=='S')
			{
				s1=i;
				s2=j;
				c[i][j]='.';
			}
			d[i][j]=MP(1e9,0);
		}
	}
	d[s1][s2]=MP(0,-k);
	pq.push(MP(MP(0,-k),MP(s1,s2)));
	while (!pq.empty())
	{
		int t=-pq.top().F.F;
		int tt=pq.top().F.S;
		int x=pq.top().S.F;
		int y=pq.top().S.S;
		pq.pop();
		if (d[x][y]!=MP(t,tt)) continue;
		if (x==0 || x==n-1 || y==0 || y==m-1)
		{
			cout <<(t+k-1)/k;
			return 0;
		}
		if (t%k==0) tt+=k;
		//cout <<x<<" "<<y<<" "<<t<<" "<<tt<<" ###\n";
		bool fl=0;
		for (int i=0;i<4;i++)
		{
			int xi=x+d1[i];
			int yi=y+d2[i];
			if (!ok(xi,yi) || (c[xi][yi]=='#' && !tt)) continue;
			if (c[xi][yi]=='#')
			{
			    if (d[xi][yi].F<t+1 || (d[xi][yi].F==t+1 && d[xi][yi].S>=tt-1))
				    continue;
			    fl=1;
				d[xi][yi]=MP(t+1,tt-1);
			    pq.push(MP(MP(-(t+1),tt-1),MP(xi,yi)));
			}
			else
			{
				if (d[xi][yi].F<t+1 || (d[xi][yi].F==t+1 && d[xi][yi].S>=tt))
				    continue;
			    fl=1;
				d[xi][yi]=MP(t+1,tt);
			    pq.push(MP(MP(-(t+1),tt),MP(xi,yi)));
			}
		}
		if (!fl)
		{
			pq.push(MP(MP(-(t+k-(t%k)),tt),MP(x,y)));
			d[x][y]=MP(t+k-(t%k),tt);
		}
	}
	return 0;
}