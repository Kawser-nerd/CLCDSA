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
	llint K,m,i,ans=0;cin>>K>>m;
	//?????
	map<llint,llint> mae;
	map<llint,llint> ato;
	llint bo=m/100000;
	llint aa=bo,zbo=0;
	while(aa>0){zbo+=aa%10;aa/=10;}
	llint nko=(K*100000+100000*bo-zbo)%K;
	for(i=0;i<100000;i++){
		int gen=i,zyu=0;
		while(gen>0){zyu+=gen%10;gen/=10;}
		if(i<m/100000){mae[(K*100000+100000*i-zyu)%K]++;}
		ato[(K*100000+zyu-i)%K]++;
		if((K*100000+zyu-i)%K==nko&&i<=m%100000){ans++;}
	}
	//ato==mae
	for(auto it:mae){ans+=it.sec*ato[it.fir];}
	ans--;
	cout<<ans<<endl;
	RE;
}