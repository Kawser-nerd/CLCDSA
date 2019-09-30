#include <stdio.h>
static int n, a[100000];
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort#C
void qsort(int l, int r) {
    static int piv, tmp;
    int ll, rr, piv_i;
    if (r > l) {
        ll = l + 1;
        rr = r;
        piv_i = l + (r - l) / 2;
        tmp = a[l];
        a[l] = a[piv_i];
        a[piv_i] = tmp;
        piv = a[l];
        while (ll < rr) {
            if (a[ll] <= piv) {
                ++ll;
            } else {
                while (ll < --rr && a[rr] >= piv);
                tmp = a[ll];
                a[ll] = a[rr];
                a[rr] = tmp;
            }
        }
        --ll;
        tmp = a[l];
        a[l] = a[ll];
        a[ll] = tmp;
        qsort(l, ll);
        qsort(rr, r);
    }
}
int main(void) {
    int i, j, ans = 1;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &j);
        while (1)
            if (j & 1)
                break;
            else
                j >>= 1;
        a[i] = j;
    }
    qsort(0, n);
    for (i = 0; i < n - 1; ++i)
        if (a[i] != a[i + 1])
            ++ans;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:37:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &j);
         ^