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
#define RE return 0
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
llint L;
class trie{
public:
	trie *zero,*one;
	int fuka;
	trie(int in){zero=nullptr;one=nullptr;fuka=in;}
	void make_zero(void){if(zero==nullptr){zero=new trie(fuka+1);}}
	void make_one(void){if(one==nullptr){one=new trie(fuka+1);}}
	llint solve(void){
		llint ans=0;
		if(fuka==L){return 0;}
		if(zero==nullptr){ans^=(L-fuka)-((L-fuka)&(L-fuka-1));}//??bit
		else{ans^=zero->solve();}
		if(one==nullptr){ans^=(L-fuka)-((L-fuka)&(L-fuka-1));}//??bit
		else{ans^=one->solve();}
		return ans;
	}
};
int main(void){
	int n,i;cin>>n;
	cin>>L;
	trie ki(0);
	for(i=0;i<n;i++){
		string str;cin>>str;
		trie *it=(&ki);
		for(int j=0;j<str.size();j++){
			if(str[j]=='0'){it->make_zero();it=it->zero;}
			else{it->make_one();it=it->one;}
		}
	}
	llint ret=ki.solve();
	if(ret==0){cout<<"Bob"<<endl;}
	else{cout<<"Alice"<<endl;}
	RE;
}