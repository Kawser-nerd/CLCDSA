#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, A, B;

	cin >> N >> A >> B;
	cout << min((N*A), B) << endl;

	return 0;
}