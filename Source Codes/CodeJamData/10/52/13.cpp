#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static unsigned int gcd(unsigned int a, unsigned int b) {
	return a==0 ? b : gcd(b%a, a);
}

static void runTest() {
	unsigned long long L;
	unsigned int N;
	cin >> L >> N;
	vector<unsigned int> B(N);
	for (unsigned int i=0; i<N; i++)
		cin >> B[i];
	unsigned long long M = *max_element(B.begin(), B.end());
	vector<unsigned long long> wasted(M);
	fill(wasted.begin(), wasted.end(), (unsigned long long)-1);
	wasted[0] = 0;
	for (unsigned int i=0; i<N; i++) {
		unsigned int b = B[i];
		unsigned int d = gcd((unsigned int)b, (unsigned int)M);
		for (unsigned int r=0; r<d; r++) {
			for (unsigned int j = r;;) {
				unsigned long long newWasted = wasted[j];
				if (newWasted==(unsigned long long)-1) {
					j = (j+b)%M;
					if (j==r)
						break;
					continue;
				}
				newWasted++;
				unsigned long long newRemainder = j + b;
				if (newRemainder>=M) {
					newRemainder -= M;
					newWasted--;
				}
				if (newWasted<wasted[newRemainder])
					wasted[newRemainder] = newWasted;
				j = (unsigned int)((j+b)%M);
				if (j==r)
					break;
			}
		}
	}
	if (wasted[L%M]==(unsigned long long)-1)
		cout << "IMPOSSIBLE\n";
	else
		cout << (wasted[L%M] + (L/M)) << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cout << "Case #" << (i+1) << ": ";
		runTest();
		cerr << (i+1) << endl;
	}
	return 0;
}
