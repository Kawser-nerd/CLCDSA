//{{{By oToToT
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <random>
#include <utility>
#include <stack>
#include <sstream>
#include <functional>
#include <deque>
#include <cassert>
using namespace std;
/* include everything for Kotori~ <3 */

using lld = int64_t;
using llu = uint64_t;
using llf = long double;
using PII = pair<int,int>;
using PIL = pair<int,lld>;
using PLI = pair<lld,int>;
using PLL = pair<lld,lld>;
template<typename T>
using maxHeap = priority_queue<T,vector<T>,less<T>>;
template<typename T>
using minHeap = priority_queue<T,vector<T>,greater<T>>;
/* define some types for Ruby! */

#define FF first
#define SS second
#define SZ(x) (int)((x).size())
#define ALL(x) begin(x), end(x)
#define PB push_back
#define WC(x) while(x--)
/* make code shorter for Di~a~ */

template<typename Iter>
ostream& _out(ostream &s, Iter b, Iter e) {
	s<<"[";
	for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
	s<<"]";
	return s;
}
template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.FF<<","<<p.SS<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
/* make output easier for Ainyan~n~ */

bool debug = 0;
#define DUMP(x) if(debug) cerr<<__PRETTY_FUNCTION__<<":"<<__LINE__<<" - "<<(#x)<<"="<<(x)<<'\n'
template<typename T>
void DEBUG(const T& x){if(debug) cerr<<x;}
template<typename T, typename... Args>
void DEBUG(const T& head,const Args& ...tail){
	if(debug){cerr<<head; DEBUG(tail...);}
}
/* Let's debug with Nico~Nico~Ni */
//}}}
const int N = 200000 + 5;
const int C = 1<<30;

map<int,int,greater<int>> st;

int main(int argc, char* argv[]){
	if(argc>1 and string(argv[1])=="-D") debug=1;
	if(!debug){ios_base::sync_with_stdio(0);cin.tie(0);}
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		st[x]++;
	}
	int ans=0;
	for(auto it=st.begin();it!=st.end();++it){
		for(int64_t cur=1;cur<=C;cur<<=1){
			if(cur<it->FF) continue;
			if(st.find(cur-it->FF)==st.end())
				continue;
			if(it->FF*2==cur) {
				ans+=it->SS/2;
				it->SS &= 1;
				continue;
			}
			int dlt = min(it->SS, st[cur-it->FF]);
			ans+=dlt;it->SS-=dlt;st[cur-it->FF]-=dlt;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
3 29 
*/