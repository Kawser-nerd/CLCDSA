#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* s = new int[N];
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		s[i] = temp;
		sum += temp;

	}
	sort(s, s + N);
	if (sum % 10 != 0)
	{
		cout << sum << endl;
	}
	else
	{
		bool in = false;
		for (int i = 0; i < N; i++)
		{
			if (s[i] % 10 != 0)
			{
				sum -= s[i];
				in = true;
				break;
			}
		}
		if (in == false)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << sum << endl;
		}
	}
	return 0;
}