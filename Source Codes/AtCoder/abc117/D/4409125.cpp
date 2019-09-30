#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

unsigned long long f(unsigned long long x, const vector<unsigned long long> &A) {
	unsigned long long out = 0;
	bitset<40> a(x);
	for(auto &y: A) {
		bitset<40> b(y);
		b ^= a;
		out += b.to_ullong();
	}
	return out;
}

int main() {
	unsigned long long N, K;
	cin >> N >> K;

	//10^12 < 2^40

	bitset<40> k(K);

	vector<unsigned long long> A(N);
	for(auto &x: A) cin >> x;

	vector<int> c(40);
	for(auto &&x: A) {
		bitset<40> b(x);
		for(int i = 0; i < 40; i++) {
			if(b[i]) c[i]++;
		}
	}


	bitset<40> x(0);
	for(int i = 0; i < 40; i++) {
		if(c[i] <= N / 2) x[i] = true;
	}

	//cout << k << endl;
	//cout << x << endl;
	bool flag = false;
	for(int i = 39; i >= 0; i--) {
		if(flag == true) continue;
		if(k[i] == false) x[i] = false;
		if(k[i] == true && x[i] == false) flag = true;
	}

	//cout << x << endl;
	// f(X) = sum (X ^ A_i)
	// MAX?????X^A_i??????11111...111?????

	cout << f(x.to_ullong(), A) << endl;
}