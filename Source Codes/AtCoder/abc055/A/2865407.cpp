#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int N;	cin >> N;

	cout << 800 * N - 200 * (N / 15) << endl;
	return 0;
}