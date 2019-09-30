#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	long long output = k;
	n--;
	for (int i = 0; i < n; i++)
	{
		output *= (k - 1);
	}
	cout << output << endl;
}