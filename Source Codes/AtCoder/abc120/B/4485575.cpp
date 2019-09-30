#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b, k;
	vector<int> nums;

	cin >> a >> b >> k;

	for (int i = 1; i < max(a, b) + 1; i++) {
		if (a % i == 0 and b % i == 0) {
			nums.push_back(i);
		}
	}
	reverse(nums.begin(), nums.end());

	cout << nums[k-1] << endl;

	return 0;

}