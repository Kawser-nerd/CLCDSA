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

bool seen[10];

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		ll n; cin >> n;
		if (n == 0){
			cout << "Case #" << zz << ": INSOMNIA" << endl;
			continue;
		}
		memset(seen,false,sizeof(seen));
		ll cnt = 0;
		string s;
		bool done = false;
		while(!done){
			cnt++;
			s = std::to_string(cnt*n);
			//cout << "cnt = " << endl;
			for (int i = 0; i < s.length(); i++){
				seen[s[i]-'0'] = true;
				//cout << (int) (s[i]-'0') << endl;
			}
			done = true;
			for (int i = 0; i < 10; i++)
				if(!seen[i]){
					done = false;
					break;
				}
		}
		cout << "Case #" << zz << ": " << s << endl;
	}
	
	return 0;
}
