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
using namespace std::chrono;
typedef long long int llint;
typedef double lldo;
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
cout<<fixed<<setprecision(20);
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=1000000007;
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
	cin.tie(0);
	ios::sync_with_stdio(false);
	int D,G,ans=mod,i,j;cin>>D>>G;G/=100;
	vector<int>p(D+1),c(D+1);
	for(i=1;i<=D;i++){cin>>p[i]>>c[i];c[i]/=100;}
	for(int bi=0;bi<1024;bi++){
		int gen=0,np=0;
		for(i=1;i<=D;i++){
			if((bi&(1<<(i-1)))){gen+=p[i];np+=p[i]*i+c[i];}
		}
		for(i=D;i>=1;i--){
			if(np>=G){break;}
			if((bi&(1<<(i-1)))){continue;}
			int mon=(G-np+i-1)/i;
			mineq(mon,p[i]);
			gen+=mon;np+=mon*i;
		}
		if(np>=G){mineq(ans,gen);}
	}
	cout<<ans<<endl;
	return 0;
}