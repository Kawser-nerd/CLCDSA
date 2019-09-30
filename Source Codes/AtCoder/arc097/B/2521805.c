#include <stdio.h>
#define N 100000
typedef struct element {
    struct element *next;
} element;

typedef struct {
    int n;
    element *head;
    element *tail;
} set;

int l[N+1];
set *f[N+1];
int n;

element elements[N+1];

set sets[N];
int next_set = 0;

void initialize(int n) {
    int i;

    for (i = 1; i <= n; i++) {
        f[i] = NULL;
    }
}

void new_pair(int x, int y) {
    set *s = &sets[next_set++];

    f[x] = f[y] = s;

    elements[x].next = &elements[y];
    elements[y].next = NULL;

    s->n = 2;
    s->head = &elements[x];
    s->tail = &elements[y];
}

void merge(set *s1, set *s2) {
    element *e;

    if (s1->n < s2->n) {
        merge(s2, s1);
        return;
    }

    /** s2??????s1???? */
    for (e = s2->head; e; e = e->next) {
        f[e - elements] = s1;
    }

    s1->n += s2->n;
    s1->tail->next = s2->head;
    s1->tail = s2->tail;
}

void insert(int x, set *s) {
    f[x] = s;
    element *e = &elements[x];
    e->next = s->head;
    s->head = e;
    s->n++;
}

void add_pair(int x, int y) {
    set *f_x, *f_y;

    if ((f_x = f[x])) {
        if ((f_y = f[y])) {
            if (f_x != f_y) {
                merge(f_x, f_y);
            }
        } else {
            insert(y, f_x);
        }
    } else {
        if ((f_y = f[y])) {
            insert(x, f_y);
        } else {
            new_pair(x, y);
        }
    }
}

int movable(int from, int to) {
    if (from == to) {
        return !0;
    }

    return f[from] && f[to] && f[from] == f[to];
}

int main()
{
    int i;
    int m;
    int x, y;
    int r;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        scanf("%d", &l[i]);
    }

    initialize(n);
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        add_pair(x, y);
        /* printf("add_pair %d %d\n", x, y); */
        /* debug_print(); */
    }

    r = 0;
    for (i = 1; i <= n; i++) {
        if (movable(i, l[i])) {
            r++;
        }
    }

    printf("%d\n", r);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:104:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:107:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &l[i]);
         ^
./Main.c:112:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x, &y);
         ^