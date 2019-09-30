#include <stdio.h>
#include <string.h>
void main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output5.out", "w", stdout);
	int cases, i, X, R, C, casecount;
	char result[1000][10];
	scanf("%d", &cases);
	for (casecount = 1; casecount <= cases; casecount++){
		scanf("%d%d%d", &X, &R, &C);
		if (X == 4){
			if ((R*C%X == 0) && (X <= R || X <= C) && (R>2 && C>2)){
				strcpy(result[casecount], "Gabriel");
			}
			else
				strcpy(result[casecount], "Richard");
		}
		if (X == 3){
			if ((R*C%X == 0) && (X <= R || X <= C) && (R>1 && C>1))
				strcpy(result[casecount], "Gabriel");
			else
				strcpy(result[casecount], "Richard");
		}
		if (X == 2){
			if ((R*C%X == 0) && (R >= 2 || C >= 2))
				strcpy(result[casecount], "Gabriel");
			else
				strcpy(result[casecount], "Richard");
		}
		if (X == 1){
			strcpy(result[casecount], "Gabriel");

		}
	}
	for (casecount = 1; casecount <= cases; casecount++){
		printf("\nCase #%d: %s", casecount, result[casecount]);
	}
}