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
		string s; cin >> s;
		char ma = 0;
		int curr;
		for (curr = 0; curr < s.length(); curr++){
			if (ma <= s[curr]) ma = s[curr];
			else break;
		}
		
		if (curr == s.length()){
			cout << "Case #" << zz << ": " << s << endl;
			continue;
		}
		
		cout << "Case #" << zz << ": ";
		bool okay = true;
		for (curr = 0; curr < s.length(); curr++){
			if (!okay) cout << '9';
			else if (s[curr] == ma){
				if (ma != '1')
					cout << ((char)(s[curr]-1));
				okay = false;
			}
			else cout << ((char) s[curr]);
		}
		cout << endl;
	}
	
	return 0;
}
