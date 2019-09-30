#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	ll n;
	ll ans=0;
	cin >> n;
	VI a(n),b(n),c(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	for(ll i=0;i<n;i++){
		ans += (lower_bound(a.begin(),a.begin()+n,b[i])-a.begin())* (n-(upper_bound(c.begin(),c.begin()+n,b[i])-c.begin()));
	}
	cout << ans << endl;
	return 0;
}