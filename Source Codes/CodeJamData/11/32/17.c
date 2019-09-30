#include <stdlib.h>
#include <stdio.h>

#define MAX 1000

int compare(const void * a, const void * b)
{
  return (*(int*)b - *(int*)a);
}

int main(void)
{
	FILE *f_in, *f_out;
	if (!(f_in = fopen("B.in", "r")))
	{
		printf("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("B.out", "w+");
	int i, j, n, nb;
	int dest;
	int dist[MAX];
	int num_boosters, tps_boosters;
	int positions[MAX];
	int fini;
	int gains[MAX];
	int g;
	
	
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d: ", i+1);
		//Récupérons les premiers paramètres.
		fscanf(f_in, "%d %d %d %d ", &num_boosters, &tps_boosters, &dest, &nb);
		//Récupérons les distances inter-étoiles.
		for(j = 0; j < nb; j++)
		{
			fscanf(f_in, "%d ", &dist[j]);
		}
		//Calculons le tableau des positions.
		positions[0] = 0;
		for(j = 0; j < dest; j++)
		{
			positions[j+1] = positions[j]+dist[j%nb];
		}
		//Déterminons les gains.
		fini = 0;
		for(j = 0; j < dest; j++)
		{
			if (fini == 1)
			{
				gains[j] = positions[j+1]-positions[j];
			}
			else
			{
				if (2*positions[j+1] > tps_boosters)
				{
					//En construisant ici, on a un gain partiel.
					gains[j] = (2*positions[j+1]-tps_boosters)/2;
					//Les boosters seront finis.
					fini = 1;
				}
				else
				{
					if (2*positions[j] == tps_boosters)
					{
						//On a un gain total.
						gains[j] = positions[j+1] - positions[j];
						//Et c'est fini.
						fini = 1;
					}
					else
					{
						//On a aucun gain car le booster sera fin après qu'on ait quitté l'étoile.
						gains[j] = 0;
					}
				}
			}
		}
		printf("Gains:\n");
		for(j = 0; j < dest; j++)
		{
			printf("%d, ", gains[j]);
		}
		printf("\n");
		//Trions la liste.
		
	  qsort(gains, dest, sizeof(int), compare);
		
		//Maximisons nos gains.
		g = 0;
		for(j = 0; j < num_boosters; j++)
		{
			g+=gains[j];
		}
		printf("Gains: %d\n", g);
		//Affichage des résultats.
		fprintf(f_out, "%d\n", (2*positions[dest]-g));
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
