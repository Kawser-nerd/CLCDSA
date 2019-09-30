#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ll N, K;
    cin >> N >> K;

	cout << (N%K==0 ? 0 : 1) << endl;
}