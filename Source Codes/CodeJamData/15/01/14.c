#include <stdio.h>
#include <stdlib.h>



int main() {
	int t,s,i,j,n,f, tmp;
	char c;
	n = 0;


	scanf("%d\n", &t);
	for (i = 0; i < t; i++) {
		f =0;
		n = 0;
		scanf("%d\n", &s);
		// n is # of ppl standing
		// f is # of friends already invited
		for (j = 0; j <= s; j++) {
			scanf("%c", &c);
			tmp = ( int) (c - '0'); //# of ppl with shyness j
			if (n >= j) { //enough pplstanding, so no new friends needed
				n += tmp; 
			} else { //not enough ppl standing, invite more friends
				f += (j - n);
				n += tmp + j - n; //after inviting j-n friends, tmp ppl stood up
			}

		}
		scanf("\n");
		printf("Case #%d: %d\n", i+1, f);
	}

	return 0;
}
