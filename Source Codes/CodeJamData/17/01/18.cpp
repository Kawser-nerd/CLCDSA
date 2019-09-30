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

bool flip[1<<10];

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		
		memset(flip,false,sizeof(flip));
		int k; string s;
		cin >> s >> k;
		bool curr = false;
		bool okay = true;
		int cnt = 0;
		//cout << "s = " << s << endl;
		for (int i = 0; i < s.length(); i++){
			curr = (curr ^ flip[i]);
			bool unhappy = ((s[i] == '-') ^ curr);
			//cout << "i = " << i << ", unhappy = " << unhappy << ", curr = " << curr << endl;
			if (unhappy){
				if (i+k>s.length()){
					okay = false;
					break;
				}
				flip[i+k] = true;
				curr = (curr ^ true);
				cnt++;
			}
		}
		if (okay){
			cout << "Case #" << zz << ": " << cnt << endl;
		}
		else cout << "Case #" << zz << ": IMPOSSIBLE" << endl;
	}
	
	return 0;
}
