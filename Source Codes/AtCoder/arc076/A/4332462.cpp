#include <iostream>
#include <string>
using namespace std;

int main() {
	int inu, monkey;
	cin >> inu >> monkey;

	if (abs(inu - monkey) >= 2)
	{
		cout << 0 << endl;
	}
	else
	{
		if (inu == monkey)
		{
			//?????
			long long output = 2;
			for (int i = inu; i > 0; i--)
			{
				output *= i;
				output = output % 1000000007;
				output *= i;
				output = output % 1000000007;
			}

			cout << output << endl;
		}
		else
		{
			if (monkey > inu)
			{
				int temp = inu;
				inu = monkey;
				monkey = temp;
			}
			long long output = inu;
			inu--;
			for (int i = inu; i > 0; i--)
			{
				output *= i;
				output = output % 1000000007;
				output *= i;
				output = output % 1000000007;
			}
			cout << output << endl;
		}

	}

	return 0;
}