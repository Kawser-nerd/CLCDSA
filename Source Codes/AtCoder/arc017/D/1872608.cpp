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

llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
llint gcdd(llint a,llint b){
	if(b==0){return a;}
	return gcd(abs(a),abs(b));
}
llint seggc[262144]={0};//???gcc??
llint segit[262144]={0};//BIT ????????????????????
int main(void){
	int n,m,i;cin>>n;
	//?????
	//?????????
	for(i=0;i<n;i++){
		int a;cin>>a;
		segit[131072+i]=a;
	}cin>>m;
	for(i=131072;i<131072+n+1;i++){seggc[i]=segit[i]-segit[i-1];}
	for(i=131071;i>0;i--){seggc[i]=gcdd(seggc[i+i],seggc[i+i+1]);}
	while(m--){
		int t,l,r;cin>>t>>l>>r;l--;
		int bi;
		if(t==0){
			//l~r?gcd segit[l];
			int ans=0;
			bi=131072+l;
			while(bi>0){ans+=segit[bi];bi/=2;}
			//l?????????
			bi=131072+l+1;//?????
			int kak=0;
			while(bi>0){
				if(((bi+1)<<kak)>=131072+r){break;}
				ans=gcdd(ans,seggc[bi]);
				bi=(bi+1)/2;
				kak++;
			}
			kak=0;
			bi=131072+r-1;
			while(bi>0){
				if((bi<<kak)<=131072+l){break;}
				ans=gcdd(ans,seggc[bi]);
				bi=(bi-1)/2;
				kak++;
			}
			cout<<ans<<endl;
		}else{
			bi=131072+l;
			seggc[bi]+=t;bi/=2;
			while(bi>0){seggc[bi]=gcdd(seggc[bi+bi],seggc[bi+bi+1]);bi/=2;}
			bi=131072+r;
			seggc[bi]-=t;bi/=2;
			while(bi>0){seggc[bi]=gcdd(seggc[bi+bi],seggc[bi+bi+1]);bi/=2;}
			//l~r?????
			bi=131072+l-1;
			while(true){
				if(bi%2==0){segit[bi]-=t;}
				if((bi&(bi-1))==0){break;}//2???
				bi=(bi-1)/2;
			}
			bi=131072+r-1;
			while(bi>0){
				if(bi%2==0){segit[bi]+=t;}
				if((bi&(bi-1))==0){break;}//2???
				bi=(bi-1)/2;
			}
			//???
		}
	}
	return 0;
}