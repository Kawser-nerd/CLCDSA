#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int bestboard[100][100];
int bestscore[2];


void printboard(int N, int board[100][100]);
//void check(int N);

void solveLines(int N,int lines[2][100]);
void solveDiagnals(int N,int diag[2][199], int b[100][100], int isOdd, int score, int x, int y, int maxPossible);

int main()
{
	int T, N, M;
	int diag[2][199];
	int line[2][100];
	int initLine[100];
	int board[100][100];

	scanf("%d\n", &T);

	for(int i=0; i<T; i++)
	{
		scanf("%d %d\n",&N, &M);
		//printf("\n\nN=%d M=%d\n", N,M);
		int score[2] = {0, 0};

		for(int k = 0; k<2; k++)
			for(int j = 0; j < N; j++)
			{
					line[k][j] = -1;
			}
		for(int k = 0; k<2; k++)
			for(int j = 0; j < 2*N-1; j++)
			{
					diag[k][j] = 0;
			}

		for(int k = 0; k<N; k++)
			for(int j = 0; j < N; j++)
			{
				board[k][j]=0;
			}


		for(int j = 0; j < M; j++)
		{
			int x,y;
			char c;
			scanf("%c %d %d\n",&c, &x, &y);
			x--;y--;
			if(c!='x')
			{
				diag[0][x+y] = 1;
				diag[1][x-y+N] = 1;
				board[x][y] = 1;
				score[(x+y)%2]++;
			}
			if(c!='+')
			{
				line[0][x] = y;
				line[1][y] = x;
			}
			

		}
		for(int j=0; j<N; j++)
			initLine[j]=line[0][j];

		//printf("\n\nN=%d M=%d\n", N,M);
		//printboard(N, board);

		bestscore[0]=0;
		bestscore[1]=0;
		solveDiagnals(N,diag, board, 0, score[0], 0, 0, (N==1)?1:N-1);
		solveDiagnals(N,diag, board, 1, score[1], 0, 1, N-1);
		solveLines(N,line);


		//printboard(N, board);
		//printf("bestscore=%d\n", bestscore);
		//printboard(N, bestboard);

		int o[10000][2],n=0;
		char c[10000];
		for(int k = 0; k < N; k++)
			for(int j = 0; j < N; j++)
				if(board[k][j]!=bestboard[k][j] || (line[0][k]==j && initLine[k]==-1))
				{
					o[n][0] = k;
					o[n][1] = j;
					c[n] = (bestboard[k][j]==0)?'x':((line[0][k]==j)?'o':'+');
					n++;
					//printf("%d --> %d %d %d\n", n, bestboard[k][j], k, j);
				}
		printf("Case #%d: %d %d\n",i+1,bestscore[0]+bestscore[1]+N, n);
		for (int j = 0; j < n; j++)
		{
			printf("%c %d %d\n", c[j],o[j][0]+1, o[j][1]+1);
		}
	}

}

void solveLines(int N,int lines[2][100])
{
	int i=0,j=0;
	for(int i=0; i<N; i++)
		if(lines[0][i]==-1)
			while(j<N)
			{
				if(lines[1][j]==-1)
				{
					lines[0][i]=j;
					lines[1][j]=i;
					j++;
					break;
				}
				j++;
			}

}
void solveDiagnals(int N,int diag[2][199], int b[100][100], int isOdd, int score, int x, int y, int maxPossible)
{

	
	if(bestscore[isOdd] >= maxPossible)
		return;
	//printf("isOdd=%d,sc= %d bs=%d x=%d y=%d\n", isOdd, score, bestscore[isOdd], x, y);
	//printboard(N,b);
	if(y >= N)
	{
		//printf("N=%d-----x=%d->\n", N, x);
		int z = N-1-x;
		if(z==x)
			x=N;
		else
			if(z<x)
			{
				z++;
				if(x==z)
					x=N;
				else
					x=z;
			}
			else
				x=z;
		//printf("%d\n", x);
		y=(x+isOdd)%2;
	}
	if(x == N || score == maxPossible)
	{
		//updateMax(board);
		//printf("sc=%d\n", score);
		if(score>bestscore[isOdd])
		{
			for(int i = 0; i<N; i++)
				for(int j = 0 ; j < N; j++)
				{
					if((isOdd+i+j)%2==0)
						bestboard[i][j] = b[i][j];
				}
			bestscore[isOdd] = score;
			
		}
		return;
	}

	if(b[x][y]!=0)
		solveDiagnals(N,diag,b,isOdd,score,x,y+2,maxPossible);
	else
	{

		int diag1 = diag[0][x+y] + diag[1][x-y+N];

		if(diag1 == 0)
		{
			b[x][y] = 1;
			diag[0][x+y] = 1;
			diag[1][x-y+N] = 1;
			solveDiagnals(N,diag,b,isOdd,score+1,x,y+2,maxPossible);
			b[x][y] = 0;
			diag[0][x+y] = 0;
			diag[1][x-y+N] = 0;
		}
		
		solveDiagnals(N,diag,b,isOdd,score,x,y+2,maxPossible);
	}
}
void printboard(int N, int board[100][100])
{
	for(int k = 0; k < N; k++,printf("\n"))
			for(int j = 0; j < N; j++)
				printf("%d", board[k][j]);
	printf("\n");
}