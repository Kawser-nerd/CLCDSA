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
const llint big=(llint)44e15;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
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
llint fute(llint s,int a){
	//xa+y(a+1)=s,x>0,y>0 ???pair(x,y)???????
	//(x+y)*a + y = s
	//??
	s-=a;s-=a+1;if(s<0){return 0;}
	llint ans=0;
	llint y=s%a,syo=(s-y)/a;
	if(y>syo){return 0;}
	return 1+((syo-y)/(a+1));
}
llint kuri(int a){
	llint ans=1,bgen=10;
	for(int h=0;h<30;h++){
		if((a&(1<<h))!=0){ans*=bgen;ans%=mod;}
		bgen*=bgen;bgen%=mod;
	}
	return ans;
}
int main(void){
	llint ans=0;
	int s,i,j,k;cin>>s;
	//7?????? ??? O(1000?)
	llint keta=1,jketa=1,aga=10,jaga=10,gen=0;
	j=0;i=0;
	while(i<1e7-1){
		while(gen<s){
			j++;
			if(j==jaga){jketa++;jaga*=10;}
			gen+=jketa;
		}
		if(gen==s){ans++;}
		i++;
		if(i==aga){keta++;aga*=10;}
		gen-=keta;
	}
	//cout<<ans<<endl;
	//i?????
	for(i=1;i*i<=s;i++){
		if(s%i!=0){continue;}
		if(i>=8){ans+=9*kuri(i-1)+1- s/i;ans%=mod;}
		int ii=s/i;if(ii==i){continue;}
		if(ii>=8){ans+=9*kuri(ii-1)+1- s/ii;ans%=mod;}
	}
	//i?i+1???
	for(i=8;i<s;i++){ans+=fute(s,i);ans%=mod;}
	cout<<ans<<endl;
	RE;
}