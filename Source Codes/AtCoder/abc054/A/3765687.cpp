#include <iostream>
using namespace std;

int main() {
	int A, B;
	
	cin >> A >> B;
	string res = "";

	if (A == B) res = "Draw";
	else if (A == 1) res = "Alice";
	else if (B == 1) res = "Bob";
	else if (A < B) res = "Bob";
	else if (A > B) res = "Alice";

	cout << res << endl;
}