#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int a;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int ans = v.at(N - 1) - v.at(0);

	cout << ans << endl;
	
	return 0;
}