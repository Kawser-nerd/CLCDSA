#include<iostream>
#include<string>
using namespace std;
int main() {
	string S;
	cin >> S;
	int alphabet[26] = { 0 };
	for (int i = 0; i < (int)S.length(); i++)alphabet[(int)S[i] - (int)'a']++;
	int single = 0, pair = 0;
	for (int i = 0; i < 26; i++) {
		single += alphabet[i] % 2;
		pair += alphabet[i] / 2;
	}
	if (single <= 1)cout << single + pair * 2 << endl;
	else cout << 1 + (pair / single) * 2 << endl;
}