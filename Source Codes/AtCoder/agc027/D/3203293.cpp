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
	llint n,i,j;cin>>n;
	vector<llint>usa;
	usa.reserve(n+n+10);
	for(i=2;;i++){
		bool ok=1;
		for(j=2;j*j<=i;j++){
			if(i%j==0){ok=0;break;}
		}
		if(ok){usa.pub(i);if(usa.size()>=n+n+10){break;}}
	}
	int m=n;
	if(n%2==1){m++;}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((i+j)%2==0){//?
				llint ans=1;
				int x=(i+j)/2;
				//x?x+1
				ans*=usa[x];
				ans*=usa[x+1];
				int y=(i+m-j)/2 +2;
				ans*=usa[n+5+y];
				ans*=usa[n+6+y];
				cout<<ans+1;
			}else{
				llint ans=1;
				int x=(i+j)/2;
				//x?x+1
				ans*=usa[x+1];
				int y=(i+m-j)/2 +2;
				ans*=usa[n+6+y];
				cout<<ans;
			}
			if(j+1<n){cout<<" ";}
		}
		cout<<endl;
	}
	return 0;
}