#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<string> answers{ "Do","","Re","","Mi","Fa","","So","","La","","Si" };
	string s1 = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
	string s2;
	cin >> s2;
	for (int i = 0; i < s2.size(); i++) {
		if (s1.substr(i, 20) == s2) {
			cout << answers[i] << endl;
			break;
		}
	}
}