#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i, m, k) for(int i = m; i < k; ++i)
#define REP(i, k) for(int i = 0; i < k; ++i)

int main() {
	string card = "123456";
	int I;
	cin >> I;
	--I;
	I %= 30;
	for (int i = 0; i <= I; ++i) {
		string buf;
		swap(card[i % 5], card[i % 5 + 1]);

	}
	cout << card.c_str() << endl;

	system("pause");
	return 0;
}