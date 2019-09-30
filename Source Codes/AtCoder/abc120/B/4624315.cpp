#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int k; cin >> k;
	int num = 0;
	vector<int> v1;
	if (a <= b) {
		for (int i = 1; i <= a; i++) {
			if (a%i == 0 && b%i == 0) {
				v1.push_back(i);
			}
			
		}
	}
	else {
		for (int i = 1; i <= a; i++) {
			if (a%i == 0 && b%i == 0) {
				v1.push_back(i);
				}
			}

		}
	reverse(v1.begin(), v1.end());
	cout << v1[k - 1];
    system("pause");
	return 0;
}