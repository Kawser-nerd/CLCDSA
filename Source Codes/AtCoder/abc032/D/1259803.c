#include <stdio.h>
#include <malloc.h>

typedef long long int int64;

struct ar {
    int n;
    int c;
    struct s {
        int w;
        int64 v;
    } s[0];
};

int64
add(struct ar *o, int w, int v, int x, struct ar *q)
{
    struct s *d = o->s;
    struct s *a = o->s;
    struct s *np = q->s;
    struct s *const ed = d+o->n;
    int64 h = -1;
    while (a < ed) {
        struct s z = { a->w + w, a->v + v};

        if (d >= ed)
            a++;
        else if (d->w > z.w)
            a++;
        else if (d->w < z.w)
            z = *d++;
        else {
            if (d->v >= z.v)
                z = *d;
            a++;
            d++;
        }

        if (z.w > x)
            break;
        if (h >= z.v)
            continue;
        *np++ = z;
        h = z.v;
    }
    q->n = np - q->s;
    return h;
}

int
main(void) {
    int n;
    int x;
    scanf("%d%d", &n, &x);
    struct ar *o = calloc(sizeof(struct ar) + sizeof(struct s)*n*2, 1);
    struct ar *q = calloc(sizeof(struct ar) + sizeof(struct s)*n*2, 1);
    o->c = n*2;
    q->c = n*2;
    o->s[0].w = 0;
    o->s[0].v = 0;
    o->n = 1;


    int64 vm = 0, i;
    for (i = 0; i < n; ++i) {
        int wi;
        int vi;
        scanf("%u%u", &vi, &wi);
        if (q->c < o->n * 2) {
            if (q->c < o->n)
                q->c = o->n;
            q->c *= 2;
            q = realloc(q, sizeof(struct ar) + sizeof(struct s)*q->c);
        }
        vm = add(o, wi, vi, x, q);
        struct ar *t = o;
        o = q;
        q = t;
    }
    printf("%lld\n", vm);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:54:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &x);
     ^
./Main.c:68:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u%u", &vi, &wi);
         ^