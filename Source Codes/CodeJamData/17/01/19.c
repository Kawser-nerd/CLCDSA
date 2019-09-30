#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		string s; int K;
		cin >> s >> K;
		int r = 0;
		int i,j,k;
		for(i=0; i<s.size(); i++)
		{
			while(s[i] == '+' && i < s.size())
				i++;
			if (i >= s.size())
				break;
			if (i+K > s.size())
				break;
			for(int j=0; j<K; j++)
				if (s[i+j] == '+') s[i+j] = '-';
				else s[i+j] = '+';
			r++;
		}
		if (i >= s.size())
			printf("Case #%d: %d\n", cc, r);
		else
			printf("Case #%d: IMPOSSIBLE\n", cc);
	}
}
