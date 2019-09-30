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
	int i,n;cin>>n;
	string ue;
	string st;
	llint ans=1,mae;
	cin>>ue;
	cin>>st;
	ue.pub('#');
	if(ue[0]==ue[1]){ans=6;mae=2;}
	else{ans=3;mae=1;}
	for(i=mae;i<n;i++){
		if(ue[i]==ue[i+1]){
			
			if(mae==2){ans*=3;ans%=mod;}
			else{ans*=2;ans%=mod;}
			i++;
			mae=2;
		}else{
			if(mae==1){ans*=2;ans%=mod;}
			mae=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}