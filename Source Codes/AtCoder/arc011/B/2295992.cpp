#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	bool b = false;
	for (int i = 0; i < N; i++) {
		string s, st; cin >> s;
		if (i&&b)st += " ";
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		bool B = false;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'b' || s[j] == 'c') { st += "1"; B = true; b = true; }
			else if (s[j] == 'd' || s[j] == 'w') { st += "2"; B = true; b = true; }
			else if (s[j] == 't' || s[j] == 'j') { st += "3"; B = true; b = true; }
			else if (s[j] == 'f' || s[j] == 'q') { st += "4"; B = true; b = true; }
			else if (s[j] == 'l' || s[j] == 'v') { st += "5"; B = true; b = true; }
			else if (s[j] == 's' || s[j] == 'x') { st += "6"; B = true; b = true; }
			else if (s[j] == 'p' || s[j] == 'm') { st += "7"; B = true; b = true; }
			else if (s[j] == 'h' || s[j] == 'k') { st += "8"; B = true; b = true; }
			else if (s[j] == 'n' || s[j] == 'g') { st += "9"; B = true; b = true; }
			else if (s[j] == 'z' || s[j] == 'r') { st += "0"; B = true; b = true; }
		}
		if (B)cout << st;
	}
	cout << endl;
}