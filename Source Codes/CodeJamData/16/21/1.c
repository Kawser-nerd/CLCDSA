#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		string s;
		cin >> s;
		int cnt[300];
		memset(cnt, 0, sizeof(cnt));
		for(i=0; i<s.size(); i++)
			cnt[s[i]]++;
		int r[10];
		memset(r, 0, sizeof(r));
		if (cnt['Z'] != 0)
		{
			j = cnt['Z'];
			cnt['Z']-=j;
			cnt['E']-=j;
			cnt['R']-=j;
			cnt['O']-=j;
			r[0]+=j;	
		}
		if (cnt['W'] != 0)
		{
			j = cnt['W'];
			cnt['T']-=j;
			cnt['W']-=j;
			cnt['O']-=j;
			r[2]+=j;
		}
		if (cnt['U'] != 0)
		{
			j = cnt['U'];
			cnt['F']-=j;
			cnt['O']-=j;
			cnt['U']-=j;
			cnt['R']-=j;
			r[4]+=j;
		}
		if (cnt['F'] != 0)
		{
			j = cnt['F'];
			cnt['F']-=j;
			cnt['I']-=j;
			cnt['V']-=j;
			cnt['E']-=j;
			r[5]+=j;
		}
		if (cnt['X'] != 0)
		{
			j = cnt['X'];
			cnt['S']-=j;
			cnt['I']-=j;
			cnt['X']-=j;
			r[6]+=j;
		}
		if (cnt['S'] != 0)
		{
			j = cnt['S'];
			cnt['S']-=j;
			cnt['E']-=j;
			cnt['V']-=j;
			cnt['E']-=j;
			cnt['N']-=j;
			r[7]+=j;
		}
		if (cnt['O'] != 0)
		{
			j = cnt['O'];
			cnt['O']-=j;
			cnt['N']-=j;
			cnt['E']-=j;
			r[1]+=j;
		}
		if (cnt['R'] != 0)
		{
			j = cnt['R'];
			cnt['T']-=j;
			cnt['H']-=j;
			cnt['R']-=j;
			cnt['E']-=j;
			cnt['E']-=j;
			r[3]+=j;
		}
		if (cnt['N'] != 0)
		{
			j = cnt['N']/2;
			cnt['N']-=j;
			cnt['I']-=j;
			cnt['N']-=j;
			cnt['E']-=j;
			r[9] += j;
		}
		r[8] += cnt['G'];

		printf("Case #%d: ", cc);
		for(int i=0; i<10; i++)
			for(int j=0; j<r[i]; j++)
				printf("%d", i);
		printf("\n");
	}
}
