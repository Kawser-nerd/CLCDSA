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
		int n, j;
		cin >> n >> j;
		cout << "Case #" << zz << ":" << endl;
		for (int i = 0; i < j; i++){
			int curr = i;
			cout << "11";
			int cnt = 1;
			while (curr){
				if (curr%2) cout << "11";
				else cout << "00";
				cnt++;
				curr >>= 1;
			}
			while (cnt < (n/2)-1){
				cout << "00";
				cnt++;
			}
			cout << "11";
			for (int base = 2; base <= 10; base++)
				cout << " " << (base+1);
			cout << endl;
		}
	}
	
	return 0;
}
