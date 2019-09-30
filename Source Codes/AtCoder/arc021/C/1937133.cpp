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
const llint mod=1e9+7;
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
int main(void){
	llint K,n,i;cin>>K>>n;
	ulint ans=0;
	vector<pair<llint,llint>>tate(n);
	for(i=0;i<n;i++){cin>>tate[i].fir>>tate[i].sec;}
	llint bmax=2e11,bmin=0;
	while(bmax-bmin>1){
		llint bgen=(bmax+bmin)/2,nok=K;
		for(auto it:tate){
			llint kai=(bgen+it.sec-it.fir)/it.sec;
			maxeq(kai,0);nok-=kai;
		}
		if(nok<=0){bmax=bgen;}
		else{bmin=bgen;}
	}
	//bmax???!
	llint nok=K;
	for(auto it:tate){
		llint kai=(bmax+it.sec-it.fir)/it.sec;
		if(kai<=0){continue;}
		ans+=(kai*it.fir)+((ulint)kai*(kai-1)/2*it.sec);
		nok-=kai;
	}
	ans+=nok*bmax;
	cout<<ans<<endl;
}