#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ll A, B, C;
    cin >> A >> B >> C;

	vector<ll> x = {A, B, C};
	sort(x.begin(), x.end());

	ll a = (x[1] - x[0]) / 2;
	ll b = (x[0] + 2*a == x[1] ? 0 : 1);
	ll c = x[2] - x[1];
	cout << a + 2*b + c << endl;
}