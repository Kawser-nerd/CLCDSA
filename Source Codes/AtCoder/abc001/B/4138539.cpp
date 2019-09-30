#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main(){
	int m;
	cin >> m;

	if (m < 100)
		cout << "00" << endl;
	else if (m < 1000)
		cout << "0" << m / 100 << endl;
	else if (m <= 5000)
		cout << m / 100 << endl;
	else if (m <= 30000 and m >= 6000)
		cout << m / 1000 + 50 << endl;
	else if (m >= 35000 and m <= 70000)
		cout << (m / 1000 - 30) / 5 + 80 << endl;
	else if (m >= 70000)
		cout << 89 << endl;
}