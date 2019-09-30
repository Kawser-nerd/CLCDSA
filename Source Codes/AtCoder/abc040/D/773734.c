#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



struct link {
    int from, to;
    int year;
};
struct citizen {
    int cno;
    int pos;
    int year;
};

int
linkf(struct link *a, struct link *b)
{
    return b->year - a->year;
}
int
citizenf(struct citizen *a, struct citizen *b)
{
    return b->year - a->year;
}
struct city {
    int cnt;
    struct city *to;
} *city;

void conn(struct city *from, struct city *to);
struct city *compress(struct city *ptr);

int
main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    city = calloc(sizeof(struct city), n);
    struct link *link = calloc(sizeof(struct link), m);
    int i;
    for (i = 0; i < m; ++i) {
        int a,b,y;
        scanf("%d%d%d", &a, &b, &y);
        link[i].from = a-1;
        link[i].to = b-1;
        link[i].year = y;
    };

    qsort(link, m, sizeof(struct link), (int (*)(const void *, const void *))linkf);

    int q;
    scanf("%d", &q);

    struct citizen *citizen = calloc(sizeof(struct citizen), q);
    int *res = (int *)calloc(sizeof(int), q);
    for (i = 0; i < q; ++i) {
        int v, w;
        scanf("%d%d", &v, &w);
        citizen[i].cno = i;
        citizen[i].pos = v-1;
        citizen[i].year = w;
    }
    qsort(citizen, q, sizeof(struct citizen), (int (*)(const void *, const void *))citizenf);

    int lno = 0;
    int cno;
    for (i = 0; i < n; ++i)
        city[i].cnt = 1;

    for (cno = 0; cno < q; ++cno) {
        while (lno < m && link[lno].year > citizen[cno].year) {
            conn(&city[link[lno].from], &city[link[lno].to]);
            lno++;
        }
        res[citizen[cno].cno] = compress(&city[citizen[cno].pos])->cnt;
    }
    for (cno = 0; cno < q; ++cno)
        printf("%d\n", res[cno]);
    return 0;
}
struct city *
compress(struct city *ptr)
{
    struct city *save = ptr;
    while (ptr->to)
        ptr = ptr->to;
    struct city *tmp;
    while ((tmp = save->to)) {
        save->to = ptr;
        save = tmp;
    }
    return ptr;
}
void
conn(struct city *from, struct city *to)
{
    from = compress(from);
    to = compress(to);
    if (from != to) {
        to->cnt = from->cnt + to->cnt;
        from->to = to;
    }
} ./Main.c: In function ‘main’:
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &m);
     ^
./Main.c:46:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &a, &b, &y);
         ^
./Main.c:55:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &q);
     ^
./Main.c:61:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &v, &w);
         ^