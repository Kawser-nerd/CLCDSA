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
//typedef unsigned long long ull;
typedef double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		ll k, c, s;
		cin >> k >> c >> s;
		if (c*s < k){
			cout << "Case #" << zz << ": IMPOSSIBLE" << endl;
			continue;
		}
		cout << "Case #" << zz << ":";
		for (int i = 0; i < s && i*c < k; i++){
			ll sum = 0;
			for (int j = c*(i+1)-1; j >= c*i; j--){
				sum *= k;
				if (j < k) sum += j;
			}
			cout << " " << (sum+1);
		}
		cout << endl;
	}
	
	return 0;
}
