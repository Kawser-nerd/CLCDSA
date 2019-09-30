#include<stdio.h>

int i,j,k,tc;
int ci,cj;

int main()
{
	int T;

	scanf("%d\n", &T);

	for (tc=1; tc<=T; tc++)
	{
		int H, W;	
		int T[100][100];
		int B[100][100]={{0}};
		char nextsol='a';
		
		scanf("%d %d\n", &H, &W);

	 	for (i=0; i<H; i++)
			for (j=0; j<W; j++)
				scanf("%d", &T[i][j]);


//NWES
		for (ci=0;ci<H;ci++)
		{
			for (cj=0;cj<W;cj++)
			{
				int i=ci;
				int j=cj;

				int N, Wd, E, S;
				int C;

				if (B[i][j] !=0) continue;
			newij:
				C = T[i][j];
				B[i][j] = nextsol;

				N = (i>0) ? T[i-1][j] : 10000;
				Wd = (j>0) ? T[i][j-1] : 10000;
				E = (j<(W-1)) ? T[i][j+1] : 10000;
				S = (i<(H-1)) ? T[i+1][j] : 10000;
				
				if (N>=C && Wd>=C && E>=C && S>=C)
					goto done;

				if (N<=Wd && N<=E && N<=S)
					goto north;

				if (Wd<=N && Wd<=E && Wd<=S)
					goto west;

				if (E<=N && E<=Wd && E<=S)
					goto east;

				if (S<=N && S<=E && S<=Wd)
					goto south;
			north:
				if (N<C)
				{
					int NB = B[i-1][j];
					if (NB==0)
					{
						i--;
						goto newij;
					}
					else {
						for (i=0; i<H; i++)
							for (j=0; j<W; j++)
								if (B[i][j]==nextsol)
									B[i][j]=NB;
						continue;
					}
				}
			west:
				if (Wd<C)
				{
					int WB = B[i][j-1];
					if (WB==0)
					{
						j--;
						goto newij;
					}
					else {
						for (i=0; i<H; i++)
							for (j=0; j<W; j++)
								if (B[i][j]==nextsol)
									B[i][j]=WB;
						continue;
					}
				}
			east:
				if (E<C)
				{
					int EB = B[i][j+1];
					if (EB==0)
					{
						j++;
						goto newij;
					}
					else {
						for (i=0; i<H; i++)
							for (j=0; j<W; j++)
								if (B[i][j]==nextsol)
									B[i][j]=EB;
						continue;
					}
				}
			south:
				if (S<C)
				{
					int SB = B[i+1][j];
					if (SB==0)
					{
						i++;
						goto newij;
					}
					else {
						for (i=0; i<H; i++)
							for (j=0; j<W; j++)
								if (B[i][j]==nextsol)
									B[i][j]=SB;
						continue;
					}
				}
			done:
				nextsol++;
			}

		}

		printf("Case #%d:\n", tc);
		for (i=0;i<H;i++)
		{
			for (j=0;j<(W-1);j++)
				printf("%c ",B[i][j]);
			printf("%c\n", B[i][W-1]);
		}
	}
}
				
