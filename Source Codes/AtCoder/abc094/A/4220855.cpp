#include<iostream>
#include<string>

using namespace std;
int main()
{
	// ?????
	int a, b, x;
	cin >> a >> b >> x;
	if ((a <= x) & (a + b >= x))
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
	return 0;

}