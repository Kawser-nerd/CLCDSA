#include <iostream>
#include <string>
using namespace std;
int main() {
	string N;
	cin >> N;

	if (N[0] == '9' || N[1] == '9')
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}