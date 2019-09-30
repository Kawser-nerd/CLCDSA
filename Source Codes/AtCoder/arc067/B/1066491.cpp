#include <iostream>


using namespace std;

int main()
{
	long long n, a, b;
	cin >> n >> a >> b;
	int xi;
	cin >> xi;
	long long count = 0;
	for (int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
		long long raz = x - xi;
		long long as = raz * a;
		xi = x;
		if (as < b)count += as; else count += b;
	}
	cout << count;












	/*int n;
	cin >> n;
	int fact = 1;
	int mod = 1000000000;
	mod += 7;
	for (int i = 2; i <= n; i++) {
		fact *= i;
		fact = fact % mod;
	}

	int coun = 0;
	int ind = (fact / 2) + 2;
	for (int i = 1; i <= ind; i++)
	{
		if (fact % i == 0)coun++;
	}
	coun++;
	cout << coun;*/
	
}