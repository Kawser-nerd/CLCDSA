#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	bool flg = true;
	int cnt = 0;
	cin >> S;

	for (int i = 0; i < (int)S.length(); i++)
	{
		if (i == 0){
			if (S[i] != 'A') {
				flg = false;
			}
		}
		else if(i>=2&&i<= (int)S.length()-2){
			if (S[i] == 'C') {
				cnt++;
			}
		}
		else if(S[i]<'a'||S[i]>'z') {
				flg = false;
		}
	}

	if (cnt != 1)
		flg = false;

	if (flg)
		cout << "AC" << endl;
	else
		cout << "WA" << endl;

	return 0;
}