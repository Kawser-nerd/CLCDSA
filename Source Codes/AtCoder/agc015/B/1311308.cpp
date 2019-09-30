//I Guds namn
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
	string s;
	cin >> s;
	ll n = s.size();
	ll ans = n * (n - 1);
	for(ll i = 2;i < s.size();i++)
		if(s[i - 1] == 'U')
			ans += i - 1;
		else
			ans += n - i;
	cout << ans << endl;
	return 0;
}
//KAG