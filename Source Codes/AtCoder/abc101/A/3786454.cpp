#include<iostream>
using namespace std;

int main() {

	char porm[4];
	int i,ans=0;

	for (i = 0; i < 4; i++) {
		cin >> porm[i];
		if (porm[i] == '+') {
			ans++;
		}
		else if (porm[i] == '-') {
			ans--;
		}
	}

	cout << ans;

	return 0;
}