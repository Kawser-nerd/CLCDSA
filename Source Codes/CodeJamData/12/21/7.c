#include <stdio.h>
#include <stdlib.h>

// Problem-A

void trie(int s[200], int t[200], int N)
{
	int i, j, c;
	for(i = 0; i < N; i++)
	{
		t[i] = s[i];
	}
	for(i = 1; i < N; i++)
	{
		j = i;
		while(j > 0 && t[j] < t[j-1])
		{
			c = t[j];
			t[j] = t[j-1];
			t[j-1] = c;
			j--;
		}
	}
}

int main()
{
	int T, test, i, j, N, s[200], t[200], X, somme, fini, k;
	double resultat, cherche;
	scanf("%d", &T);
	for(test = 1; test <= T; test++)
	{
		scanf("%d", &N);
		printf("Case #%d: ", test);
		X = 0;
		for(i = 0; i < N; i++)
		{
			scanf("%d", &s[i]);
			X += s[i];
		}
		trie(s, t, N);
		t[N] = 1000000000;
		fini = 1;
		for(i = 0; i < N && fini; i++)
		{
			somme = 0;
			// On teste le cas où les plus nuls ont une note entre t[0] et t[1]
			// Il faut alors donner cette note à tous ceux ayant moins de t[1].
			// Il y en a i+1
			for(j = 0; j <= i; j++) somme += t[j];
			cherche = (X+somme)/(double)(i+1);
			if(cherche <= t[i+1]) fini = 0;
		}
		for(i = 0; i < N; i++)
		{
			if(cherche <= s[i]) printf("%.6lf ", 0.0);
			else printf("%.6lf ", 100*(cherche-s[i])/(double)X);
		}
		printf("\n");
		
	}
	return 0;
}
