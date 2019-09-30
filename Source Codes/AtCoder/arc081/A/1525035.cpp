#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
using namespace std;
typedef long long int llint;
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
const int mod=1000000007;
const llint big=1e18+10;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-9;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
int main(void){
	int n,i;cin>>n;
	vector<llint>a(n);
	vector<llint>b;
	for(i=0;i<n;i++){cin>>a[i];}
	sort(a.begin(),a.end());
	for(i=0;i<n-1;i++){
		if(a[i]==a[i+1]){b.pub(a[i]);i++;}
	}
	if(b.size()<2){cout<<0<<endl;return 0;}
	cout<<b[b.size()-1]*b[b.size()-2]<<endl;
	return 0;
}