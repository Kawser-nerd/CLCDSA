/* File name: main.c               */
/* Author: Sharath Holla K.        */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INPUTFILE "input.in"
#define CMD_LINE_LENGTH 300

FILE *output_file;
FILE *input_file;
char temp_str[CMD_LINE_LENGTH];
char curr_cmd[CMD_LINE_LENGTH];

typedef struct
{
	long d;
	int n;
	long w;
	long e;
	long s;
	long delta_d;
	long delta_p;
	long delta_s;
}PLAYER;
void calc_routine(int index_i)
{
    int num_player, i, j;
	PLAYER **playerList;
	long minW = 1000000, maxE = -1000000;
	long *S;

    int diff;
	int totAttack = 0;
	int suc = 0;
	int * tmp;


    fscanf(input_file, "%d\n", &num_player);

    playerList = (PLAYER **)malloc(num_player * sizeof(PLAYER *));


	for(i = 0; i < num_player; i++)
	{
		PLAYER *curPlayer = (PLAYER *)malloc(sizeof(PLAYER));
		long finE, finW;
		fscanf(input_file, "%ld %d %ld %ld %ld %ld %ld %ld\n", &(curPlayer->d), &(curPlayer->n), &(curPlayer->w), &(curPlayer->e), &(curPlayer->s), &(curPlayer->delta_d), &(curPlayer->delta_p), &(curPlayer->delta_s));
		playerList[i] = curPlayer;
		finE = curPlayer->e + ((curPlayer->n - 1) * curPlayer->delta_p);
		finW = curPlayer->w + ((curPlayer->n - 1) * curPlayer->delta_p);
		if(curPlayer->e > maxE)
			maxE = curPlayer->e;
		if(curPlayer->w < minW)
			minW = curPlayer->w;
		if(finE > maxE)
			maxE = finE;
		if(finW < minW)
			minW = finW;
		totAttack += curPlayer->n;
	}
	diff = 2*(maxE - minW) + 1;
	S = (long *)malloc(diff * sizeof(long));
	tmp = (int *)malloc(num_player * sizeof(int));
	memset(S, 0, diff*sizeof(long));

	while(totAttack)
	{
		int count = 0;
		int min = 676060;
		for(i = 0; i < num_player; i++)
		{
			PLAYER *curPlayer = playerList[i];
			if(curPlayer->n <= 0) continue;
			if(curPlayer->d < min)
			{
				min = curPlayer->d;
				count = 0;
				tmp[count] = i;
			}
			else if(curPlayer->d == min)
			{
				count++;
				tmp[count] = i;
			}
		}
		for(i = 0; i <= count; i++)
		{
			PLAYER *curPlayer = playerList[tmp[i]];
			long curS = curPlayer->s;
			for(j = 2* curPlayer->w; j <= 2* curPlayer->e; j++)
			{
				if(curS > S[j- 2* minW])
				{
					suc++;
					break;
				}
			}
			totAttack--;
		}
		for(i = 0; i <= count; i++)
		{
			PLAYER *curPlayer = playerList[tmp[i]];
			long curS = curPlayer->s;
			for(j = 2* curPlayer->w; j <= 2* curPlayer->e; j++)
			{
				if(curS > S[j- 2* minW])
				{
					S[j- 2* minW] = curS;
				}
			}
			curPlayer->n--;
			curPlayer->d += curPlayer->delta_d;
			curPlayer->e += curPlayer->delta_p;
			curPlayer->w += curPlayer->delta_p;
			curPlayer->s += curPlayer->delta_s;
		}
	}

    
	
	
	fprintf(output_file, "Case #%d: %d\n", index_i+1, suc);
	for(i = 0; i < num_player; i++)
	{
		PLAYER *curPlayer = playerList[i];
		free(curPlayer);
	}
    free(playerList);
	free(S);
	free(tmp);
    return;
}

void main()
{
    int test_cases = 0;
    int index_i;
    input_file = fopen(INPUTFILE, "rt");
    output_file = fopen("output.txt", "wt");

    //fscanf(input_file, "%d", &test_cases);
    {
        fgets((char *)curr_cmd, CMD_LINE_LENGTH, input_file);
        sscanf((char *)curr_cmd, "%s", temp_str);
        test_cases = atoi(temp_str);
    }

    for (index_i = 0; index_i < test_cases; index_i++)
    {
        calc_routine(index_i);
    }

    fclose(input_file);
    fclose(output_file);
}