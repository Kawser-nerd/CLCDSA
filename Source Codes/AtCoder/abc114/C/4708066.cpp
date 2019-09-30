#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
string str;
int num = 0;
void DFS(int flag3, int flag5, int flag7, string s)
{
	if (s.size() == str.size())
	{
		if (s > str)
			return;
	}
	else if (s.size() > str.size())
		return;
	if (flag3 == 1 && flag5 == 1 && flag7 == 1)
		num++;
	DFS(1, flag5, flag7, s + '3');
	DFS(flag3, 1, flag7, s + '5');
	DFS(flag3, flag5, 1, s + '7');
}
int main()
{
	cin >> str;
	string s = "";
	DFS(0, 0, 0, s);
	cout << num << endl;
	system("pause");
	return 0;
}