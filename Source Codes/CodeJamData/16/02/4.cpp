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
	string s;
	
	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		getline(cin, s);
		
		char encours = '+';
		int count = 0;
		
		for(int i = s.size()-1; i >= 0; i--)
		{
			if(s[i] != encours) count++;
			encours = s[i];
		}
		
		printf("%d\n", count);

	}

	return 0;
}
