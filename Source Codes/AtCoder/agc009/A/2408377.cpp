#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long int a[n],b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	long long int plus = 0;
	for(int i = n - 1; i >= 0; i--) {
		long long int nowa = a[i] + plus;
		if(nowa % b[i] == 0) continue;
		if(nowa <= b[i]) {
			plus += b[i] - nowa;
		} else {
			plus += b[i] - (nowa % b[i]);
		}



	}

	cout << plus << endl;



}