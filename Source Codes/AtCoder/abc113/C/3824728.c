#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int pref;       //prefecture number
    int year;       //constructed year
    int init_idx;   //input order
    int pref_idx;   //pref order
} city;

/* sort by year */
int cmp_year(const void *a, const void *b) {
    return ((city*)a)->year - ((city*)b)->year;
}
/* sort by init_idx */
int cmp_idx(const void *a, const void *b) {
    return ((city*)a)->init_idx - ((city*)b)->init_idx;
}


int main()
{
    int n, m;
    int i;

    scanf("%d %d",&n,&m);

    city c[m];
    int *count = (int*)calloc(n+1,sizeof(int));      //count of each pref order

    for(i=0; i<m; i++) {
        scanf("%d %d", &c[i].pref, &c[i].year);
        c[i].init_idx = i;      //c[i]'s init_idx equals to "i";
    }

    /* sort by year */
    qsort(c,m,sizeof(city),cmp_year);

    /* count c[i]'s order in a pref
       (already arranged in year order) */
    for(i=0; i<m; i++) {
        c[i].pref_idx = (++count[c[i].pref]);
    }

    /* sort by init_idx to inital order */
    qsort(c,m,sizeof(city),cmp_idx);

    for(i=0; i<m; i++) {
        printf("%06d%06d\n", c[i].pref, c[i].pref_idx);
    }

    free(count);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^
./Main.c:34:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &c[i].pref, &c[i].year);
         ^