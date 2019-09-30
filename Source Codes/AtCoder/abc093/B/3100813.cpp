#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int A, B, K;
	vector<int> v;

	cin >> A >> B >> K;

	for (int i = A; i < A + K&&i<=B; i++)
	{
		v.push_back(i);
	}

	
	for (int i = B; i >B-K&&i>=A; i--)
	{
		v.push_back(i);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
		cout << *it << endl;
	}

	return 0;
}