#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	for(int i = n; i <= 999; i++) {
		str = to_string(i);
		if (str[0] == str[1] && str[1] == str[2]) {
			break;
		}
	}

	cout << str << endl;

	return 0;
}