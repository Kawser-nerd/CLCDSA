#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int no_cases, case_no;
#ifdef TESTING
	fputs("TESTING is on", stderr);
#endif
	scanf("%u", &no_cases);
	
	for (case_no = 0; case_no != no_cases; case_no++)
	{
		unsigned int p, n[4] = {0, 0, 0, 0}, groups, x, answer;
		scanf("%u%u", &groups, &p);
		while (groups--)
		{
			scanf("%u", &x);
			n[x%p]++;
		}
#ifdef TESTING
		printf("%u %u %u %u\n", n[0], n[1], n[2], n[3]);
#endif
		answer = n[0];
		switch (p)
		{
			case 2:
			answer += (n[1] + 1) / 2;
			break;
			
			case 3:
			x = n[1] < n[2] ? n[1] : n[2];
			answer += x;
			answer += (n[1] - x + 2) / 3;
			answer += (n[2] - x + 2) / 3;
			break;
			
			case 4:
			x = n[1] < n[3] ? n[1] : n[3];
			answer += x;
			answer += (n[2] + (n[1] + n[3] - x - x + 3) / 2) / 2;
			break;
		}
#ifdef TESTING
		printf("x = %u\n", x);
#endif
		
		printf("Case #%u: %u\n", case_no + 1, answer);
	}
	return 0;
}
