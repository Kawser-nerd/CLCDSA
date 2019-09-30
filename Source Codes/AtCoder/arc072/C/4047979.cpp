#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	ll n,d;
	cin >> n >> d;
	vector<ll>a(n),p(n),q(n+1);
	rep(i,n)cin >> a[i];
	p[0] = d;
	for(int i=1;i<n;i++){
		if(abs(p[i-1])>=abs(p[i-1]-a[i-1])){
			p[i] = abs(p[i-1]-a[i-1]); 
		}else{
			p[i] = p[i-1];
		}
	}
	ll c = 0;
	for(int i=n-1;i>=0;i--){
		if(a[i]<=2*c+1){
			c += a[i];
		}
		q[i] = c;
	}
	// rep(i,n){
	// 	cerr << p[i] << " " << q[i+1] << endl;
	// }
	vector<bool>flag(n);
	rep(i,n){
		if(p[i]<=q[i+1]){
			flag[i] = true;
		}
	}
	int qq;
	cin >> qq;
	rep(tt,qq){
		int x;
		cin >> x;
		x--;
		if(flag[x]){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	return 0;
}