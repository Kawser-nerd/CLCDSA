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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	ll n,m;
	cin >> n >> m;
	ll t = 1900;
	ll k=1;
	for(ll i=0;i<m;i++){
		k *= 2;
	}
	cout << k*(100*(n-m)+t*m)  << endl;
	return 0;
}