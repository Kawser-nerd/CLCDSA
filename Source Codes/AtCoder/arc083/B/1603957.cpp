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
#define dme cout<<"-1"<<endl;return 0
const int mod=1000000007;
const int big=1e9+10;
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
	llint di[300][300]={0};
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>di[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			for(k=0;k<n;k++){
				if(di[i][j]>di[i][k]+di[k][j]){dme;}
				if(i==k||j==k){continue;}
				if(di[i][j]==di[i][k]+di[k][j]){ans-=di[i][j];break; }
			}
			ans+=di[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}