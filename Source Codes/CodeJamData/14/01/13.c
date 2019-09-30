/*
    By Yemeli Tasse Cyrille
    http://yemelitc.org
    Date: 12 April 2014
*/


#include<stdio.h>
#include "yemelitc_functions.c"


int main()
{
	int i, j;
	int cases, T;
	int count, ans;

    int first_answer;
    int second_answer;
    int first_array[4][4];
    int second_array[4][4];

	FILE *output = fopen("A-small-attempt0.out", "w");
	FILE *input = fopen("A-small-attempt0.in", "r");
	fscanf(input, "%d", &T);

	for(cases=1; cases<=T; cases++)
	{
		fscanf(input, "%d", &first_answer);
		first_answer--;

		for(i=0; i<4; i++)
		    for(j=0; j<4; j++)
		        fscanf(input, "%d", &first_array[i][j]);

		fscanf(input, "%d", &second_answer);
		second_answer--;

		for(i=0; i<4; i++)
		    for(j=0; j<4; j++)
		        fscanf(input, "%d", &second_array[i][j]);

        count=0;
		ans=0;
		for(i=0; i<4; i++)
		    for(j=0; j<4; j++)
		        if(first_array[first_answer][i] == second_array[second_answer][j])
		        {
		            count++;
		            ans = first_array[first_answer][i];
		        }
		
		if(count==1)
		{
		    fprintf(output, "Case #%d: %d\n", cases, ans);
		    printf("Case #%d: %d\n", cases, ans);
		}
		else if (count > 1)
		{
		    fprintf(output, "Case #%d: Bad magician!\n", cases);
		    printf("Case #%d: Bad magician!\n", cases);
		}
		else
		{
		    fprintf(output, "Case #%d: Volunteer cheated!\n", cases);
		    printf("Case #%d: Volunteer cheated!\n", cases);
		}
	}

	fclose(input);
	fclose(output);
}

