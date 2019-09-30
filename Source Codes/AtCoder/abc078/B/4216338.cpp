#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<cmath>
#include<iomanip>
#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans;
	ans = a / (b + c);
	if ((ans*(b+c)+ c) > a)
		cout << ans-1 << endl;
	else
		cout << ans  << endl;
}