#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	bool flg[3] = {
		false,false,false
	};

	cin >> s;

	for (int i = 0; i < 3; i++)
	{
		flg[s[i] - 'a'] = true;
	}

	bool ans = true;

	for (int i = 0; i < 3; i++)
	{
		if (flg[i] == false) {
			ans = false;
		}
	}

	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}