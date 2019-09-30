#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

int distance(struct point p1, struct point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main(void) {
    int h, w, d;
    struct point p[90000 + 1];//don't use a[0]
    int q;
    int dd[90000 + 1] = {0};//don't use dd[0]

    scanf("%d%d%d", &h, &w, &d);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int a;
            scanf("%d", &a);
            p[a].x = i;
            p[a].y = j;
        }
    }

    //dd[k] is the distance of p[k] and p[k % d] (if k % d == 0, distance of p[k] and p[d])
    for (int k = d + 1; k <= h * w; k++) {
        dd[k] = dd[k - d] + distance(p[k], p[k - d]);
    }

    scanf("%d", &q);
    for (int k = 0; k < q; k++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", dd[r] - dd[l]);
    }
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &h, &w, &d);
     ^
./Main.c:23:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &a);
             ^
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &q);
     ^
./Main.c:37:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &l, &r);
         ^