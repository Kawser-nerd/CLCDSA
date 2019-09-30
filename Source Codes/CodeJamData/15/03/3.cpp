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

// 1 : 1
// 2 : i
// 3 : j
// 4 : k
// -1 : -1
// -2 : -i
// -3 : -j
// -4 : -k

int fakeproduit(int a, int b)
{
	if(a == 1) return b;
	else if(b == 1) return a;
	else if(a == b) return -1;
	else if(a == 2 && b == 3) return 4;
	else if(a == 2 && b == 4) return -3;
	else if(a == 3 && b == 2) return -4;
	else if(a == 3 && b == 4) return 2;
	else if(a == 4 && b == 2) return 3;
	else if(a == 4 && b == 3) return -2;
	else fprintf(stderr, "Erreur\n");
}

int produit(int a, int b)
{
	bool neg = false;
	if(a < 0)
	{
		neg = !neg;
		a = -a;
	}
	if(b < 0)
	{
		neg = !neg;
		b = -b;
	}
	int res = fakeproduit(a, b);
	if(neg) return -res;
	else return res;
}


int main()
{
	int T;
	long long int L, X;
	int s[10005];
	char c;
	int valued[10005];
	int valueg[10005];

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);

		scanf("%lld %lld\n", &L, &X);

		for(int i = 0; i < L; i++)
		{
			scanf("%c", &c);
			s[i] = c - 'i' + 2;
		}

		valueg[0] = 1;
		for(int i = 1; i <= L; i++)
		{
			valueg[i] = produit(valueg[i-1], s[i-1]); // Produit des i premiers termes en partant de la gauche
		}
		valued[0] = 1;
		for(int i = 1; i <= L; i++)
		{
			valued[i] = produit(s[L-i], valued[i-1]); // Produit des i premiers termes en partant de la droite
		}

		// Trouver le premier "i" à gauche :

		int blocentier = 1;
		long long int x = 0;
		bool trouve = false;
		long long int trouvex, trouvei;

		while((x == 0 || blocentier != 1) && !trouve && x < X)
		{
			for(int i = 1; i <= L && !trouve; i++)
			{
				if(produit(blocentier, valueg[i]) == 2)
				{
					trouve = true;
					trouvex = x;
					trouvei = i;
				}
			}
			blocentier = produit(blocentier, valueg[L]);
			x = x+1;
		}

		// Trouve le premier "k" à droite

		blocentier = 1;
		x = 0;
		bool trouve2 = false;
		long long int trouvex2, trouvei2;

		while((x == 0 || blocentier != 1) && !trouve2 && x < X)
		{
			for(int i = 1; i <= L && !trouve2; i++)
			{
				if(produit(valued[i], blocentier) == 4)
				{
					trouve2 = true;
					trouvex2 = x;
					trouvei2 = i;
				}
			}
			blocentier = produit(valueg[L], blocentier);
			x = x+1;
		}

		if(!trouve || !trouve2)
		{
			printf("NO\n");
		}
		else
		{
			long long int total = L * trouvex + trouvei + L * trouvex2 + trouvei2;
			fprintf(stderr, "Total : %lld - %lld\n", total,  X*L);
			if(total > (long long int)X*L)
			{
				printf("NO\n");
			}
			else
			{
				// It remains to have ijk in total, i.e. -1
				blocentier = valueg[L];
				bool ok = false;
				if(blocentier == 1)
				{
				}
				else if(blocentier == -1)
				{
					if(X % 2 == 1) ok = true;
				}
				else
				{
					if(X % 4 == 2) ok = true;
				}
				if(ok) printf("YES\n");
				else printf("NO\n");
			}
		}

		scanf("\n");
	}

	return 0;
}
