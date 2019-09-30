#include<iostream>

using namespace std;

int main() {

	int day;

	cin >> day;

	if (day == 25) {
		cout << "Christmas";
	}
	else if (day == 24) {
		cout << "Christmas Eve";
	}
	else if (day == 23) {
		cout << "Christmas Eve Eve";
	}
	else if (day == 22) {
		cout << "Christmas Eve Eve Eve";
	}

	return 0;
}