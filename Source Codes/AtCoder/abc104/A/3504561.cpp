#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ll R;
    cin >> R;

	cout << ((R < 1200) ? "ABC" : ((R < 2800) ? "ARC" : "AGC"))  << endl;
}