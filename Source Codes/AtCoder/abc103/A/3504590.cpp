#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	vector<ll> A(3);
    cin >> A[0] >> A[1] >> A[2];

	ll ans = numeric_limits<ll>::max();
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				if(i==j || j==k || k==i) continue;
				ans = min(ans, abs(A[i]-A[j])+abs(A[j]-A[k]));
			}
		}
	}

	cout << ans << endl;
}