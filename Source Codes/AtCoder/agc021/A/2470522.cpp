// AGC21-A.cpp : ????????????? ???????????
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	cin >> n;
	reverse(n.begin(), n.end());
    for (size_t i = 0; i < n.size()-1; i++)
	{
		if (n[i] != '9')
		{
			n[i + 1] -= 1;
			n[i] = '9';
		}
	}
	long long sum = 0;
	for (size_t i = 0; i < n.size(); i++)
	{
		sum += n[i] - '0';
	}

	cout << sum << endl;
	return 0;
}