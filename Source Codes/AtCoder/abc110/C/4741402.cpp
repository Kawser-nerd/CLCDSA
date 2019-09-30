#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;
	vector<int> alphabet(27);
	vector<int> alphabet2(27);
	string output = "Yes";
	for (int i = 0; i < S.length(); i++)
	{
		if (alphabet[S[i] - 'a'] == 0)
		{
			alphabet[S[i] - 'a'] = T[i];
		}
		else
		{
			if (alphabet[S[i] - 'a'] != T[i])
			{
				output = "No";
			}
		}
		if (alphabet2[T[i] - 'a'] == 0)
		{
			alphabet2[T[i] - 'a'] = S[i];
		}
		else
		{
			if (alphabet2[T[i] - 'a'] != S[i])
			{
				output = "No";
			}
		}
	}
	cout << output << endl;
	return 0;
}