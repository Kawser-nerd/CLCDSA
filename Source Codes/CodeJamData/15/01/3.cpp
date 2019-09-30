#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	int combien[1005];
	int SMax;
	int total, encours;
	char c;

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		scanf("%d ", &SMax);

		for(int i = 0; i <= SMax; i++)
		{
			scanf("%c", &c);
			combien[i] = c-'0';
		}
		scanf("\n");

		int encours = 0;
		int ajoute = 0;
		for(int i = 0; i <= SMax; i++)
		{
			encours += combien[i];
			if(encours < i+1)
			{
				ajoute += i+1-encours;
				encours = i + 1;
			}
		}
		printf("%d\n", ajoute);
	}

	return 0;
}
