#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;
typedef long long ll;
typedef double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;



int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		ll n, k; cin >> n >> k;
		ll bleh = k;
		int cnt = 0;
		while (bleh > 1){
			bleh >>= 1;
			cnt++;
		}
		ll pos = (k + 1LL - (1LL << cnt));
		ll tot = (1LL << cnt);
		ll rem = (n - tot + 1LL) % tot;
		
		ll curr = (n - tot + 1LL) / tot;
		if (pos <= rem) curr++;
		
		if (curr % 2 == 0) cout << "Case #" << zz << ": " << (curr/2) << " " << (curr/2-1) << endl;
		else cout << "Case #" << zz << ": " << (curr/2) << " " << (curr/2) << endl;
	}
	
	return 0;
}
