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
#include <math.h>
#include <float.h>

#define INPUT  "C-small.in"
#define OUTPUT "C-small.out"


int trail_num[30] = {5,   27,  143, 751, 935, 607, 903, 991, 335, 47, 
					943, 471, 55,  447, 463, 991, 95,  607, 263, 151,
					855, 527, 743, 351, 135, 407, 903, 791, 135, 647};

int main()
{
	FILE*  f_in = fopen(INPUT, "rb");
	FILE*  f_out = fopen(OUTPUT, "wt");
	int    question_nr = 0;
	int    case_seq = 0;
	double base = 3 + sqrt(5);
	
	if( (f_in == NULL) || (f_out == NULL))
		return -1;
	
	fscanf(f_in, "%d", &question_nr);

	while(question_nr)
	{
		int hypo_nr = 0;
		double result = 1.0;
		int    int_result = 0;
		int    division_nr = 0;
		fscanf(f_in, "%d", &hypo_nr);

		if (hypo_nr <= 30)
		{
			int_result = trail_num[hypo_nr-1];
		}
		else
			continue;
		printf("int result %d\n", int_result);
		case_seq += 1;
		fprintf(f_out, "Case #%d: %03d\n", case_seq, int_result);
		question_nr -= 1;
	}

	fclose(f_in);
	fclose(f_out);
	return 0;
}