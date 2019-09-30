#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

/* common define */
/* TODO create common.h */
#define U1 unsigned char
#define S1 char
#define	S4 int
#define DU double
#define VD void

#define TRUE              (1)
#define FALSE             (0)

/* define */
typedef struct {
	S4 s4_startWi;
	S4 s4_startHi;
	S4 s4_endWi;
	S4 s4_endHi;
}ST_AREA;

#define MAX_HEIGHT       (100)
#define MAX_WIDTH        (100)

#define WHITE            (1)
#define BLACK            (0)

VD vd_d_setCumulativeSum(S4 s4_a_height, S4 s4_a_width, S4 s4_ap_concentration[][MAX_WIDTH], S4 s4_ap_cumlativeSum[][MAX_WIDTH])
{
	S4 s4_t_hi;
	S4 s4_t_wi;

	for (s4_t_hi = (S4)0; s4_t_hi < s4_a_height; s4_t_hi++)
	{
		for (s4_t_wi = (S4)0; s4_t_wi < s4_a_width; s4_t_wi++)
		{
			s4_ap_cumlativeSum[s4_t_hi][s4_t_wi] = s4_ap_concentration[s4_t_hi][s4_t_wi];

			if (s4_t_hi > (S4)0)
			{
				s4_ap_cumlativeSum[s4_t_hi][s4_t_wi] += s4_ap_cumlativeSum[s4_t_hi - 1][s4_t_wi];
			}
			if (s4_t_wi > (S4)0)
			{
				s4_ap_cumlativeSum[s4_t_hi][s4_t_wi] += s4_ap_cumlativeSum[s4_t_hi][s4_t_wi - 1];
			}
			if ((s4_t_wi > (S4)0) &&
				(s4_t_hi > (S4)0))
			{
				s4_ap_cumlativeSum[s4_t_hi][s4_t_wi] -= s4_ap_cumlativeSum[s4_t_hi - 1][s4_t_wi - 1];
			}
		}
	}
}

S4 s4_d_calcPartCumulativeSum(ST_AREA st_a_area, S4 s4_ap_cumlativeSum[][MAX_WIDTH])
{
	S4 s4_t_return;

	s4_t_return = s4_ap_cumlativeSum[st_a_area.s4_endHi][st_a_area.s4_endWi];
	if (st_a_area.s4_startWi > (S4)0)
	{
		s4_t_return -= s4_ap_cumlativeSum[st_a_area.s4_endHi][st_a_area.s4_startWi - 1];
	}
	if (st_a_area.s4_startHi > (S4)0)
	{
		s4_t_return -= s4_ap_cumlativeSum[st_a_area.s4_startHi - 1][st_a_area.s4_endWi];
	}
	if ((st_a_area.s4_startWi > (S4)0) &&
		(st_a_area.s4_startHi > (S4)0))
	{
		s4_t_return += s4_ap_cumlativeSum[st_a_area.s4_startHi - 1][st_a_area.s4_startWi - 1];
	}
	return((S4)s4_t_return);
}

S4 s4_d_calcMaxArea(S4 s4_a_height, S4 s4_a_width, S4 s4_ap_cumlativeSum[][MAX_WIDTH])
{
	S4 s4_t_height;
	S4 s4_t_width;
	S4 s4_t_top;
	S4 s4_t_left;
	S4 s4_t_bottom;
	S4 s4_t_right;
	ST_AREA st_t_area;
	S4 s4_t_concentration;
	S4 s4_t_maxSize;
	S4 s4_t_size;

	s4_t_maxSize = (S4)0;

	/* Calc all pattern of positions. */
	for (s4_t_top = (S4)0; s4_t_top < s4_a_height; s4_t_top++)
	{
		for (s4_t_left = (S4)0; s4_t_left < s4_a_width; s4_t_left++)
		{
			st_t_area.s4_startHi = s4_t_top;
			st_t_area.s4_startWi = s4_t_left;

			/* Calc all pattern of size */
			for (s4_t_bottom = s4_t_top; s4_t_bottom < s4_a_height; s4_t_bottom++)
			{
				for (s4_t_right = (S4)s4_t_left; s4_t_right < s4_a_width; s4_t_right++)
				{
					st_t_area.s4_endHi = s4_t_bottom;
					st_t_area.s4_endWi = s4_t_right;

					s4_t_concentration = s4_d_calcPartCumulativeSum(st_t_area, s4_ap_cumlativeSum);

					/* White and black is same. */
					if (s4_t_concentration == (S4)0)
					{
						/* Calc the area. */
						s4_t_height = s4_t_bottom - s4_t_top + (S4)1;
						s4_t_width = s4_t_right - s4_t_left + (S4)1;

						s4_t_size = s4_t_height * s4_t_width;
						if (s4_t_size > s4_t_maxSize)
						{
							s4_t_maxSize = s4_t_size;
						}
					}
				}
			}
		}
	}
	return(s4_t_maxSize);
}

S4 main()
{
	S4 s4_t_height;
	S4 s4_t_width;
	S4 s4_t_hi;
	S4 s4_t_wi;
	S4 s4_t_color;
	S4 s4_t_concentration;
	S4 s4_tp_concentration[MAX_HEIGHT][MAX_WIDTH];
	S4 s4_tp_cumulativeSum[MAX_HEIGHT][MAX_WIDTH];
	S4 s4_t_isOdd;
	S4 s4_t_maxSize;

	/* Input */
	(VD)scanf("%d %d", &s4_t_height, &s4_t_width);

	s4_t_color = (S4)BLACK;	/* The first area is black */
	for (s4_t_hi = (S4)0; s4_t_hi < s4_t_height; s4_t_hi++)
	{
		/* If s4_t_hi is odd, the first area is black. */
		s4_t_isOdd = s4_t_hi % (S4)2;
		if (s4_t_isOdd == (S4)1)	/* s4_t_hi is not odd. */
		{
			s4_t_color = (S4)WHITE;
		}
		else
		{
			s4_t_color = (S4)BLACK;
		}

		for (s4_t_wi = (S4)0; s4_t_wi < s4_t_width; s4_t_wi++)
		{
			(VD)scanf("%d", &s4_t_concentration);
			
			/* This program has a concentration of white as minus number and black as plus number. */
			/* white */
			if (s4_t_color == (S4)WHITE)
			{
				s4_tp_concentration[s4_t_hi][s4_t_wi] = (-1) * s4_t_concentration;
			}
			/* black */
			else
			{
				s4_tp_concentration[s4_t_hi][s4_t_wi] = s4_t_concentration;
			}

			/* The color is different from before area. */
			s4_t_color++;
			s4_t_color = s4_t_color % (S4)2;
		}
	}
	
	/* Set cumulative sum. */
	vd_d_setCumulativeSum(s4_t_height, s4_t_width, s4_tp_concentration, s4_tp_cumulativeSum);

	/* Calc max area. */
	s4_t_maxSize = s4_d_calcMaxArea(s4_t_height, s4_t_width, s4_tp_cumulativeSum);

	/* ?? */
	printf("%d\n", s4_t_maxSize);

	return((S4)0);
} ./Main.c: In function ‘main’:
./Main.c:149:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  (VD)scanf("%d %d", &s4_t_height, &s4_t_width);
  ^
./Main.c:167:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    (VD)scanf("%d", &s4_t_concentration);
    ^