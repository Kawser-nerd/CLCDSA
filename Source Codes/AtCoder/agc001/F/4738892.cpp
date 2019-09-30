//Zory-2019
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<algorithm>
#include<iostream>
#include<deque>
// #include<unordered_map>
using namespace std;
int bin[40],lg[1<<21];
namespace mine
{
	typedef long long ll;
	#define double long double
	const int INF=0x3f3f3f3f;
	const ll LLINF=0x3f3f3f3f3f3f3f3fll;
	ll qread()
	{
		ll ans=0;char c=getchar();int f=1;
		while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num)
	{
		if(num<0) {num=-num;putchar('-');}
		if(num>9) write(num/10);
		putchar('0'+num%10);
	}
	void writeln(int num){write(num);puts("");}
	#define FR first
	#define SE second
	#define MP make_pair
	#define pr pair<int,int>
	#define PB push_back
	#define vc vector
	void chmax(int &x,const int y) {x=x>y?x:y;}
	void chmin(int &x,const int y) {x=x<y?x:y;}
	const int MAX_N=5e5+10;
	const int MOD=1e9+7;
	void add(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;if(x<0) x+=MOD;}

	struct SegmentTree
	{
		#define lc 2*x
		#define rc 2*x+1
		#define mid ((l+r)>>1)
		pr mx[MAX_N*4];
		void change(int x,int l,int r,int p,int c)
		{
			mx[x]=max(mx[x],MP(c,p));
			if(l==r) return;
			if(p<=mid) change(lc,l,mid,p,c);
			else change(rc,mid+1,r,p,c);
		}
		pr ask(int x,int l,int r,int fl,int fr)
		{
			if(fl>fr) return MP(0,0);
			if(l==fl and r==fr) return mx[x];
			if(fr<=mid) return ask(lc,l,mid,fl,fr);
			if(fl>mid) return ask(rc,mid+1,r,fl,fr);
			return max(ask(lc,l,mid,fl,mid),ask(rc,mid+1,r,mid+1,fr));
		}
	}sgt;

	int a[MAX_N],ans[MAX_N];
	int ru[MAX_N];vector<int> to[MAX_N];
	void ins(int x,int y) {ru[y]++;to[x].PB(y);}
	priority_queue<int> q;
	void main()
	{
		int n=qread(),K=qread();
		for(int i=1;i<=n;i++) a[qread()]=i;
		for(int i=1;i<=n;i++)
		{
			int num=a[i];sgt.change(1,1,n,num,i);
			pr a=sgt.ask(1,1,n,max(1,num-K+1),num-1);if(a.FR>0) ins(num,a.SE);
			pr b=sgt.ask(1,1,n,num+1,min(num+K-1,n));if(b.FR>0) ins(num,b.SE);
		}
		for(int i=1;i<=n;i++) if(ru[i]==0) q.push(i);
		for(int now=n;now>=1;now--)
		{
			int x=q.top();q.pop();ans[x]=now;
			for(int t=0;t<(int)to[x].size();t++)
			{
				int y=to[x][t];ru[y]--;
				if(ru[y]==0) q.push(y);
			}
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
};
int main()
{
	srand(time(0));
	bin[0]=1;for(int i=1;i<=30;i++) bin[i]=bin[i-1]<<1;
	lg[1]=0;for(int i=2;i<(1<<21);i++) lg[i]=lg[i>>1]+1;
	mine::main();
}