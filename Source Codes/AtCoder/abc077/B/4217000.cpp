#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<cmath>
#include<iomanip>
#include<iostream>
using namespace std;

int main() {
	long long int a,j,ans;
	cin >> a;
	for (int i = 1;i < 110000;i++) {
		ans = i * i;
		j = i;
		if (ans > a)
			break;
	}
	cout << (j - 1)*(j  - 1) << endl;
}