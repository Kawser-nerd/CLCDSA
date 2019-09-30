#include <stdio.h>

char str[200005];
int ch;
int sp = 0;

int main()
{

	while((ch = getchar()) != EOF) {

		if (ch == 'S') {
			sp++;
			str[sp] = 'S';
		} else if (ch == 'T') {
			if(str[sp] == 'S') {
				sp--;
			} else {
				sp++;
				str[sp] = 'T';
			}
		}
	}

	printf("%d\n", sp);

	return 0;
}