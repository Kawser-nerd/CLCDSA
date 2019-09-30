// AGC19-A.cpp : ????????????? ???????????
//
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{
	long long q, h, s, d, n;
	cin >> q >> h >> s >> d;
	cin >> n;
	long long sum = 0;
	
	long two = min({ d, 2 * s, 4 * h, q * 8 });
	long one = min({ s, 2 * h, q * 4 });
	
	sum += (n / 2) * two;
	sum += (n % 2) * one;
	cout << sum << endl;
	
    return 0;
}