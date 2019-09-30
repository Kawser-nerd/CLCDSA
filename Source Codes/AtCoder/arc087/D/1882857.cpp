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
vector<vector<int>> hen;
vector<int>zyu;//??????
int n,endflag=0;
int make_tree(int ter,int oya){
	vector<int> are;
	int kos=1,flag=1;
	for(auto it:hen[ter]){
		if(it==oya){continue;}
		int a=make_tree(it,ter);
		are.pub(a);
		kos+=a;
		if(a*2>n){flag=0;}
	}
	if(kos*2<n){flag=0;}
	if(kos*2==n){endflag=1;}
	if(flag==1){
		are.pub(n-kos);
		zyu=are;
	}
	return kos;
}
int main(void){
	int i,j;cin>>n;
	hen.res(n);
	vector<llint>fra(n+1);fra[0]=1;
	vector<llint>gya(n+1);
	for(i=0;i<n;i++){fra[i+1]=(fra[i]*(i+1))%mod;}
	llint gen=fra[n];gya[n]=1;
	for(int bi=0;bi<30;bi++){
		if(((mod-2)&(1<<bi))!=0){gya[n]*=gen;gya[n]%=mod;}
		gen=gen*gen;
		gen%=mod;
	}
	for(i=n-1;i>=0;i--){gya[i]=(gya[i+1]*(i+1))%mod;}
	for(i=0;i<n-1;i++){
		int a,b;cin>>a>>b;a--;b--;
		hen[a].pub(b);
		hen[b].pub(a);
	}
	make_tree(0,-1);
	if(endflag==1){cout<<(fra[n/2]*fra[n/2]%mod)<<endl;RE;}
	vector<llint>dp(n+1);
	dp[0]=1;
	for(auto it:zyu){
		vector<llint>ddp(n+1);
		for(i=0;i<=n;i++){
			for(j=0;j<=it;j++){
				if(i+j<0||i+j>n){continue;}
				ddp[i+j]+=((((dp[i]*fra[it])%mod)*((fra[it]*gya[j])%mod))%mod*(gya[it-j]*gya[it-j]%mod))%mod;
			}
		}
		for(i=0;i<=n;i++){dp[i]=ddp[i]%mod;}
	}
	llint ans=0;
	for(i=0;i<=n;i++){
		if(i%2==0){ans+=dp[i]*fra[n-i];}
		else{ans-=dp[i]*fra[n-i];}
		ans%=mod;
	}
	if(ans<0){ans+=mod;}
	cout<<ans<<endl;
	RE;
}