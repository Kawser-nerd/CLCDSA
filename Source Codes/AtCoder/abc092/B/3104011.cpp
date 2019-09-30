#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, D, X;
	int cnt = 0;
	vector<int> A;

	cin >> N >> D >> X;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		cnt += (D / A.at(i));
		if (D % A.at(i)!=0) {
			cnt++;
		}
	}

	cout << cnt + X << endl;

	return 0;
}