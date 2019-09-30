#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool Judge(string S,string T)
{
	for (int i = 0; i < S.length(); i++)
	{
		S = S.back()+ S.substr(0,S.size()-1);
		if (S == T)
			return true;
	}
	return false;
}

int main()
{
	string S,T;
	cin >> S >> T;
	if (S.size() != T.size())
	{
		cout << "No" << endl;
	}
	
	if (Judge(S,T))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}