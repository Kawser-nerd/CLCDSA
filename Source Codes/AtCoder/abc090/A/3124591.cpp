#include <iostream>
#include <string>
using namespace std;
int main() {
	string s[3];
	
	for (int i = 0; i < 3; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(i==j)
				cout << s[i][j];
		}
	}

	cout << endl;

	return 0;
}