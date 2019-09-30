#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DEBUGF(s, ...) fprintf(stderr, "DEBUGF #%d: " s, t+1, ##__VA_ARGS__)

struct partition_set
{
	long long size;
	long long count;
};

#define N_PART 8

void do_test(int t)
{
	long long n, k;
	long long min, max;
	struct partition_set p[N_PART] = { 0 };
	
	scanf("%lld %lld", &n, &k);

	p[0].size = n;
	p[0].count = 1;

	while (k > p[0].count)
	{
		long long size1, size2;
		long long count1, count2;
		int i;
		/* The next p[0].count people to enter take the central stall in each of the largest partitions */
		k -= p[0].count;
		
		if (p[0].size & 1)
		{
			/* odd: each partition creates two new ones of size (N-1)/2 */
			size1 = (p[0].size - 1) / 2;
			count1 = p[0].count * 2;
			size2 = 0;
			count2 = 0;
		}
		else
		{
			/* even: each partition creates one new one of size N/2 and one new one of size N/2 - 1 */
			size1 = p[0].size / 2;
			count1 = p[0].count;
			size2 = p[0].size / 2 - 1;
			count2 = p[0].count;
		}

		/* Wipe the current parition out */
		memmove(&p[0], &p[1], (N_PART - 1) * sizeof p[0]);
		p[N_PART - 1].size = 0;
		p[N_PART - 1].count = 0;

		for (i = 0; i < N_PART && p[i].size != 0; i++)
		{
			if (p[i].size == size1)
			{
				p[i].count += count1;
				size1 = size2;
				count1 = count2;
				size2 = 0;
				count2 = 0;
			}
		}

		if (size1)
		{
			if (i >= N_PART)
			{
				int j;
				DEBUGF("Partition table overflow!\n");
				DEBUGF("*size1 = %lld count1 = %lld size2 = %lld count2 = %lld\n", size1, count1, size2, count2);
				for (j = 0; j < N_PART; j++)
					DEBUGF("p[%d] = { .size = %lld, .count = %lld }\n", j, p[j].size, p[j].count);
				exit(1);
			}

			p[i].size = size1;
			p[i].count = count1;
			i++;
		}

		if (size2)
		{
			if (i >= N_PART)
			{
				int j;
				DEBUGF("Partition table overflow!\n");
				DEBUGF("size1 = %lld count1 = %lld *size2 = %lld count2 = %lld\n", size1, count1, size2, count2);
				for (j = 0; j < N_PART; j++)
					DEBUGF("p[%d] = { .size = %lld, .count = %lld }\n", j, p[j].size, p[j].count);
				exit(1);
			}

			p[i].size = size2;
			p[i].count = count2;
		}
	}

	/* The last person is going to pick the stall in the middle of parititon p[0]. */

	if (p[0].size & 1)	
	{
		/* Odd: min(L_s,R_s) = max(L_s,R_s) = (N-1)/2 */
		min = max = (p[0].size - 1) / 2;	
	}
	else
	{
		/* even: min(l_s, R_s) = (N/2) - 1, max(L_S, R_S) = (N/2) */
		max = (p[0].size / 2);
		min = max - 1;
	}

	printf("Case #%d: %lld %lld\n", t + 1, max, min);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
