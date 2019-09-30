#include <stdio.h>
#include <stdlib.h>

int main(void){
	long x = 0, y = 0, count = 0;
	char c;
	while(1){
		c = getchar();
		if(c == '\n')break;
		if(c == 'U')y++;
		if(c == 'D')y--;
		if(c == 'L')x--;
		if(c == 'R')x++;
		if(c == '?')count++;
	}
	if(getchar() == '1')
		printf("%ld\n", labs(x) + labs(y) + count);
	else
		printf("%ld\n", (labs(x) + labs(y) - count) < 0 ? (x + y + count) % 2 : labs(x) + labs(y) - count);
	return 0;
}