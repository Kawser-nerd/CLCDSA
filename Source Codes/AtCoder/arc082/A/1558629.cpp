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
#define dme cout<<"NO"<<endl;return 0
const int mod=1000000007;
const int big=1e9+10;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
const int hi=100000;
int main(void){
	int n,i,ans=0;cin>>n;
	vector<int>a(hi+2);
	for(i=0;i<n;i++){
		int q;cin>>q;q++;
		a[q-1]++;a[q]++;a[q+1]++;
	}
	for(i=0;i<a.size();i++){
		maxeq(ans,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}