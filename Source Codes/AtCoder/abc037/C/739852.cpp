#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int n, k;
	vector<int> a;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	long long y = 0;
	for (int i = 0; i < n-k+1; i++) {
		long long x = 0;
		for (int j = i; j < i+k; j++) {
			x += a[j];
		}
		y += x;
	}
	cout << y << endl;

	return 0;
}