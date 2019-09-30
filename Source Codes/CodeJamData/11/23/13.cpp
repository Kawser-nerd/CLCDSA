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
int n,m;
set<int> e[2222];
int st[2222];
int fn[2222];
VI cyc[2222];
map< pii, pii >  who;
inline void del(int st,int fn,int num)
{
	e[st].erase(e[st].find(-fn));
	st%=n;
	fn%=n;
	if (st>fn)
		swap(st,fn);
	if (who.find(mp(st,fn))==who.end())
		who[mp(st,fn)]=mp(num,-1);
	else
		who[mp(st,fn)]=mp(who[mp(st,fn)].x,num);
}
int color[2222];
int used[2222];
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>tests;
	for(int tk=1;tk<=tests;++tk)
	{
		cerr<<tk<<endl;
		cin>>n>>m;
		rp(i,n)
		{
			e[i].clear();
			cyc[i].clear();
		}
		who.clear();
		rp(i,m)
		{
			cin>>st[i];
			st[i]--;
		}
		rp(i,m)
		{
			cin>>fn[i];
			fn[i]--;
		}
		rp(i,m)
		{
			e[st[i]].insert(-fn[i]);
			e[fn[i]].insert(-(st[i]+n));
		}
		rp(i,n)
			e[i].insert(-(i+1));
		int ck=0;
		int ans=inf;
		rp(i,n)
			while(L(e[i]))
			{
				int st=i;
				int cur=st;
				do
				{
					int nxt=*e[cur].lower_bound(-(st+n));
					if (L(cyc[ck])==1 && -nxt==st+n)
					{
						set<int>::iterator it=e[cur].lower_bound(-(st+n));
						it++;
						nxt=*it;
					}
					del(cur,-nxt,ck);
					cur=-nxt;
					cyc[ck].pb(cur%n);
				}while(cur!=st+n);
				ans=min(ans,L(cyc[ck]));
				ck++;
			}
		rp(i,n)
		{
			color[i]=-1;
			used[i]=0;
		}
		queue<int> q;
		q.push(0);
		while(!q.empty())
		{
			int cur=q.front();
			used[cur]=2;
			q.pop();
			VI nums(ans);
			rp(i,ans)
				nums[i]=i;
			int pos=0;
			if (cur)
			{
				while(color[cyc[cur][pos]]==-1)
					++pos;
				nums.erase(find(nums.begin(),nums.end(),color[cyc[cur][pos]]));
				nums.erase(find(nums.begin(),nums.end(),color[cyc[cur][pos+1]]));
				nums.insert(nums.begin(),color[cyc[cur][pos+1]]);
				nums.insert(nums.begin(),color[cyc[cur][pos]]);
			}
			int m=L(cyc[cur]),now,whos;
			for(now=pos,whos=0;now!=pos+m;++now,whos++)
				color[cyc[cur][now%m]]=nums[whos%ans];
			--now;
			while(color[cyc[cur][now%m]]==color[cyc[cur][(now+m-1)%m]]
				||color[cyc[cur][now%m]]==color[cyc[cur][(now+1)%m]])
				{
					color[cyc[cur][now%m]]=whos%ans;
					whos++;
				}
			rp(i,m)
			{
				int st=cyc[cur][i];
				int fn=cyc[cur][(i+1)%m];
				if (fn<st)
					swap(st,fn);
				int one=who[mp(st,fn)].x;
				int two=who[mp(st,fn)].y;
				if (one!=-1 && !used[one])
				{
					q.push(one);
					used[one]=1;
				}
				if (two!=-1 && !used[two])
				{
					q.push(two);
					used[two]=1;
				}
			}
		}	
		cout<<"Case #"<<tk<<": ";
		cout<<ans<<endl;
		rp(i,n)
		{
			if (i)
				cout<<" ";
			cout<<color[i]+1;
		}
		cout<<endl;
	}
}
