#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int nc, cn;
	scanf("%u", &nc);
	
	for (cn = 0; cn != nc; cn++)
	{
		unsigned short int activity[1440] = {};
		unsigned int a, b, c, d, t, w, answer = 0, last = 2, lastt, \
		 ts[2] = {}, tfree = 0, gaps[2][1440] = {}, x;
		scanf("%u%u", &a, &b);
		while (a--)
		{
			scanf("%u%u", &c, &d);
			activity[c] = d - c << 1;
		}
		while (b--)
		{
			scanf("%u%u", &c, &d);
			activity[c] = d - c << 1 | 1;
		}
		for (t = 1440; t--; )
		{
			if (activity[t])
			{
				last = activity[t] & 1;
				lastt = t + (activity[t] >> 1) - 1440;
				break;
			}
		}
		if (last == 2) //no activities
		{
			answer = 2;
			goto done;
		}
		
		for (t = 0; t != 1440; t++)
		{
			if (activity[t])
			{
				ts[w = activity[t] & 1] += activity[t] >> 1;
				if (w ^ last) //different
				{
					tfree += t - lastt;
					answer++;
				}
				else
				{
					ts[w] += t - lastt;
					gaps[w][t - lastt]++;
				}
				last = w;
				lastt = t + (activity[t] >> 1);
			}
		}
		
		w = 0;
		if (ts[0] > 720 || (w = 1, ts[1] > 720))
		{
			x = ts[w] - 720;
			for (t = 1440; t--; )
			{
				while (gaps[w][t])
				{
					gaps[w][t]--;
					answer += 2;
					if (t >= x)
					{
						t = 0;
						break;
					}
					x -= t;
				}
			}
		}
		
		done:
		printf("Case #%u: %u\n", cn + 1, answer);
	}
	
	return 0;
}
