#include <stdio.h>
#include <stdlib.h>

void switches()
{
    int S,Q;
    int i,j;

    char engines[100][103];
    int searches[1000];

    int min[1000][100];
    //    int prev;

    scanf("%d",&S);
    fgets(engines[0],102,stdin);

    for (i = 0; i < S; i++) {
	fgets(engines[i],102,stdin);
    }

    scanf("%d",&Q);
    fgets(engines[i],102,stdin);
    for (i = 0; i < Q; i++) {
	int j;
	char buf[102];
	fgets(buf,102,stdin);

	for (j = 0; j < S; j++) {
	    if (strcmp(buf, engines[j]) == 0) {
		searches[i] = j;
		break;
	    }
	}
	if (j == S) printf("What?!\n");
    }

    for (i = 0; i < S; i++) {
	min[0][i] = 0;
    }
    min[0][searches[0]] = 1;
    
    for (j = 1; j < Q; j++) {
	for (i = 0; i < S; i++) {
	    if (i == searches[j]) {
		int m;
		int lastmin = 1000;
		for (m = 0; m < S; m++) {
		    if (i == m) continue;

		    if (lastmin > min[j-1][m])
			lastmin = min[j-1][m];
		}
		min[j][i] = 1 + lastmin;
	    }
	    else
		min[j][i] = min[j-1][i];
	}
    }

    int lastmin = 1000;
    for (i = 0; i < S; i++) {
	if (lastmin > min[j-1][i])
	    lastmin = min[j-1][i];
    }
    printf("%d\n",lastmin);
}

int main(int argc, char *argv[])
{
    int cases;
    int i;

    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
	printf("Case #%d: ",(i+1));
	switches();
    }

    return 0;
}
