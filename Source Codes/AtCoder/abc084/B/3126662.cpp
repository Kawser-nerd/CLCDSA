#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b;
	string s;
	bool flg = true;

	cin >> a >> b >> s;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (i == a) {
			if (s[i] != '-') {
				flg = false;
			}
		}
		else {
			if (s[i]<'0' || s[i]>'9') {
				flg = false;
			}
		}
	}

	if (flg)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}