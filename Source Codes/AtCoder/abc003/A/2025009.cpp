#include <iostream>
using namespace std;

int main()
{
	int n,total;
	cin >> n;
	total = 0;

	for (int i = 1; i < n+1; i++)
	{
		total += i * 10000;
	}

	cout << total / n<< endl;


}