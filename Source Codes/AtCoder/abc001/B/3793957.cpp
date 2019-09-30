#include <iostream>
using namespace std;
int main()
{
	int n;
	char vv;
	cin >> n;
	if(n < 100){cout << "00" << endl;}
	else if(n < 1000){cout << "0" << n/100 << endl;}
	else if(n <= 5000){cout << n/100 << endl;}
	else if(n <= 30000){cout << 50 + n/1000 << endl;}
	else if(n <= 70000){cout << (((n/1000)-30)/5)+80 << endl;}
	else if(n > 70000){cout << "89" << endl;}
	
	return 0;
}