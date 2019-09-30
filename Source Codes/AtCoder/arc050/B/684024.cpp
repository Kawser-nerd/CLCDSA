#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long X,Y,x,y;
	cin >> X >> Y >> x >> y;
	long long l,h;
	l = 0;h=min(X,Y)+1;
	while(h-l>1)
	{
		long long m = (h + l) / 2;
		if((X-m) / (x - 1) + (Y-m) / (y-1) >= m)
		{
			l = m;
		}
		else
		{
			h = m;
		}
	}
	cout << l;
    return 0;
}