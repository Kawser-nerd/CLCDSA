#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;



int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int smax;
		string lv;
		cin >> smax >> lv;
		int r = 0;
		int c = 0;
		for(int i=0; i<=smax; i++)
		{
			int t = 0;
			if (lv[i] != '0' && i > c)
				t = i-c;
			c += lv[i]-'0';
			r += t;
			c += t;
		}
		printf("Case #%d: %d\n", cc, r);
	}
}
