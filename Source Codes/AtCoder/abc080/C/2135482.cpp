#include "stdio.h"
 
int tryit(int my[10], int* jikanntai, int F[100][10], int P[100][11], int* max, int mise_max)
{
	int mise_ind = 0;
	int dou_num = 0;
	int i, j;
	int temp_p = 0;
 
	if(*jikanntai>=9)
	{
		for(i=0; i<mise_max; i++)
		{
			dou_num = 0;
			for(j=0; j<10; j++)
			{
				if(my[j] == F[i][j] &&  F[i][j] == 1)
				{
					dou_num += 1;
				}
			}
			temp_p += P[i][dou_num];
		}
 
		if((temp_p > *max)&&(my[0]!=0||my[1]!=0||my[2]!=0||my[3]!=0||my[4]!=0||my[5]!=0||my[6]!=0||my[7]!=0||my[8]!=0||my[9]!=0))
		{
			*max = temp_p;
		}
 
		return 0;
	}
 
	*jikanntai = *jikanntai + 1;
	my[*jikanntai] = 0;
	tryit(my, jikanntai, F, P, max, mise_max);
 
	my[*jikanntai] = 1;
	tryit(my, jikanntai, F, P, max, mise_max);
 
	*jikanntai = *jikanntai - 1;
	return 0;
}
 
int main(void){
	int i, j;
	int my[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int max = -2147483647;
	int jikanntai = 0;
 
	int N;
	int F[100][10];
	int P[100][11];
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<10;j++)
		{
			scanf("%d", &F[i][j]);
		}
	}
 
	for(i=0;i<N;i++)
	{
		for(j=0;j<11;j++)
		{
			scanf("%d", &P[i][j]);
		}
	}
 
	jikanntai = -1;
	tryit(my, &jikanntai, F, P, &max, N);
 
	printf("%d\n", max);
	return 0;
}