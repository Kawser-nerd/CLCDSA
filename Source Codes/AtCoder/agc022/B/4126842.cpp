#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> ans = { 2, 3, 4, 9 };
	if (N >= 4) {
		N -= 4;
	}
	else {
		ans = { 2, 3, 25 };
		N -= 3;
	}
	for (int i = 8; i <= 30000 && N >= 2; i += 6) {
		ans.push_back(i);
		ans.push_back(i + 2);
		N -= 2;
	}
	for (int i = 15; i <= 30000 && N >= 2; i += 12) {
		ans.push_back(i);
		ans.push_back(i + 6);
		N -= 2;
	}
	for (int i = 6; i <= 30000 && N >= 1; i += 6) {
		ans.push_back(i);
		N -= 1;
	}
	for (int i : ans) {
		cout << i << ' ';
	}
	return 0;
}