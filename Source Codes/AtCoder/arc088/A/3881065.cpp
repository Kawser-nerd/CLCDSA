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
int x, y;
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
  cin >> x >> y;
  int ans = 0;
  while(x<= y){
    ++ans; 
    x<<=1;
  }
  cout << ans;
	return 0;
}