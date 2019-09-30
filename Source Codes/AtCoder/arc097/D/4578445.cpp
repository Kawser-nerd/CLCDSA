#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+1;
vector<int> es[L];
char col[L+10];
map<int,int> mf[L],mg[L],mh[L];
int hitf[L];
int pref[L];
int f(int r,int p)
{
	if(mf[r].count(p))
	{
		return mf[r][p];
	}
	if(r==0)
	{
		return mf[r][p]=0;
	}
	if(col[r]=='W')
	{
		return mf[r][p]=1;
	}
	
	if(hitf[r]==0)
	{
		pref[r]=p;
		for(auto i:es[r])
		{
			if(i!=p&&f(i,r))
			{
				hitf[r]=i;
				return mf[r][p]=1;
			}
		}
		hitf[r]=-1;
	}
	else if(hitf[r]==p)
	{
		for(auto i:es[r])
		{
			if(i!=p&&f(i,r))
			{
				return mf[r][p]=1;
			}
		}
	}
	else if(hitf[r]>0)
	{
		return mf[r][p]=1;
	}
	else
	{
		return mf[r][p]=f(pref[r],r);
	}
	return mf[r][p]=0;
}

int sumg[L];
int preg[L];
int cntg[L];
int g(int r, int p)
{
	if(mg[r].count(p))
	{
		return mg[r][p];
	}
	if(f(r,p)==0)
	{
		return mg[r][p]=0;
	}
	int sum=0;
	int cnt=0;
	if(sumg[r]==-1)
	{
		preg[r]=p;
		for(auto i:es[r])
		{
			if(i!=p)
			{
				if(f(i,r))
				{
					sum+=g(i,r)+2;
					cnt++;
				}
			}
		}
		sumg[r]=sum;
		cntg[r]=cnt;
	}
	else
	{
		sum=sumg[r];
		cnt=cntg[r];
		if(f(p,r))
		{
			sum-=g(p,r)+2;
			cnt--;
		}
		if(f(preg[r],r))
		{
			sum+=g(preg[r],r)+2;
			cnt++;
		}
	}
	if(p==0)
	{
		cnt++;
	}
	if(col[r]=='B')
	{
		cnt++;
	}
	if(cnt%2)
	{
		sum++;
	}
	//cerr << "g " << r << ", " << p << ": " << sum << endl;
	return mg[r][p]=sum;
}

int sumh[L];
int preh[L];
int mxh[L];
int mx2h[L];
int cnth[L];
int h(int r,int p)
{
	if(mh[r].count(p))
	{
		return mh[r][p];
	}
	if(f(r,p)==0)
	{
		//cerr << "aaa " << r << ", " << p << endl;
		return mh[r][p]=0;
	}
	int sum=0;
	int mx=0;
	int cnt=0;
	if(sumh[r]==-1){
		preh[r]=p;
		int mx2=0;
		for(auto i:es[r])
		{
			if(i!=p){
				if(f(i,r))
				{
					sum+=g(i,r)+2;
					int d=g(i,r)+2-(h(i,r)+1);

					if(mx<d)
					{
						mx2=mx;
						mx=d;
					}
					else if(mx2<d)
					{
						mx2=d;
					}
					cnt++;
				}
			}
		}
		sumh[r]=sum;
		cnth[r]=cnt;
		mxh[r]=mx;
		mx2h[r]=mx2;
	}
	else
	{
		sum=sumh[r];
		cnt=cnth[r];
		mx=mxh[r];
		if(f(p,r))
		{
			sum-=g(p,r)+2;
			int d=g(p,r)+2-(h(p,r)+1);
			if(mx==d)
			{
				mx=mx2h[r];
			}
			cnt--;
		}
		if(f(preh[r],r))
		{
			sum+=g(preh[r],r)+2;
			int d=g(preh[r],r)+2-(h(preh[r],r)+1);
			if(mx<d)
			{
				mx=d;
			}
			cnt++;
		}
	}
	if(cnt==0)
	{
		if(p==0)
		{
			sum=1;
		}
		return mh[r][p]=sum;
	}
	if(p==0)
	{
		cnt++;
	}
	if(col[r]=='W')
	{
		cnt++;
	}
	if(cnt%2)
	{
		sum++;
	}
	sum-=mx;
	int v=min(sum,g(r,p));
	//cerr << "h " << r << ", " << p << ": " << v << endl;
	return mh[r][p]=v;


}


int main() {
	//memset(hitf,-1,sizeof(hitf));
	memset(sumg,-1,sizeof(sumg));
	memset(sumh,-1,sizeof(sumh));
	int N;
	cin >> N;
	for(int i=1;i<N;i++){
		int x,y;
		cin >> x >> y;
		es[x].push_back(y);
		es[y].push_back(x);
	}
	col[0]='B';
	cin >> (col+1);
	bool any=false;
	for(int i=1;i<=N;i++)
	{
		if(col[i]=='W'){
			any=true;
			break;
		}
	}
	if(!any)
	{
		cout << 0 << endl;
		return 0;
	}
	int ret=1<<20;
	for(int i=1;i<=N;i++)
	{
		ret=min(ret,h(i,0));
	}
	cout << ret << endl;

	return 0;
}