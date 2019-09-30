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
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
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
/*
cout<<setprecision(20);
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=924844033;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	cout<<setprecision(20);
	cin.tie(0);
	ios::sync_with_stdio(false);
	llint n,i,K;cin>>n>>K;
	vector<llint>x(n);
	for(i=0;i<n;i++){cin>>x[i];}
	REV(x);
	llint ans=big;
	//????????????
	llint bmin=0,bmax=n+1;
	while(bmax-bmin>1){
		llint bgen=(bmax+bmin)/2;
		//bgen?bgen+1??????
		llint hians=K*(n+bgen);
		for(i=0;i<n;i++){
			int suu=i/bgen;
			if(suu==0){suu=5;}
			else{suu=suu*2+3;}
			hians+=x[i]*suu;
		}
		mineq(ans,hians);
		
		llint mgans=K*(n+bgen+1);
		for(i=0;i<n;i++){
			int suu=i/(1+bgen);
			if(suu==0){suu=5;}
			else{suu=suu*2+3;}
			mgans+=x[i]*suu;
		}
		mineq(ans,mgans);
		if(hians<mgans){bmax=bgen;}
		else{bmin=bgen;}
	}
	cout<<ans<<endl;
	return 0;
}