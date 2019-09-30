#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int no_cases, case_no;
	scanf("%u", &no_cases);
	for (case_no = 0; case_no != no_cases; case_no++)
	{
		unsigned int n;
		unsigned long long int d, place, speed,
		 splace = 0, sspeed = 1, x, y;
		
		scanf("%llu%u", &d, &n);
		while (n--)
		{
			scanf("%llu%llu", &place, &speed);
			place = d - place;
			if (place * sspeed > splace * speed)
			{
				splace = place;
				sspeed = speed;
			}
		}
		// d * sspeed / splace
		x = d * sspeed;
		y = x / splace;
		x %= splace;
		printf("Case #%u: %llu.%09llu\n", case_no + 1, 
		 y, x * 1000000000ULL / splace);
	}
	return 0;
}
