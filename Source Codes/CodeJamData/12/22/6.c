#include <stdio.h>
#include <stdlib.h>

// Problem-B

int main()
{
	int T, test, i, j, sol[100][100], plafond[100][100], I, J, N, M, k;
	double temps[100][100], hauteuractuelle, hauteurdemandee, moment, H, hauteurfinale;
	scanf("%d", &T);
	for(test = 1; test <= T; test++)
	{
		scanf("%lf %d %d", &H, &N, &M);
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M; j++)
			{
				scanf("%d", &plafond[i][j]);
				temps[i][j] = 1000000000;
			}
		}
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M; j++)
			{
				scanf("%d", &sol[i][j]);
			}
		}
		temps[0][0] = 0;
		for(k = 0; k < 10000; k++)
		{
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M; j++)
			{
				// On regarde si on peut venir d'une case précédente
				if(i > 0)
				{
					I = i-1;
					J = j;
					if(temps[I][J] < 1000000000 && sol[i][j] <= plafond[i][j] - 50 && sol[I][J] <= plafond[i][j] - 50 && sol[i][j] <= plafond[I][J]-50)
					{
						hauteuractuelle = H-temps[I][J]*10;
						hauteurdemandee = plafond[i][j]-50;
						if(hauteuractuelle < hauteurdemandee) moment = temps[I][J];
						else moment = (H+50-plafond[i][j])/10.0;
						hauteurfinale = H - moment*10;
						if(moment == 0) moment = 0;
						else if(hauteurfinale >= 20+sol[I][J]) moment += 1;
						else moment += 10;
						if(moment < temps[i][j]) temps[i][j] = moment;
					}
				}
				if(i < N-1)
				{
					I = i+1;
					J = j;
					if(temps[I][J] < 1000000000 && sol[i][j] <= plafond[i][j] - 50 && sol[I][J] <= plafond[i][j] - 50 && sol[i][j] <= plafond[I][J]-50)
					{
						hauteuractuelle = H-temps[I][J]*10;
						hauteurdemandee = plafond[i][j]-50;
						if(hauteuractuelle < hauteurdemandee) moment = temps[I][J];
						else moment = (H+50-plafond[i][j])/10.0;
						hauteurfinale = H - moment*10;
						if(moment == 0) moment = 0;
						else if(hauteurfinale >= 20+sol[I][J]) moment += 1;
						else moment += 10;
						if(moment < temps[i][j]) temps[i][j] = moment;
					}
				}
				if(j > 0)
				{
					I = i;
					J = j-1;
					if(temps[I][J] < 1000000000 && sol[i][j] <= plafond[i][j] - 50 && sol[I][J] <= plafond[i][j] - 50 && sol[i][j] <= plafond[I][J]-50)
					{
						hauteuractuelle = H-temps[I][J]*10;
						hauteurdemandee = plafond[i][j]-50;
						if(hauteuractuelle < hauteurdemandee) moment = temps[I][J];
						else moment = (H+50-plafond[i][j])/10.0;
						hauteurfinale = H - moment*10;
						if(moment == 0) moment = 0;
						else if(hauteurfinale >= 20+sol[I][J]) moment += 1;
						else moment += 10;
						if(moment < temps[i][j]) temps[i][j] = moment;
					}
				}
				if(j < M-1)
				{
					I = i;
					J = j+1;
					if(temps[I][J] < 1000000000 && sol[i][j] <= plafond[i][j] - 50 && sol[I][J] <= plafond[i][j] - 50 && sol[i][j] <= plafond[I][J]-50)
					{
						hauteuractuelle = H-temps[I][J]*10;
						hauteurdemandee = plafond[i][j]-50;
						if(hauteuractuelle < hauteurdemandee) moment = temps[I][J];
						else moment = (H+50-plafond[i][j])/10.0;
						hauteurfinale = H - moment*10;
						if(moment == 0) moment = 0;
						else if(hauteurfinale >= 20+sol[I][J]) moment += 1;
						else moment += 10;
						if(moment < temps[i][j]) temps[i][j] = moment;
					}
				}
			}
		}

		}
		
		printf("Case #%d: %.6lf\n", test, temps[N-1][M-1]);
	}
	return 0;
}
