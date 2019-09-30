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
	int i,x,k;cin>>x>>k;
	vector<int>kai(k+2);
	vector<int>sna(k+2);//??,?
	vector<int>msna(k+2);
	int uegen=big;//???
	kai[0]=0;
	for(i=0;i<k;i++){cin>>kai[i+1];}
	kai[k+1]=big;
	int now=0,mtnow=0;
	int j=0;
	vector<pair<int,int>> uebt(k+2);//??,a
	
	for(i=0;i<kai.size()-1;i++){
		sna[i]=now;msna[i]=mtnow;
		uebt[i]=mp(kai[i],x-mtnow);
		if(i%2==0){now-=kai[i+1]-kai[i];mtnow-=kai[i+1]-kai[i];if(now<=0){now=0;}}
		else{now+=kai[i+1]-kai[i];mtnow+=kai[i+1]-kai[i];if(now>=x){mineq(uegen,kai[i+1]-now+x);now=x;}}
		
	}
	uebt[k+1]=(mp(0,uegen));//a=0????????????
	sort(uebt.begin(),uebt.end());
	vector<pair<int,int>> uebtlis;//??,a
	uebtlis.pub(uebt[0]);
	for(i=1;i<k+2;i++){
		if(uebtlis.back().sec>uebt[i].sec){uebtlis.pub(uebt[i]);}
	}
	//uegen ??????
	//??????->a??????????,t????????????a=??
	//???????=mtnow?
	//???????->max(a=0???,a=ai?x??????????)???
	int q;cin>>q;
	for(i=0;i<q;i++){
		int t,a;cin>>t>>a;
		auto it=upper_bound(uebtlis.begin(),uebtlis.end(),mp(t,big));it--;
		mineq(a,it->sec);
		int mebas=upper_bound(kai.begin(),kai.end(),t)-kai.begin()-1;
		int sokara=t-kai[mebas];
		int aoans=max(sna[mebas],msna[mebas]+a);
		if(mebas%2==0){aoans-=sokara;}
		else{aoans+=sokara;}
		mineq(aoans,x);
		maxeq(aoans,0);
		cout<<aoans<<endl;
	}
	return 0;
}