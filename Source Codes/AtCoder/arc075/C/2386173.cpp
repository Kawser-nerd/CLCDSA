// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef ll Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
class BIT{
	public:
	//[1,i]
	int n;
	vi bit;
//	int bit[MAZ_N+1];
	BIT(int size){
		n=size;
		bit=vi(n+1);
	}
	int query(int i){//sum
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i&-i;
		}
		return s;
	}
	void add(int i,int x){
		while(i<=n){
			bit[i]+=x;
			i+=i&-i;
		}
	}
};
int main(){
	ll n,m;
	cin>>n>>m;
	vi in(n+1);
	ll sum=0;
	rep(i,n){
		int a;cin>>a;
		sum+=a;
		in[i+1]=sum-(i+1)*m;
	}
	vi t=in;
	sort(all(t));
	t.erase(unique(all(t)),t.end());
	rep(i,n+1)in[i]=lower_bound(all(t),in[i])-t.begin();
	
	ll out=0;
	BIT bit(n+2);
	rep(i,n+1){
		int t=in[i];
		out+=bit.query(t+1);
		bit.add(t+1,1);
	}
	cout<<out<<endl;
}