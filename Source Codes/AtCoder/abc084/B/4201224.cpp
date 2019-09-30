#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	int a, b;
	string s;
	string num = "0123456789";
	cin >> a >> b >> s;
	int sum = 0;
	for (int i = 0;i < a;i++) {
		for (int j = 0;j < 10;j++) {
			if (s[i] == num[j])
				sum++;
		}
	}
	for (int k = a + 1;k < a + b+1;k++) {
		for (int l = 0;l < 10;l++) {
			if (s[k] == num[l])
				sum++;
		}
	}
	if (sum == a+b and s[a] == '-')
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}