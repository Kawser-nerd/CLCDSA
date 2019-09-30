//


#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long N;
	string s, n;

	cin >> N;
	cin >> s;
	cin >> n;

	unsigned cur = 0;
	for( unsigned i = 0 ; i < s.length() ; i++)
	{
		if (s[i] == n[cur])
			cur++;
		else
		{
			i -= cur;

			cur = 0;
		}
		
	}


	cout << max((unsigned long long)(s.length() + n.length() - cur), N);


}