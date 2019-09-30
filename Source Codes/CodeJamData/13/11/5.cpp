#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long ll;

typedef long double ld;

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		ll r, t;
		cin >> r >> t;
		
		ld lim = 3e18;
		ld rr = (ld) r;
		ld temp = sqrt(lim/2.0 + (rr-1/2.0)*(rr-1/2.0)/4.0) - (rr-1/2.0)/2.0;
		
		ll mi = 0;
		ll ma = (ll) temp;
		ll curr = ma/2L;
		while (ma-mi>0){
			ll val = (curr-1) * curr * 2L + curr * (2L*r+1L);
			if (val > t){
				ma = curr-1;
				curr = (mi+ma+1)/2L;
			}
			else{
				mi = curr;
				curr = (mi+ma+1)/2L;
			}
		}
		cout << "Case #" << zz << ": " << curr << endl;
	}
	
		
	return 0;
}
