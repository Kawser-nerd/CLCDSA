#include <iostream>
#include <vector>
#include <map>

using namespace std;

int gcd(int m, int n) {
    if (m < n) {
        return gcd(n, m);
    }
    if (n==0) {
        return abs(m);
    } else {
        return gcd(n, m % n);
    }
}

int lcm(int m, int n) {
    return abs(m * n) / gcd(m, n);
}


int main() {
	int N, X;
    vector<int> x;
    cin >> N >> X;

    for (size_t i = 0; i < N; i++) {
        int xi;
        cin >> xi;
		x.push_back(xi);
    }
	x.push_back(X);

	sort(x.begin(), x.end());

	int result = x[1] - x[0];
    for (size_t i = 2; i < x.size(); i++) {
		result = gcd(result, x[i] - x[i-1]);
	}

	cout << result << endl;
}