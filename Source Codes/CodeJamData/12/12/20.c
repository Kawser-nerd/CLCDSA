#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_N 10000

struct level {
	int onestar;
	int twostar;
	
	int onestar_prev;
	int onestar_next;
	int twostar_prev;
	int twostar_next;
	int demoted_next;
	int demoted_prev;
};

void do_test(int t)
{
	int n, i, j;
	static struct level l[MAX_N];
	int onestar_min = -1, twostar_min = -1, demoted_min = -1;
	int stars = 0, completed = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		int prev;
		scanf("%d %d", &l[i].onestar, &l[i].twostar);

		for (prev = -1, j = onestar_min; j != -1 && (l[j].onestar < l[i].onestar || (l[j].onestar == l[i].onestar && l[j].twostar > l[i].twostar)); prev = j, j = l[j].onestar_next)
			;
		l[i].onestar_next = j;
		l[i].onestar_prev = prev;
		if (prev == -1)
			onestar_min = i;
		else
			l[prev].onestar_next = i;
		if (j != -1)
			l[j].onestar_prev = i;

		for (prev = -1, j = twostar_min; j != -1 && l[j].twostar < l[i].twostar; prev = j, j = l[j].twostar_next)
			;
		l[i].twostar_next = j;
		l[i].twostar_prev = prev;
		if (prev == -1)
			twostar_min = i;
		else
			l[prev].twostar_next = i;
		if (j != -1)
			l[j].twostar_prev = i;

		l[i].demoted_next = -1;
		l[i].demoted_prev = -1;
	}

	/* greedy algorithm:
	 * always best to solve as many two-star levels as we can at each step,
 	 * otherwise solve a 1-star level.

	 * check if we have completed the game;
	 * grab next two-star level;
     *    if no two-star levels are in reach, grab next one-star level and move corresponding two-star to one-star
	 * repeat
	 */

	while (twostar_min != -1 || demoted_min != -1)
	{
		if (twostar_min != -1 && l[twostar_min].twostar <= stars)
		{
			int ldone = twostar_min;

			stars += 2;
			completed += 1;
			//printf("Completing level %d @two-stars, now have %d stars and %d levels.\n", ldone, stars, completed);

			/* remove from two-star list */
			twostar_min = l[ldone].twostar_next;
			if (twostar_min != -1)
				l[twostar_min].twostar_prev = -1;

			/* and one-star list */
			if (l[ldone].onestar_prev == -1)
				onestar_min = l[ldone].onestar_next;
			else
				l[l[ldone].onestar_prev].onestar_next = l[ldone].onestar_next;

			if (l[ldone].onestar_next != -1)
				l[l[ldone].onestar_next].onestar_prev = l[ldone].onestar_prev;
		}
		else if (demoted_min != -1 && l[demoted_min].twostar <= stars)
		{
			int ldone = demoted_min;

			stars += 1;
			completed += 1;
			//printf("Completing level %d @demoted, now have %d stars and %d levels.\n", ldone, stars, completed);

			/* remove from demoted two-star list */
			demoted_min = l[ldone].demoted_next;
			if (demoted_min != -1)
				l[demoted_min].demoted_prev = -1;
		}
		else if (onestar_min != -1 && l[onestar_min].onestar <= stars)
		{
			int ldone = onestar_min;
			int prev;

			/* Find affordable onestar with most expensive twostar */
			for (i = onestar_min; i != -1 && l[i].onestar <= stars; i = l[i].onestar_next)
				if (l[i].twostar > l[ldone].twostar)
					ldone = i;

			stars += 1;
			completed += 1;
			//printf("Completing level %d @one-star, now have %d stars and %d levels.\n", ldone, stars, completed);

			/* remove from onestar list */
			if (l[ldone].onestar_prev == -1)
				onestar_min = l[ldone].onestar_next;
			else
				l[l[ldone].onestar_prev].onestar_next = l[ldone].onestar_next;

			if (l[ldone].onestar_next != -1)
				l[l[ldone].onestar_next].onestar_prev = l[ldone].onestar_prev;

			/* and two-star list */
			if (l[ldone].twostar_prev == -1)
				twostar_min = l[ldone].twostar_next;
			else
				l[l[ldone].twostar_prev].twostar_next = l[ldone].twostar_next;

			if (l[ldone].twostar_next != -1)
				l[l[ldone].twostar_next].twostar_prev = l[ldone].twostar_prev;

			/* and add to demoted two-star list */
			for (prev = -1, j = demoted_min; j != -1 && l[j].twostar < l[ldone].twostar; prev = j, j = l[j].demoted_next)
				;
			l[ldone].demoted_next = j;
			l[ldone].demoted_prev = prev;
			if (prev == -1)
				demoted_min = ldone;
			else
				l[prev].demoted_next = ldone;
			if (j != -1)
				l[j].demoted_prev = ldone;
		}
		else
		{
			completed = -1;
			break;
		}
	}

	if (completed != -1)
		printf("Case #%d: %d\n", t + 1, completed);
	else
		printf("Case #%d: Too Bad\n", t + 1);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
