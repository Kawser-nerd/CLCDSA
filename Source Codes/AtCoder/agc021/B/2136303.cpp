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
const llint big=(llint)(2.19e15)+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
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
using pli=pair<llint,int>;
using daic=priority_queue<pli,vector<pli>,greater<pli>>;
int main(void){
	int n,i,j;cin>>n;
	vector<lldo>x(n);
	vector<lldo>y(n);
	cout<< setprecision(20);
	for(i=0;i<n;i++){cin>>x[i]>>y[i];}
	for(i=0;i<n;i++){
		vector<lldo>kak;
		for(j=0;j<n;j++){
			if(i==j){continue;}
			kak.pub(atan2(y[i]-y[j],x[i]-x[j]));
		}
		SO(kak);
		//cerr<<"de"<<kak.size()<<endl;
		lldo sa=0;
		for(j=0;j<n-2;j++){maxeq(sa,kak[j+1]-kak[j]);}
		maxeq(sa,2*pai+kak[0]-kak[n-2]);
		if(sa<pai){cout<<"0\n";}
		else{cout<<(sa-pai)/(2*pai)<<endl;}
	}
	RE;
}