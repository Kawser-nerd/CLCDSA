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
struct SuffixArray{
	vector<int> SA;
	string s;
	void Build_SA(const string& str){
		s = str;
		SA.resize(s.size());
		iota(begin(SA), end(SA), 0);
		sort(begin(SA), end(SA), [&](const int& a, const int& b)
		{
			if(s[a] == s[b]) {return(a > b);}
			return (s[a] < s[b]);
		});
		vector< int > classes(s.size()), c(s.size()), cnt(s.size());
		for(int i = 0; i < s.size(); i++) {c[i] = s[i];}
		for(int len = 1; len < s.size(); len <<= 1) {
			for(int i = 0; i < s.size(); i++) {
				if(i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
					classes[SA[i]] = classes[SA[i - 1]];
				} else {
					classes[SA[i]] = i;
				}
			}
			iota(begin(cnt), end(cnt), 0);
			copy(begin(SA), end(SA), begin(c));
			for(int i = 0; i < s.size(); i++) {
				int s1 = c[i] - len;
				if(s1 >= 0) SA[cnt[classes[s1]]++] = s1;
			}
			classes.swap(c);
		}
	}
	int operator[](int k) const{return (SA[k]);}
	int size() const{return (s.size());}
};
SuffixArray sa;
SuffixArray sb;
int n;
string str;
vector<int>gya;
vector<int>gyb;
bool comp(int a,int b){
	if(a==b){return false;}
	if((gya[a]<gya[b])==(gyb[a]<gyb[b])){return gya[a]<gya[b];}
	bool han=false;
	if(a>b){swap(a,b);han=true;}
	return (gya[n+a-b]<gya[a])^han;
}
int main(void){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	int i;cin>>n>>str;
	sa.Build_SA(str);
	str.pub('z'+1);
	sb.Build_SA(str);
	gya.res(n);gyb.res(n);
	for(i=0;i<n;i++){gya[sa[i]]=i;gyb[sb[i]]=i;}
	vector<int>ans(n);
	for(i=0;i<n;i++){ans[i]=i;}
	sort(ans.begin(),ans.end(),comp);
	for(i=0;i<n;i++){cout<<ans[i]+1<<endl;}
	RE;
}