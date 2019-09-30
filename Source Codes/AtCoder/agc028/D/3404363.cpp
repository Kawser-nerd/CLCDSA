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
	//900???AC
	llint n,K,i,j,h,ans=0;cin>>n>>K;n*=2;
	static int go[600];
	for(i=0;i<600;i++){go[i]=-1;}
	for(i=0;i<K;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		go[a]=b;
		go[b]=a;
	}
	static llint dp[600][600]={0};
	static llint ziyu[601];
	for(i=0;i<n;i++){
		ziyu[i+1]=ziyu[i];
		if(go[i]==-1){ziyu[i+1]++;}
	}
	static llint tori[601]={0};
	tori[0]=1;
	for(i=2;i<=n;i+=2){tori[i]=(tori[i-2]*(i-1))%mod;}
	for(i=0;i<n;i++){//??
		for(j=0;j+i<n;j++){
			int x=j,y=j+i;
			bool dame=false;
			for(h=x;h<=y;h++){
				if(go[h]!=-1&&(go[h]<x||y<go[h])){dame=true;break;}
			}
			if(dame){continue;}
			
			int zi=ziyu[y+1]-ziyu[x];
			if(zi%2==1){continue;}
			dp[x][y]=tori[zi];
			for(h=x;h<y;h++){
				dp[x][y]-=dp[x][h]*tori[ziyu[y+1]-ziyu[h+1]];
				dp[x][y]%=mod;
			}
			ans+=dp[x][y]*tori[ziyu[n]-zi];
			ans%=mod;
			//cerr<<"x,y,dp"<<x<<","<<y<<","<<dp[x][y]<<endl;
		}
	}
	ans+=mod;ans%=mod;
	cout<<ans<<endl;
	return 0;
}