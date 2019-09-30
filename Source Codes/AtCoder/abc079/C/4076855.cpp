#include <iostream>

using namespace std;

int main() {
	int input;
	cin >> input;
	int A, B, C, D;
	A = input / 1000;
	B = (input % 1000) / 100;
	C = (input % 100) / 10;
	D = input % 10;
	if ((A + B + C + D) == 7)cout << A << "+" << B << "+" << C << "+" << D << "=" << 7 <<endl;
	else if ((A + B + C - D) == 7)cout << A << "+" << B << "+" << C << "-" << D << "=" << 7 << endl;
	else if ((A + B - C + D) == 7)cout << A << "+" << B << "-" << C << "+" << D << "=" << 7 << endl;
	else if ((A + B - C - D) == 7)cout << A << "+" << B << "-" << C << "-" << D << "=" << 7 << endl;
	else if ((A - B + C + D) == 7)cout << A << "-" << B << "+" << C << "+" << D << "=" << 7 << endl;
	else if ((A - B + C - D) == 7)cout << A << "-" << B << "+" << C << "-" << D << "=" << 7 << endl;
	else if ((A - B - C + D) == 7)cout << A << "-" << B << "-" << C << "+" << D << "=" << 7 << endl;
	else if ((A - B - C - D) == 7)cout << A << "-" << B << "-" << C << "-" << D << "=" << 7 << endl;
	return 0;
}