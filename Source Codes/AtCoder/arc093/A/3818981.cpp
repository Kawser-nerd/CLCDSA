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
int a[mn];
int b[mn];
int s;
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
  cin >> n;
  for(int i=1; i<= n; ++i) cin >> a[i];
  a[0] = a[n+1] =  0;
  s = 0;
  for(int i=0; i<= n; ++i) b[i] = abs(a[i+1]- a[i]), s += b[i];
  for(int i=1; i<= n; ++i){
    cout << s-b[i-1]-b[i] + abs(a[i+1]-a[i-1]) << "\n";
  }
	return 0;
}