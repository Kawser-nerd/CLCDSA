/*
* =====================================================================================
*
*       Filename:  main.c
*
*    Description:  
*
*        Version:  1.0
*        Created:  07/18/08 02:38:50
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  Leon Bai 
*
* =====================================================================================
*/


#include <stdio.h>
#include <stdlib.h>

#define INPUT  "A-small.in"
#define OUTPUT "A-small.out"

int rearrage_array(int* array, int array_nr)
{
	int i, j;

	for (i= 0;i<(array_nr-1);i++)
	{
		for (j=(i+1);j<array_nr;j++)
		{
			if(array[j] < array[i])
			{
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	return 0;
}

int main()
{
	FILE*  f_in = fopen(INPUT, "rb");
	FILE*  f_out = fopen(OUTPUT, "wt");
	int    question_nr = 0;
	int    case_seq = 0;
	
	if( (f_in == NULL) || (f_out == NULL))
		return -1;
	
	fscanf(f_in, "%d", &question_nr);

	while(question_nr)
	{
		int  i = 0;
		int* vector_array_x = NULL;
		int* vector_array_y = NULL;
		int  vector_nr = 0;
		int  result = 0;

		fscanf(f_in, "%d", &vector_nr);
		vector_array_x = malloc(sizeof(int)*vector_nr);
		memset(vector_array_x, 0, sizeof(int)*vector_nr);
		vector_array_y = malloc(sizeof(int)*vector_nr);
		memset(vector_array_y, 0, sizeof(int)*vector_nr);

		for (i=0;i<vector_nr;i++)
			fscanf(f_in, "%d", &vector_array_x[i]);
		for (i=0;i<vector_nr;i++)
			fscanf(f_in, "%d", &vector_array_y[i]);

		rearrage_array(vector_array_x, vector_nr);
		rearrage_array(vector_array_y, vector_nr);
		for(i=0;i<vector_nr;i++)
			result += vector_array_x[i] * vector_array_y[vector_nr-1-i];

		case_seq += 1;
		fprintf(f_out, "Case #%d: %d\n", case_seq, result);
		question_nr -= 1;

		free(vector_array_x);
		free(vector_array_y);
	}

	fclose(f_in);
	fclose(f_out);
	return 0;
}