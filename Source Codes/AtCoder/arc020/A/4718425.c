#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int ant;
	int bug;

	ant = 0;
	bug = 0;

	scanf("%d %d", &ant, &bug);

	if((ant < -1000) || (ant > 1000) || (bug < -1000) || (bug > 1000)) {
		return -1;
	}

/*	printf("DEBUG: ant:%d, bug,%d\n",ant,bug);*/

	if(abs(ant) > abs(bug)) {
		printf("Bug\n");
	}else if(abs(ant) < abs(bug)) {
		printf("Ant\n");
	}else {
		printf("Draw\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &ant, &bug);
  ^