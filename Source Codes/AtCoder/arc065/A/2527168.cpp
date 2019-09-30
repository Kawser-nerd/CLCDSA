//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

string s;
bool ans_flag = false;

string dfs(int l) {

	dump("start_dfs");

	string ret = "NO";
	if (l == s.size() && !ans_flag) {
		ans_flag = true;
	}

	if (ans_flag) {
		ret = "YES";
		dump("YES");
	}
	else {
		if (s.substr(l,5) == "dream") {
			dump(s.substr(l,5)); 
			dump("dream");
			ret = dfs(l+5);
		}
		if (s.substr(l,7) == "dreamer") {
			dump(s.substr(l,7)); 
			dump("dreamer");
			ret = dfs(l+7);
		}
		if (s.substr(l,5) == "erase") {
			dump(s.substr(l,5)); 
			dump("erase");
			ret = dfs(l+5);
		}
		if (s.substr(l,6) == "eraser") {
			dump(s.substr(l,6)); 
			dump("eraser");
			ret = dfs(l+6);
		}
	}

	dump("return");
	return ret;
}

int main() {

	cin >> s;
	int l = 0;

	cout << dfs(l);

	return 0;
}