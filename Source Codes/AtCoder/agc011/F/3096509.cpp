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
	llint n,K,i,j,L,R,h;cin>>n>>K;
	vector<llint>wa(n+1);
	vector<int>sen(n);
	for(i=0;i<n;i++){
		llint A;int B;cin>>A>>B;A*=2;
		if(A>K&&B==1){cout<<"-1\n";return 0;}
		wa[i+1]=wa[i]+A;
		sen[i]=B;
	}
	vector<llint>atu(n+2);
	for(i=0;i<=n;i++){atu[i]=wa[i]%K;}
	atu[n+1]=K;
	SO(atu);
	vector<int>seg(262144,-1);
	vector<llint>dp(n);
	llint Kbig=big-big%K;
	for(i=0;i<n;i++){
		if(sen[i]==2){continue;}
		//???seg????
		int sta=LBI(atu,wa[i+1]%K);
		int mae=LBI(atu,wa[i]%K);
		//cerr<<"mast"<<mae<<sta<<endl;
		//sta?seg????
		int bas=131072+sta;
		int dco=-1;
		while(bas>1){
			if(seg[bas]!=-1){dco=seg[bas];}
			bas/=2;
		}
		if(dco==-1){dp[i]=0;}
		else{dp[i]=dp[dco]+(Kbig+wa[dco+1]-wa[i+1])%K;}
		//mae??sta???????????
		if(mae<sta){
			sta++;
			//??
			L=1,R=1;
			for(h=16;h>=0;h--){
				if(seg[L]!=-1){seg[L+L]=seg[L];seg[L+L+1]=seg[L];}
				if(seg[R]!=-1){seg[R+R]=seg[R];seg[R+R+1]=seg[R];}
				seg[L]=-1;seg[R]=-1;
				L*=2;R*=2;
				if(mae&(1<<h)){L++;}
				if(sta&(1<<h)){R++;}
				if(L+1<R){
					if(L%2==0){seg[L+1]=i;}
					if(R%2==1){seg[R-1]=i;}
				}
			}
		}else{
			sta++;
			//??
			L=1,R=1;
			for(h=16;h>=0;h--){
				if(seg[L]!=-1){seg[L+L]=seg[L];seg[L+L+1]=seg[L];}
				if(seg[R]!=-1){seg[R+R]=seg[R];seg[R+R+1]=seg[R];}
				seg[L]=-1;seg[R]=-1;
				L*=2;R*=2;
				if(mae&(1<<h)){L++;}
				if(sta&(1<<h)){R++;}
				if(L%2==0){seg[L+1]=i;}
				if(R%2==1){seg[R-1]=i;}
			}
		}
		//?????
	}
	//for(i=0;i<n;i++){cerr<<dp[i]<<endl;}
	for(i=1;i<131072;i++){if(seg[i]<0){continue;}seg[i+i]=seg[i];seg[i+i+1]=seg[i];}
	llint ans=big;
	for(i=0;i<=n;i++){
		if(i>0&&atu[i-1]==atu[i]){continue;}
		int ter=seg[i+131072];
		if(ter==-1){ans=0;break;}
		mineq(ans,dp[ter]+(Kbig+wa[ter+1]-atu[i])%K);
		//cerr<<"i="<<i<<"t="<<ter<<"wa="<<wa[ter+1]<<"atu="<<atu[i]<<endl;
	}
	ans+=wa[n];
	cout<<ans<<endl;
	return 0;
}