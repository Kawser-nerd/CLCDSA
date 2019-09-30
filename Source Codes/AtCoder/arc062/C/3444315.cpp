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
const int maxn=405;
int C[maxn][4];
struct tile
{
	int a,b,c,d;
	tile(){}
	tile(int _a,int _b,int _c,int _d):a(_a),b(_b),c(_c),d(_d){} 
	bool operator < (const tile &t)const
	{
		return (a!=t.a?a<t.a:b!=t.b?b<t.b:c!=t.c?c<t.c:d<t.d);
	}
	bool operator == (const tile &t)
	{
		return a==t.a&&b==t.b&&c==t.c&&d==t.d;
	}
};
map<tile,int> m;
void ins(int a,int b,int c,int d)
{
	m[tile(a,b,c,d)]++;
	m[tile(b,c,d,a)]++;
	m[tile(c,d,a,b)]++;
	m[tile(d,a,b,c)]++;
}
vector<tile> vx;
int same(tile a,tile b)
{
	int ans=0;
	int aa=b.a,bb=b.b,cc=b.c,dd=b.d;
	if(a==tile(aa,bb,cc,dd))ans++;
	if(a==tile(bb,cc,dd,aa))ans++;
	if(a==tile(cc,dd,aa,bb))ans++;
	if(a==tile(dd,aa,bb,cc))ans++;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	rep(i,n)rep(j,4)cin>>C[i][j];
	ll ans=0;
	ford(i,n,0)
	{
		rep(j,vx.size())
		{
			tile cur=vx[j];
			int a=cur.a,b=cur.b,c=cur.c,d=cur.d;
		//	cout<<C[i][0]<<" "<<C[i][1]<<" "<<C[i][2]<<" "<<C[i][3]<<endl;
		//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		//	system("pause"); 
			tile x=tile(C[i][0],C[i][1],b,a);
			tile y=tile(C[i][1],C[i][2],c,b);
			tile z=tile(C[i][2],C[i][3],d,c);
			tile w=tile(C[i][3],C[i][0],a,d);
		//	cout<<"x: "<<x.a<<" "<<x.b<<" "<<x.c<<" "<<x.d<<" "<<m[x]<<endl;
		//	cout<<"y: "<<y.a<<" "<<y.b<<" "<<y.c<<" "<<y.d<<" "<<m[y]<<endl;
		//	cout<<"z: "<<z.a<<" "<<z.b<<" "<<z.c<<" "<<z.d<<" "<<m[z]<<endl;
		//	cout<<"w: "<<w.a<<" "<<w.b<<" "<<w.c<<" "<<w.d<<" "<<m[w]<<endl; 
			ll res=1;
			res*=1ll*m[x]-same(cur,x);
		//	cout<<m[x]<<" "<<same(cur,x)<<endl;
			res*=1ll*m[y]-same(x,y)-same(cur,y);
		//	cout<<m[y]<<" "<<same(x,y)<<" "<<same(cur,y)<<endl;
			res*=1ll*m[z]-same(x,z)-same(y,z)-same(cur,z);
		//	cout<<m[z]<<" "<<same(x,z)<<" "<<same(y,z)<<" "<<same(cur,z)<<endl;
			res*=1ll*m[w]-same(x,w)-same(y,w)-same(z,w)-same(cur,w);
		//	cout<<m[w]<<" "<<same(x,w)<<" "<<same(y,w)<<" "<<same(z,w)<<" "<<same(cur,w)<<endl;
			ans+=res;
		//	cout<<res<<" "<<ans<<endl;
		//	system("pause");
		}
		int a=C[i][0],b=C[i][3],c=C[i][2],d=C[i][1];
		ins(a,b,c,d);
		vx.pb(tile(a,b,c,d));
		vx.pb(tile(b,c,d,a));
		vx.pb(tile(c,d,a,b));
		vx.pb(tile(d,a,b,c));
	}
	cout<<ans<<endl;
	return 0;
}