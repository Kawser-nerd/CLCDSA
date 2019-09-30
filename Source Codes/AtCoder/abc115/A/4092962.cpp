#include <string>
#include <iostream>
using namespace std;
int main() {
	int D;
	cin >> D;
	cout << string("Christmas");
	for (int i = D; i < 25; ++i) cout << " Eve";
	cout << endl;
	return 0;
}