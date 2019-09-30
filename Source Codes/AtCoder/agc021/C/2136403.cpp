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
#include<list>
#include <numeric>
using namespace std;
typedef unsigned long long int ulint;
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
const int mod=(int)1e9+7;
const llint big=(llint)(2.19e15)+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
llint gcd(llint a,llint b){if(a%b==0){return b;}else{return gcd(b,a%b);}}
llint lcm(llint a,llint b){return a/gcd(a,b) *b;}
template<class T,class U> auto LB(T& ve,U in){return lower_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto UB(T& ve,U in){return upper_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto LBI(T& ve,U in){return LB(ve,in)-ve.begin();}
template<class T,class U> auto UBI(T& ve,U in){return UB(ve,in)-ve.begin();}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
using pli=pair<llint,int>;
using daic=priority_queue<pli,vector<pli>,greater<pli>>;
int main(void){
	int n,m,a,b,i,j;cin>>n>>m>>a>>b;
	int ta=0,yo=0,ro=0;
	ro=2*(n/2)*(m/2);
	yo=(n%2)*(m/2);
	ta=(n/2)*(m%2);
	if((a>0&&m==0)||(b>0&&n==0)){cout<<"NO\n";RE;}
	if(a>yo+ro||b>ta+ro||a+b>yo+ro+ta){cout<<"NO\n";RE;}
	if(((n%2==0)||(m%2==0))&&a+b==yo+ro+ta&&(a-yo)%2==1){cout<<"NO\n";RE;}
	cout<<"YES\n";
	vector<string>ans(n,string(m,'.'));
	if(m%2==1){
		for(i=0;i+1<n;i+=2){
			if(b<=0){break;}b--;
			ans[i][m-1]='^';
			ans[i+1][m-1]='v';
		}
	}
	if(n%2==1){
		for(j=0;j+1<m;j+=2){
			if(a<=0){break;}a--;
			ans[n-1][j]='<';
			ans[n-1][j+1]='>';
		}
	}
	for(i=0;i+1<n;i+=2){
		for(j=0;j+1<m;j+=2){
			//cerr<<"de "<<i<<" "<<j<<endl;
			if(a>=2){a-=2;
				  ans[i][j]='<';  ans[i][j+1]='>';
				ans[i+1][j]='<';ans[i+1][j+1]='>';
			}else if(b>=2){b-=2;
				  ans[i][j]='^';  ans[i][j+1]='^';
				ans[i+1][j]='v';ans[i+1][j+1]='v';
			}else if(a>0){a--;
				ans[i][j]='<';  ans[i][j+1]='>';
			}else if(b>0){b--;
				  ans[i][j]='^';
				ans[i+1][j]='v';
			}
		}
	}
	if(b>0){//???
		ans[n-2][m-3]='^';
		ans[n-1][m-3]='v';ans[n-1][m-2]='<';ans[n-1][m-1]='>';
	}
	for(auto it:ans){cout<<it<<endl;}
	RE;
}