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
#include <numeric>
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
const int mod=(int)1e9+7;
const llint big=(llint)44e15;
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
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
int main(void){
	int n,m,i,s,t;cin>>n>>m>>s>>t;s--;t--;
	//?????
	vector<vector<pair<llint,int>>>go(n);
	for(i=0;i<m;i++){
		int u,v;llint d;cin>>u>>v>>d;u--;v--;
		go[u].pub(mp(d,v));
		go[v].pub(mp(d,u));
	}
	vector<llint>Sdis(n,big);Sdis[s]=0;
	vector<llint>Tdis(n,big);Tdis[t]=0;
	//dis S????? ???DAG??
	priority_queue<pair<llint,int>,vector<pair<llint,int>>,greater<pair<llint,int>>> que;
	//que_touist
	que.push(mp(0LL,s));
	while(que.size()>0){
		llint time=que.top().fir;
		int town=que.top().sec;
		que.pop();
		if(Sdis[town]<time){continue;}
		for(auto it:go[town]){
			llint nex=time+it.fir;
			if(Sdis[it.sec]<=nex){continue;}
			Sdis[it.sec]=nex;
			que.push(mp(nex,it.sec));
		}
	}
	que.push(mp(0LL,t));
	while(que.size()>0){
		llint time=que.top().fir;
		int town=que.top().sec;
		que.pop();
		if(Tdis[town]<time){continue;}
		for(auto it:go[town]){
			llint nex=time+it.fir;
			if(Tdis[it.sec]<=nex){continue;}
			Tdis[it.sec]=nex;
			que.push(mp(nex,it.sec));
		}
	}
	llint syo=Tdis[s];//????
	vector<pair<llint,int>> Sso(n);//s??????????
	for(i=0;i<n;i++){Sso[i]=mp(Sdis[i],i);}SO(Sso);
	vector<llint> Sdp(n);Sdp[s]=1;//S??????
	vector<pair<llint,int>> Tso(n);//t??????????
	for(i=0;i<n;i++){Tso[i]=mp(Tdis[i],i);}SO(Tso);
	vector<llint> Tdp(n);Tdp[t]=1;//T??????
	for(i=0;i<n;i++){
		int ter=Sso[i].sec;
		for(auto it:go[ter]){
			if(Sdis[ter]+Tdis[it.sec]+it.fir>syo){continue;}//not ??
			Sdp[it.sec]+=Sdp[ter];Sdp[it.sec]%=mod;
		}
		//cerr<<"de Sdp["<<ter<<"]="<<Sdp[ter]<<endl;
	}
	llint ans=0;
	for(i=0;i<n;i++){
		int ter=Tso[i].sec;
		if(Tdis[ter]*2==syo){
			ans-=((Tdp[ter]*Sdp[ter])%mod) * ((Tdp[ter]*Sdp[ter])%mod);ans%=mod;
		}
		for(auto it:go[ter]){
			if(Tdis[ter]+Sdis[it.sec]+it.fir>syo){continue;}//not ??
			Tdp[it.sec]+=Tdp[ter];Tdp[it.sec]%=mod;
			if(Tdis[ter]*2<syo&&syo<Tdis[it.sec]*2){
				ans-=(Tdp[ter]*Sdp[it.sec]%mod) * (Tdp[ter]*Sdp[it.sec]%mod);ans%=mod;
			}
		}
	}ans%=mod;
	ans+=Sdp[t]*Tdp[s];ans+=mod;ans%=mod;
	cout<<ans<<endl;
	RE;
}