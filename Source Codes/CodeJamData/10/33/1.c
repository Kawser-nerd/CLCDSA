#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int board[512][512];
int maxaltr[512][512];
int maxaltd[512][512];
int maxsq[512][512];


int dascii[128];

int sizes[513];
int potsizes[513];

int min(int a, int b)
{
  return a < b ? a  : b;
}

void pmaxsq(int M, int N)
{
  for(int i = 0; i < M; i++)
    {
      for(int j = 0; j < N; j++)
	{
	  printf("%d",maxsq[i][j]);
	}
      printf("\n");
    }
}

int main()
{
  dascii['0'] = 0;
  dascii['1'] = 1;
  dascii['2'] = 2;
  dascii['3'] = 3;
  dascii['4'] = 4;
  dascii['5'] = 5;
  dascii['6'] = 6;
  dascii['7'] = 7;
  dascii['8'] = 8;
  dascii['9'] = 9;
  dascii['A'] = 10;
  dascii['B'] = 11;
  dascii['C'] = 12;
  dascii['D'] = 13;
  dascii['E'] = 14;
  dascii['F'] = 15;

  int T;
  scanf("%d",&T);

  for(int times = 1; times <= T; times++)
    {
      int M,N;
      scanf("%d %d",&M,&N);

      for(int i = 0; i < M; i++)
	{
	  char buf[129];
	  scanf("%s",buf);
	  for(int j = 0; j < N; j+=4)
	    {
	      int a = dascii[buf[j/4]];
	      board[i][j] = !!(a&8);
	      board[i][j+1] = !!(a&4);
	      board[i][j+2] = !!(a&2);
	      board[i][j+3] = !!(a&1);
	    }
	}

      for(int i = 0; i < M; i++)
	{
	  maxaltr[i][N-1] = 1;
	  for(int j = N-2; j >= 0; j--)
	    {
	      if(board[i][j] != board[i][j+1])
		maxaltr[i][j] = 1+maxaltr[i][j+1];
	      else
		maxaltr[i][j] = 1;
	    }
	}

      for(int i = 0; i < N; i++)
	{
	  maxaltd[M-1][i] = 1;
	  for(int j = M-2; j >= 0; j--)
	    {
	      if(board[j][i] != board[j+1][i])
		maxaltd[j][i] = 1+maxaltd[j+1][i];
	      else
		maxaltd[j][i] = 1;
	    }
	}

      int tmax = 1;
      for(int i = 0; i < 513; i++)
	potsizes[i] = 0;

      for(int i = M-1; i >= 0; i--)
	{
	  for(int j = N-1; j>=0; j--)
	    {
	      if(i+1==M||j+1==N)
		{
		  maxsq[i][j] = 1;
		  potsizes[1]++;
		}
	      else if(board[i][j] ==board[i+1][j+1])
		{
		  int a = maxaltr[i][j];
		  int b = maxaltd[i][j];
		  int c = 1+maxsq[i+1][j+1];
		  maxsq[i][j] = min(a,min(b,c));
		  if(maxsq[i][j] > tmax)
		    tmax = maxsq[i][j];

		  potsizes[maxsq[i][j]]++;
		}
	      else
		{
		  maxsq[i][j] = 1;
		  potsizes[1]++;
		}
	    }
	}

      for(int i = 0; i < 513; i++)
	sizes[i] = 0;

      int nsizes = 0;
      for(int size = tmax; size> 0; size--)
	{
	  if(potsizes[size]==0)
	    continue;

	  int canmake = 0;

	  for(int i = 0; i < M; i++)
	    {
	      for(int j = 0; j < N; j++)
		{
		  if(maxsq[i][j] ==size)
		    {
		      canmake = 1;
		      sizes[size]++;
		      for(int k = -size+1; k < size; k++)
			{
			  if(i+k<0)
			    continue;
			  for(int l = -size+1; l < size; l++)
			    {
			      if(j+l<0)
				continue;

			      potsizes[maxsq[i+k][j+l]]--;
			      
			      if(k >= 0 && l >= 0)
				maxsq[i+k][j+l] = 0;
			      else
				{
				  int d = -min(k,l);
				  if(maxsq[i+k][j+l] > d)
				    maxsq[i+k][j+l] = d;
				}

			      potsizes[maxsq[i+k][j+l]]++;
			    }
			}
		    }
		}
	    }
	  
	  if(canmake)
	    nsizes++;
	}

      printf("Case #%d: %d\n",times,nsizes);
      for(int size = 512; size>0; size--)
	{
	  if(sizes[size])
	    printf("%d %d\n",size,sizes[size]);
	}
    }
  return 0;
}
      
		
