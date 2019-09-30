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
bool a[mn];
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
  cin >> s;
  n = s.length();
  a[0] = 0;
  int l=1, r = n, ans = 1;
  while(l<= r){
    int mid =  (l+r)>>1;
    for(int i=1; i<= n; ++i) a[i] = s[i-1] -'0';
    for(int i=n; i>=1; --i) a[i] = a[i]^a[i-1];
    for(int i=1; i<= n-mid+1; ++i){
      a[i] ^= a[i-1];
      if(a[i]) a[i]^=1;
    }
    bool check = true;
    for(int i=n-mid+2; i<= n; ++i){
      a[i] ^= a[i-1];
      check &= (a[i]==0 || i-1 >= mid);
    }
    
    if(check){
      ans = mid;
      l = mid+1;
    }
    else r = mid-1;
  }
  cout << ans;
	return 0;
}