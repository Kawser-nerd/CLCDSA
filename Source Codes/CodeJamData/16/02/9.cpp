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
		int cnt = 0;
		for (int i = 0; i < s.length() - 1; i++)
			if (s[i] != s[i+1])
				cnt++;
		if (s[s.length()-1] == '-') cnt++;
		cout << "Case #" << zz << ": " << cnt << endl;
	}
	
	return 0;
}
