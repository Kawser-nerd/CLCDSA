#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long int ll;

int main() {
	int N;
    cin >> N;

	vector<int> X(N);
    vector<int> Xs(N);
 	for(int i=0; i<N; i++) {
		int x;
		cin >> x;
		X[i] = x;
        Xs[i] = x;
	}

	sort(Xs.begin(), Xs.end());

    ll l_median = Xs[N/2-1];
    ll r_median = Xs[N/2];

	for(ll i=0; i<N; i++) {
        if(X[i] <= l_median) {
            cout << r_median << endl;
        } else {
            cout << l_median << endl;
        }
	}
}