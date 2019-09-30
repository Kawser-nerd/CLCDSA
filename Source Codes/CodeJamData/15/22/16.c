#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int r,c,n;
int board[10000];

int brute_force(int pos,int left)
	{
	int score;
	int best=1000000;
	int i,p;

	if(left==0)
		{
		score=0;
		for(i=0;i<c;i++)
			{
			for(p=0;p<r;p++)
				{
				if(board[i+(p*c)])
					{
					if((board[i+1+(p*c)])&&(i<c-1))
						{
						score++;
						}
					if((board[i+((p+1)*c)])&&(p<r-1))
						{
						score++;
						}
					}
				}
			}
		return(score);
		}
	for(p=1;p+pos<=(r*c)-left;p++)
		{
		board[p+pos]=1;
		score=brute_force(pos+p,left-1);
		board[p+pos]=0;
		if(score<best)
			{
			best=score;
			}
		}
	return(best);
	}

int main(int argc,char *argv[])
	{
	int tests;
	int casenum;
	int score;
	int internal;

	fscanf(stdin,"%d\n",&tests);
	for(casenum=1;casenum<=tests;casenum++)
		{
		fscanf(stdin,"%d %d %d\n",&r,&c,&n);
		if((n==1)||(((r*c)+1)>(n*2)))
			{
			// Sparsely populated - easy enough to fit everyone in happily
			score=0;
			}
		else
			{
			score=brute_force(-1,n);
			}
		printf("Case #%d: %d\n",casenum,score);
		}
	}
