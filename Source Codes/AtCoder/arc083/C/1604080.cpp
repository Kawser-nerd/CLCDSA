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
using namespace std;
typedef long long int llint;
typedef long double lld;
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
#define dme cout<<"IMPOSSIBLE"<<endl;return 0
const int mod=1000000007;
const int big=7000000;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
//19:04~
int main(void){
	llint ans=0;
	int n,i,j,k;cin>>n;
	vector<vector<int>>ko(n);
	vector<int>can(n);//????????
	vector<int>x(n);
	for(i=1;i<n;i++){
		int q;cin>>q;q--;
		ko[q].pub(i);
	}
	for(i=0;i<n;i++){cin>>x[i];}
	for(i=n-1;i>=0;i--){//?????
		vector<int>dp(5001);
		for(k=0;k<ko[i].size();k++){
			int kos=ko[i][k];
			int a=x[kos];
			int b=can[kos];
			vector<int>ddp(5001,big);
			for(j=0;j+a<=5000;j++){ddp[j+a]=dp[j]+b;}
			for(j=0;j+b<=5000;j++){mineq(ddp[j+b],dp[j]+a);}
			swap(dp,ddp);
		}
		can[i]=big;
		for(j=0;j<=x[i];j++){mineq(can[i],dp[j]);}
		if(can[i]==big){dme;}
	}
	cout<<"POSSIBLE"<<endl;
	return 0;
}