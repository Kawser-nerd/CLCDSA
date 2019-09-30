#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    struct element *next;
} element;

typedef struct {
    int n;
    element *head;
    element *tail;
} set;

int *l;
set **f;

element *elements;

void initialize(int n) {
    int i;

    l = calloc(n + 1, sizeof(int));
    f = calloc(n + 1, sizeof(set *));
    elements = calloc(n + 1, sizeof(element));

    for (i = 1; i <= n; i++) {
        f[i] = NULL;
    }
}

void new_pair(int x, int y) {
    set *s = malloc(sizeof(set));

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
    int n, m;
    int x, y;
    int r;

    scanf("%d %d", &n, &m);

    initialize(n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &l[i]);
    }

    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        add_pair(x, y);
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
./Main.c:105:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:110:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &l[i]);
         ^
./Main.c:114:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x, &y);
         ^