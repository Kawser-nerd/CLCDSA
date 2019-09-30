#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
	long long N, M, scc, cccc;
	cin >> N >> M;
	scc = min(N, M / 2);
	cccc = (M - scc * 2) / 4;
	cout << scc + cccc << endl;
}