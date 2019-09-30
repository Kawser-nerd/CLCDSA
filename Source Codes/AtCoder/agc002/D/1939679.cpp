#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<unordered_map>
#include<array>
#include<map>
#include<bitset>
#include<iomanip>
#include<list>
using namespace std;
typedef unsigned long long int ulint;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
#define RE return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=1e9+7;
const llint big=1e15+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
llint gcd(llint a,llint b){if(a%b==0){return b;}else{return gcd(b,a%b);}}
llint lcm(llint a,llint b){return a/gcd(a,b) *b;}
template<class T,class U> auto LB(T& ve,U in){return lower_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto UB(T& ve,U in){return upper_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto LBI(T& ve,U in){return LB(ve,in)-ve.begin();}
template<class T,class U> auto UBI(T& ve,U in){return UB(ve,in)-ve.begin();}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
int main(void){
	//????????????...
	int n,m,i;cin>>n>>m;
	vector<pair<int,int>>hen(m);
	for(i=0;i<m;i++){int a,b;cin>>a>>b;a--;b--;hen[i]=mp(a,b);}
	int q;cin>>q;
	vector<tuple<int,int,int,int,int>>que(q);
	for(i=0;i<q;i++){
		int a,b,c;cin>>a>>b>>c;a--;b--;
		que[i]=mt(0,a,b,c,i);
	}
	//??????????,a,b,c;
	for(int h=16;h>=0;h--){
		//sco+(1<<h)
		vector<int>siz(n,1);
		vector<int>oya(n);
		for(i=0;i<n;i++){oya[i]=i;}
		int mde=0;
		for(i=0;i<m;i++){
			int a=hen[i].fir,b=hen[i].sec;
			while(a!=oya[a]){a=oya[a];}
			while(b!=oya[b]){b=oya[b];}
			int g=hen[i].fir,iti;
			if(a==b){goto AAA;}
			if(siz[a]<siz[b]){swap(a,b);}
			siz[a]+=siz[b];
			oya[b]=a;
			while(g!=a){iti=oya[g];oya[g]=a;g=iti;}
			g=hen[i].sec;
			while(g!=a){iti=oya[g];oya[g]=a;g=iti;}
			
			AAA:
			while(mde<q&&i+1>=get<0>(que[mde])+(1<<h)){
				int go,x,y,z,ba;tie(go,x,y,z,ba)=que[mde];
				while(x!=oya[x]){x=oya[x];}
				while(y!=oya[y]){y=oya[y];}
				if(x==y&&siz[x]<z){get<0>(que[mde])+=(1<<h);}
				if(x!=y&&siz[x]+siz[y]<z){get<0>(que[mde])+=(1<<h);}
				mde++;
			}
			
		}
		sort(que.begin(),que.end());
	}
	vector<int>ans(q);
	for(i=0;i<q;i++){ans[get<4>(que[i])]=get<0>(que[i]);}
	for(i=0;i<q;i++){cout<<ans[i]+1<<endl;}RE;
}