#include<iostream>
using namespace std;
int main() {
	int k; cin >> k;
	long long f[50]; f[0] = 1; f[1] = 1;
	for (int i = 2; i <= k; i++)f[i] = f[i - 1] + f[i - 2];
	cout << f[k - 1] <<' '<< f[k] << endl;
	return 0;
}