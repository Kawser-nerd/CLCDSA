#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

int main() {
	string w;
	cin >> w;

	vector<char> word;

	for (int i = 0; i < w.length(); i++)
	{
		if (w[i] != 'a'&&w[i] != 'i'&&w[i] != 'u'&&w[i] != 'e'&&w[i] != 'o') {
			word.push_back(w[i]);
		}
	}

	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i];
	}

	cout << endl;

	return 0;
}