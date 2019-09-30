#include <stdio.h>
#include <stdlib.h>

#define DEPART_A 3
#define DEPART_B 4
#define ARRIVE_A 1
#define ARRIVE_B 2

void schedule()
{
    int T;
    int NA, NB;
    int na, nb;
    int ca, cb;
    int i,j;
    
    int *times;
    int *event;

    scanf("%d",&T);
    scanf("%d %d",&NA,&NB);

    times = (int *)malloc(2*(NA+NB)*sizeof(int));
    event = (int *)malloc(2*(NA+NB)*sizeof(int));

    j = 0;
    for (i = 0; i < NA; i++) {
	int h,m;
	
	scanf("%d:%d",&h,&m);
	times[j] = h*60+m;
	event[j] = DEPART_A;
	j++;

	scanf("%d:%d",&h,&m);
	times[j] = h*60+m+T;
	event[j] = ARRIVE_B;
	j++;
    }

    for (i = 0; i < NB; i++) {
	int h,m;
	
	scanf("%d:%d",&h,&m);
	times[j] = h*60+m;
	event[j] = DEPART_B;
	j++;

	scanf("%d:%d",&h,&m);
	times[j] = h*60+m+T;
	event[j] = ARRIVE_A;
	j++;
    }

    // sort
    for (i = 1; i < 2*(NA+NB); i++) {
	int t = times[i];
	int e = event[i];

	for (j = (i-1); j >= 0 && (times[j] > t || (times[j] == t && event[j] > e)); j--) {
	    times[j+1] = times[j];
	    event[j+1] = event[j];
	}
	times[j+1] = t;
	event[j+1] = e;
    }

    //    for (i = 0; i < 2*(NA+NB); i++)
    //	printf("%d\n",event[i]);

    na = 0; nb = 0;
    ca = 0; cb = 0;
    for (i = 0; i < 2*(NA+NB); i++) {
	switch (event[i]) {
	case DEPART_A: if (ca == 0) na++; else ca--; break;
	case DEPART_B: if (cb == 0) nb++; else cb--; break;
	case ARRIVE_A: ca++; break;
	case ARRIVE_B: cb++; break;
	default: printf("What?\n");
	}
    }

    printf("%d %d\n",na,nb);
}

int main(int argc, char *argv[])
{
    int cases;
    int i;

    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
	printf("Case #%d: ",(i+1));
	schedule();
    }

    return 0;
}
