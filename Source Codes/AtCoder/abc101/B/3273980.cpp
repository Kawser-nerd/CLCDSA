#include <iostream>

using namespace std;

int main()
{
	int n, d=0;
	cin >> n;
	int x=n;
	while(n>0)
	{
		d+=n%10;
		n/=10;
	}
	if(x%d==0)
	cout << "Yes" << endl;
	else
	cout << "No" << endl;
}