#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    int curcase = 0;
    while (curcase != t)
    {
        unsigned long long int val;
	scanf("%llu", &val);
	int i = 0;
	unsigned long long int pow = 1;
	while (pow * 10 <= val && pow > 0)
	{
	    int curdig = val / pow % 10;
	    int nextdig = val / (pow * 10) % 10;
	    if (curdig < nextdig)
	    {
                val /= pow * 10;
		val *= pow * 10;
		val--;
	    }
	    pow *= 10;
	}
        printf("Case #%d: %llu\n", curcase + 1, val);
	curcase++;
    }
    return 0;
}
