#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define V2D(A, T, N, M, V) vector<vector<T> > A(N, vector<T>(M, V))
#define V3D(A, T, N, M, K, V) vector<vector<vector<T> > > A(N, vector<vector<T> >(M, vector<T>(K, V)))

void solveTest() {
	int N;
	cin >> N;
	if (!N) {
		cout << 0 << endl;
		return;
	}
	vector<int> cards(N);
	for (int i = 0; i < N; ++i) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());
	for (int ans = N; ans >= 1; ans--) {
		multiset<int> data(cards.begin(), cards.end());
		multiset<int> lastCards;
		bool ok = true;
		while (!data.empty()) {
			int curCard = *data.begin();
			data.erase(data.begin());
			multiset<int>::iterator it = lastCards.find(curCard - 1);
			if (it == lastCards.end()) {
				for (int i = 1; i < ans; i++) {
					multiset<int>::iterator it1 = data.find(curCard + i);
					if (it1 == data.end()) {
						ok = false;
						break;
					}
					else {
						data.erase(it1);
					}
				}
				lastCards.insert(curCard + ans - 1);
			}
			else {
				lastCards.erase(it);
				lastCards.insert(curCard);
			}
			if (!ok) break;
		}
		if (ok) {
			cout << ans << endl;
			return;
		}
	}
	assert(false);
}

int main() {
	int nt;
	cin >> nt;
	for (int it = 1; it <= nt; ++it) {
		printf("Case #%d: ", it);
		solveTest();
	}
	return 0;
}
