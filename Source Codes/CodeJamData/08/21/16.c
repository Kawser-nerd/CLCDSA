#define MAX_LEN 2000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char input[MAX_LEN+1];

inline int read_line() {
	if (!gets(input)) return -1;
	return (strlen(input));
}

static inline long read_number() {
	read_line(input);
	return (atoi(input));
}

int main() {

	int no_cases, c;

	long t, A, B, C, D, x, y, M, q, i, v1, v2, v3;
	long treeX[100000], treeY[100000];


	no_cases=read_number();
	for (c=0; c<no_cases; c++) {
		
		read_line();
		sscanf(input, "%ld %ld %ld %ld %ld %ld %ld %ld", &t, &A, &B, &C, &D, &x, &y, &M);
		treeX[0]=x;
		treeY[0]=y;
//		printf("tree @ %ld, %ld\n", treeX[0], treeY[0]);
		for (i=1; i<t; i++) {
			x=((long long)A*x+B)%M;
			y=((long long)C*y+D)%M;
			treeX[i]=x;
			treeY[i]=y;
//			printf("tree @ %ld, %ld\n", treeX[i], treeY[i]);
		}
		q=0;
		for (v1=0; v1<t-2;v1++)
			for (v2=v1+1; v2<t-1;v2++)
				for (v3=v2+1; v3<t; v3++)
					if ((((treeX[v1]+treeX[v2]+treeX[v3])%3)==0) &&
					    (((treeY[v1]+treeY[v2]+treeY[v3])%3)==0)){
//							printf("1 tree @ %ld, %ld\n", treeX[v1], treeY[v1]);
//							printf("2 tree @ %ld, %ld\n", treeX[v2], treeY[v2]);
//							printf("3 tree @ %ld, %ld\n", treeX[v3], treeY[v3]);
						q++;
					}

		printf("Case #%d: %d\n", c+1, q);
	}
	return 0;
}
