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

#define INPUT  "B-small.in"
#define OUTPUT "B-small.out"

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
		int width = 0;
		int height = 0;
		int area = 0;
		int result = -1;
		int x1=0, y1=0, x2=0, y2=0, x3=0, y3=0;
		fscanf(f_in, "%d %d %d", &width, &height, &area);

		if (area > width*height)
		{
			result = -1;
		}
		else
		{
			int delta_x1=0, delta_x2=0, delta_y1=0, delta_y2=0;
			for (delta_x1=0;delta_x1<=width;delta_x1++)
			{
				for (delta_y2=0;delta_y2<=height;delta_y2++)
				{
					for (delta_x2=1;delta_x2<=(width-delta_x1);delta_x2++)
					{
						for (delta_y1=1;delta_y1<=(height-delta_y2);delta_y1++)
						{
							if (area == ((delta_x1+delta_x2)*(delta_y1+delta_y2)-delta_x1*delta_y2*2-delta_x1*delta_y1-delta_x2*delta_y2))
							{
								x1 = 0;
								y1 = 0;
								x2 = x1 + delta_x1;
								y2 = y1 + delta_y1;
								x3 = x2 + delta_x2;
								y3 = y2 + delta_y2;
								result = 0;
								goto END;
							}
						}
					}
				}
			}

			for (delta_x1=0;delta_x1<=width;delta_x1++)
			{
				for (delta_y2=0;delta_y2<=height;delta_y2++)
				{
					for (delta_x2=1;delta_x2<=(width-delta_x1);delta_x2++)
					{
						for (delta_y1=delta_y2;delta_y1<=height;delta_y1++)
						{
							if (area == (2*(delta_x1+delta_x2)*delta_y1-(delta_x1+delta_x2)*(delta_y1-delta_y2)-delta_x1*delta_y1-delta_x2*delta_y2))
							{
								x1 = 0;
								y1 = 0;
								x2 = x1 + delta_x1;
								y2 = y1 + delta_y1;
								x3 = x2 + delta_x2;
								y3 = y2 - delta_y2;
								result = 0;
								goto END;
							}
						}
					}
				}
			}
		}

END:
		case_seq += 1;
		if (result == -1)
			fprintf(f_out, "Case #%d: IMPOSSIBLE\n", case_seq);
		else
			fprintf(f_out, "Case #%d: %d %d %d %d %d %d\n", case_seq, x1, y1, x2, y2, x3, y3);
		question_nr -= 1;
	}

	fclose(f_in);
	fclose(f_out);
	return 0;
}