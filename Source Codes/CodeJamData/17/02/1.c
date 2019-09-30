#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int no_cases, case_no;
	char number[21] = {0}, *p;
	scanf("%u", &no_cases);
	getchar();
	for (case_no = 0; case_no != no_cases; case_no++)
	{
		gets(p = number + 1);
		while (p[0] <= p[1]) {++p;}
		if (p[1])
		{
			while (p[-1] == p[0]) {--p;}
			--*p;
			while (*++p) {*p = '9';} 
		}
		printf("Case #%u: %s\n", case_no + 1, number + 1 + (number[1] == '0'));
	}
	return 0;
}
