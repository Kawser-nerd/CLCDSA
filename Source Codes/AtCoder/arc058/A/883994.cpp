#include <iostream>
#include <set>

using namespace std;

int n, m; set<int> S;

bool Check() {
	int nn = n;
	while (nn) {
		int digit = nn % 10;
		if (S.find(digit) != S.end()) {
			return false;
		}
		nn /= 10;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++) {
		int x;
		scanf("%d", &x);
		S.insert(x);
	}
	while (!Check()) n ++;
	printf("%d\n", n);
}