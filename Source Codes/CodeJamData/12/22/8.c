#include <stdio.h>
#include <conio.h>

int ** mapFloor;
int ** mapCeil;
double ** costs;
int H, N, M;

typedef struct
{
	int x;
	int y;
	double cost;
	int height;
} Cell;

void resetCosts();
void searchExit(Cell* list, int n);
int checkCell(Cell from, Cell to);
int addBest(Cell c);
int doCellStuff(Cell from, Cell to, Cell*, int);

int main()
{
	FILE *in = fopen("B-large.in", "r");
	FILE *out = fopen("B-large.out", "w+");
	
	int T;
	
	fscanf(in, "%d\n", &T);
	
	int t;
	int i, j;
	
	
	
	mapCeil = (int**)malloc(100*sizeof(int*));
	mapFloor = (int**)malloc(100*sizeof(int*));
	costs = (double**)malloc(100*sizeof(double*));
	
	for (i=0; i<100; ++i)
	{
		mapCeil[i] = (int*)malloc(100*sizeof(int));
		mapFloor[i] = (int*)malloc(100*sizeof(int));
		costs[i] = (double*)malloc(100*sizeof(double));
	}
	
	for (t=0; t<T; ++t)
	{
		fscanf(in, "%d", &H);
		fscanf(in, "%d", &N);
		fscanf(in, "%d", &M);
		
		for (i=0; i<N; ++i)
		{
			for (j=0; j<M; ++j)
			{
				fscanf(in, "%d", &mapCeil[i][j]);
				//printf("%d ", mapCeil[i][j]);
			}
			//printf("\n");
		}
		
		for (i=0; i<N; ++i)
		{
			for (j=0; j<M; ++j)
			{
				fscanf(in, "%d", &mapFloor[i][j]);
				//printf("%d ", mapFloor[i][j]);
			}
			//printf("\n");
		}
		
		
		Cell *startCell = (Cell*)malloc(1*sizeof(Cell));
		startCell[0].x = 0;
		startCell[0].y = 0;
		startCell[0].cost = 0.0;
		startCell[0].height = H;
		
		resetCosts();
		searchExit(startCell, 1);
		
		
		fprintf(out, "Case #%d: %lf\n", (t+1), costs[N-1][M-1]);
		//printf("Case #%d: %lf\n", (t+1), costs[N-1][M-1]);
	}
	
	fclose(in);
	fclose(out);
	
	//getch();
	return 0;
}

void resetCosts()
{
	int i, j;
	for (i=0; i<100; ++i)
	{
		for (j=0; j<100; ++j)
		{
			costs[i][j] = -1;
		}
	}
}

void searchExit(Cell* list, int n)
{
	if (n==0) return;
	
	int i;
	int newN=0;
	Cell nc;
	Cell* newList = (Cell*)malloc(100*100*sizeof(Cell*));
	
	for (i=0; i<n; ++i)
	{
		//north
		if (list[i].x > 0)
		{
			nc.x = list[i].x-1;
			nc.y = list[i].y;
			nc.cost = list[i].cost;
			nc.height = list[i].height;
			
			newN += doCellStuff(list[i], nc, newList, newN);
		}
		
		//west
		if (list[i].y > 0)
		{
			nc.x = list[i].x;
			nc.y = list[i].y-1;
			nc.cost = list[i].cost;
			nc.height = list[i].height;
			
			newN += doCellStuff(list[i], nc, newList, newN);
		}
		
		//south
		if (list[i].x < N-1)
		{
			nc.x = list[i].x+1;
			nc.y = list[i].y;
			nc.cost = list[i].cost;
			nc.height = list[i].height;
			
			newN += doCellStuff(list[i], nc, newList, newN);
		}
		
		//east
		if (list[i].y < M-1)
		{
			nc.x = list[i].x;
			nc.y = list[i].y+1;
			nc.cost = list[i].cost;
			nc.height = list[i].height;
			
			newN += doCellStuff(list[i], nc, newList, newN);
		}
	}
	
	free(list);
	
	searchExit(newList, newN);
}

//-7 success, -13 fail
int checkCell(Cell from, Cell to)
{
	if ( mapCeil[from.x][from.y] - mapFloor[to.x][to.y] < 50 ) return -13;
	if ( mapCeil[to.x][to.y] - mapFloor[from.x][from.y] < 50 ) return -13;
	if ( mapCeil[to.x][to.y] - mapFloor[to.x][to.y] < 50 ) return -13;
	
	int dist = mapCeil[to.x][to.y] - from.height;
	if ( dist < 50 )
	{
		return (50-dist);
	}
	
	return -7; //success
}

int addBest(Cell c)
{
	if ((costs[c.x][c.y] == -1) || (c.cost < costs[c.x][c.y]))
	{
		costs[c.x][c.y] = c.cost;
		return 1;
	}
	
	return 0;
}

int doCellStuff(Cell from, Cell to, Cell *newList, int n)
{
	int check = checkCell(from, to);
	
	//printf("Check: %d\n", check);
	
	if (check == -7)
	{
		if (to.cost > 0.0)
		{
			//add move cost
			if (to.height - mapFloor[from.x][from.y] >= 20) //1sec
			{
				to.cost += 1.0;
				to.height -= 10.0;
			}
			else
			{
				to.cost += 10.0;
				to.height -= 100.0;
			}
		}
		
		if (addBest(to))
		{
			newList[n] = to;
			return 1;
		}
	}
	else if (check != -13)
	{
		double waitCost = ((double)check)/10.0;
		
		to.cost += waitCost;
		to.height -= check;
		
		//add move cost
		if (to.height - mapFloor[from.x][from.y] >= 20) //1sec
		{
			to.cost += 1.0;
			to.height -= 10.0;
		}
		else
		{
			to.cost += 10.0;
			to.height -= 100.0;
		}
		
		if (addBest(to))
		{
			newList[n] = to;
			return 1;
		}
	}
	
	return 0;
}
