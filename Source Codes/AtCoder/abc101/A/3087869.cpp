#include <iostream>
#include <string>
using namespace std;
int main() {
	string S;
	int ans = 0;

	cin >> S;

	for (int i = 0; i < (int)S.size(); i++)
	{
		if (S[i] == '+')
			ans++;
		if (S[i] == '-')
			ans--;
	}

	cout << ans << endl;

	return 0;
}