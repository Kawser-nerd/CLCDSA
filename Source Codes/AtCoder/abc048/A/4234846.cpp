#include <iostream>
using namespace std;
#define ll long long
#include <string>
#include <algorithm>
int main()
{
	string s;
	getline(cin,s);
	char a;
	cout<<s[0];
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ')
		cout<<s[i+1];
	}
	return 0;
}