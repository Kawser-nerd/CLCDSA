#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;
	int aSize = a.size();	

	for (int i = 0; i < aSize; i++)
	{
		if (a[i] == 'a')
		{
			a.erase(a.begin() + i);
			i--;
			aSize--;
		}else if (a[i] == 'i')
		{
			a.erase(a.begin() + i);
			i --;
			aSize--;
		}else if (a[i] == 'u')
		{
			a.erase(a.begin() + i);
			i --;
			aSize--;
		}else if (a[i] == 'e')
		{
			a.erase(a.begin() + i);
			i --;
			aSize--;
		}else if (a[i] == 'o')
		{
			a.erase(a.begin() + i);
			i --;
			aSize--;
		}
	}
		cout << a << endl;

}