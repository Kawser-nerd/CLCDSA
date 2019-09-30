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
	int X, R, C;

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);

		scanf("%d %d %d", &X, &R, &C);

		int s;
		if(R < C)
		{
			s = R;
			R = C;
			C = s;
		}

		if(X >= 7)
		{
			printf("RICHARD\n");
		}
		else if(X == 1)
		{
			printf("GABRIEL\n");
		}
		else if(X == 2)
		{
			if(R % 2 == 0 || C % 2 == 0) printf("GABRIEL\n");
			else printf("RICHARD\n");
		}
		else if(X == 3)
		{
			if((R*C) % 3 != 0) printf("RICHARD\n");
			else
			{
				if(C == 1) printf("RICHARD\n");
				else printf("GABRIEL\n");
			}
		}
		else if(X == 4)
		{
			if((R*C) % 4 != 0) printf("RICHARD\n");
			else
			{
				if(C == 1 || R <= 3) printf("RICHARD\n"); // On ne sait pas placer la pièce
				else if(C == 2) printf("RICHARD\n"); // Le T va tout casser
				else if(C >= 3) printf("GABRIEL\n");
			}
		}
		else if(X == 5)
		{
			if((R*C) % 5 != 0) printf("RICHARD\n");
			else
			{
				if(C == 1 || R <= 4) printf("RICHARD\n");
				else if(C == 2) printf("RICHARD\n"); // Certaines pièces rentrent pas
				else if(C == 3)
				{
					if(R == 5) printf("RICHARD\n"); // Le W
					else printf("GABRIEL\n");
				}
				else if(C >= 4) printf("GABRIEL\n");
			}
		}
		else if(X == 6)
		{
			if((R*C) % 6 != 0) printf("RICHARD\n");
			else
			{
				if(C == 1 || R <= 5) printf("RICHARD\n");
				else if(C == 2) printf("RICHARD\n"); // Rentre pas
				else if(C == 3) printf("RICHARD\n");
				else if(C >= 4) printf("GABRIEL\n");
			}
		}

	}

	return 0;
}
