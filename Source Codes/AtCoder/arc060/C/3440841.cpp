#include <iostream>
    #include <string>
    #include <set>  
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <cmath>
    #include <queue>
    #include <deque>
    #include <cstring>
    #include <cstdio>
    #include <map>
    #include <numeric>
    #include <cassert>
    #include <iomanip>
    #include <sstream>
    #include <ctime>
    #include <bitset> 
    #include <unordered_set>
using namespace std;
#define for1(i,a,b) for(int i=(a);i<(int)(b);++i)
#define rep(i,maxn) for1(i,0,maxn)
#define ford(i,b,a) for(int i=(int)(b)-1;i>=a;--i)
typedef long long ll;
typedef unsigned long long int128;
typedef pair<int,int> pii;
typedef pair<int,pii > piii;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define eps 1e-10
#define pi acos(-1)
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define dprintf(...) printf(__VA_ARGS__)
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1^1)
const int maxn=1e5+10;
int N,L,Q;
int x[maxn],cnt[maxn],num[maxn];
int fa[maxn][20];
vector<int> nxt[maxn];
bool vis[maxn];
inline bool chk(int v,int stp,int to)
{
	int res=v;
	rep(i,20)
	{
		if(stp&(1<<i))res=fa[res][i];
	}
//	cout<<v<<" "<<stp<<" "<<to<<endl;
//	system("pause");
//	int sz=cnt[fa[i]];
//	if(num[i]+stp>=cnt[fa[i]])return 1;
//	return nxt[fa[i]][num[i]+stp]>=to;
	return res<=to;
}
int main()
{
	scanf("%d",&N);
	rep(i,N)
		scanf("%d",x+i);
	scanf("%d",&L);
//	rep(i,N)fa[i]=i;
	num[0]=0;
	int cur=0;
	for1(i,1,N)
	{
		while(x[i]-x[cur]>L)cur++;
		fa[i][0]=cur;
	//	cout<<cur<<endl; 
	}
	rep(i,N)
	{
		for(int lg=0;lg<19;lg++)
		{
			fa[i][lg+1]=fa[fa[i][lg]][lg];
		//	cout<<i<<" "<<lg+1<<" "<<fa[i][lg+1]<<endl;
		}
	}
//	rep(i,N)cout<<num[i]<<endl 
//	system("pause");
	scanf("%d",&Q);
	while(Q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		if(a>b)swap(a,b);
		int L=0,R=N-1;
		while(L<R)
		{
			int mid=(L+R)>>1;
	//		cout<<chk(b,mid,a)<<" "<<L<<" "<<R<<" "<<mid<<endl;
			if(chk(b,mid,a))R=mid;
			else L=mid+1;
		}
	//	system("pause");
		printf("%d\n",L);
	}
	return 0;
}