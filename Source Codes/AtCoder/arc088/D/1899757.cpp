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
#define RE return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=1e9+7;
const int big=1e9+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
int n;
vector<vector<int>>hen;
vector<int>ki;//is kisu
int solve(int ter,int oya,int bgen){
	//????
	//cerr<<ter<<endl;
	multiset<int>soi;
	if(ki[ter]){soi.ins(0);}
	for(auto it:hen[ter]){
		if(it==oya){continue;}
		int kae=solve(it,ter,bgen);
		if(kae==-1){return -1;}
		soi.ins(kae);
	}
	//bgen????????
	//soi?1???
	//set?????log????
	int sta=-1;
	while(soi.size()>1){
		int mae=*prev(soi.end());
		soi.era(prev(soi.end()));
		auto itr=soi.upper_bound(bgen-mae);
		if(itr==soi.begin()){//????
			if(sta!=-1){return -1;}
			else{sta=mae;}
		}
		else{soi.era(prev(itr));}
	}
	if(sta>bgen){return -1;}
	if(soi.size()==1){sta=*soi.begin();}
	if(oya!=-1){return sta+1;}
	else{return 0;}
}
int main(void){
	int i;
	cin>>n;hen.res(n);ki.res(n);
	for(i=0;i<n-1;i++){
		int a,b;cin>>a>>b;a--;b--;
		hen[a].pub(b);ki[a]=(!ki[a]);
		hen[b].pub(a);ki[b]=(!ki[b]);
	}
	int A=0,ha=-1;
	for(i=0;i<n;i++){if(ki[i]){A++;}if(hen[i].size()==1){ha=i;}}
	cout<<A/2<<" ";
	int bmax=n,bmin=0;
	while(bmax-bmin>1){
		int bgen=(bmax+bmin)/2;
		if(solve(ha,-1,bgen)!=-1){bmax=bgen;}
		else{bmin=bgen;}
	}
	cout<<bmax<<endl;
	RE;
}