#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cstring>
#include <iomanip>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
#define inf 280201280201280201
#define mn 100005
#define FLN "test"
#define int long long
typedef pair<int, int> ii;
//constance

//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int n;
string s;
//functions here
void input(){
}
void solve(){
}

//#define LOCAL 1

signed main(signed argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	   freopen(FLN".inp", "r", stdin);
	   freopen(FLN".out", "w", stdout);
#endif
  cin >> s; n = s.length();
  int cur = 0;
  int ans = 0;
  for(int i=0; i< n; ++i){
    if(s[i] == 'W'){
      ++cur;
      ans += (i+1-cur);
    }
  }
  cout << ans;
	return 0;
}