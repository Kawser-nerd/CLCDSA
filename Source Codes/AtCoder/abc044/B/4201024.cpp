#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	string s;
	int count = 0;
	int a[30];
	cin >> s;
	for (int num = 0;num< 30;num++) {
		a[num] = 0;
	}
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'a')
			a[0] += 1;
		if (s[i] == 'b')
			a[1] += 1;
		if (s[i] == 'c')
			a[2] += 1;
		if (s[i] == 'd')
			a[3] += 1;
		if (s[i] == 'e')
			a[4] += 1;
		if (s[i] == 'f')
			a[5] += 1;
		if (s[i] == 'g')
			a[6] += 1;
		if (s[i] == 'h')
			a[7] += 1;
		if (s[i] == 'i')
			a[8] += 1;
		if (s[i] == 'j')
			a[9] += 1;
		if (s[i] == 'k')
			a[10] += 1;
		if (s[i] == 'l')
			a[11] += 1;
		if (s[i] == 'm')
			a[12] += 1;
		if (s[i] == 'n')
			a[13] += 1;
		if (s[i] == 'o')
			a[14] += 1;
		if (s[i] == 'p')
			a[15] += 1;
		if (s[i] == 'q')
			a[16] += 1;
		if (s[i] == 'r')
			a[17] += 1;
		if (s[i] == 's')
			a[18] += 1;
		if (s[i] == 't')
			a[19] += 1;
		if (s[i] == 'u')
			a[20] += 1;
		if (s[i] == 'v')
			a[21] += 1;
		if (s[i] == 'w')
			a[22] += 1;
		if (s[i] == 'x')
			a[23] += 1;
		if (s[i] == 'y')
			a[24] += 1;
		if (s[i] == 'z')
			a[25] += 1;
	}
	for (int j = 0;j < 26;j++) {
		if (a[j] % 2 == 1)
			count++;
	}
	if (count > 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}