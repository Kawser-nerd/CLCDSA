/* AtCoder My Practice
 * author: Leonardone @ NEETSDKASU
 */
#include <stdio.h>
#include <stdlib.h>

#define N_MAX (200001)

typedef struct _range {
    int upper, lower;
    struct _range *ubound, *lbound;
} Range;

Range *newRange(int lower, int upper) {
    Range *range = (Range*)malloc(sizeof(Range));
    range->lower = lower;
    range->upper = upper;
    return range;
}

int idx[N_MAX];
long long sum;
Range range;

void calc(int value, int index) {
    Range *tmp = &range;
    long long len1, len2, len3;
    for (;;) {
        if (tmp->lower <= index && index <= tmp->upper) {
            len1 = (long long)(tmp->upper - tmp->lower + 1);
            len2 = (long long)(tmp->upper - index);
            len3 = (long long)(index - tmp->lower);
            sum += (len1 * (len1 + 1LL) - (len2 * (len2 + 1LL)) - (len3 * (len3 + 1))) / 2LL * (long long)value;
            if (tmp->lower == index) {
                tmp->lower++;
            } else if (tmp->upper == index) {
                tmp->upper--;
            } else {
                tmp->lbound = newRange(tmp->lower, index - 1);
                tmp->ubound = newRange(index + 1, tmp->upper);
                tmp->lower = tmp->upper = index;
            }
            break;
        } else if (index < tmp->lower) {
            tmp = tmp->lbound;
        } else {
            tmp = tmp->ubound;
        }
    }
}

char buf[N_MAX * 10];
char *p = buf;

int getInt(void) {
    int v = 0;
    while (*p < '0' || '9' < *p) p++;
    while ('0' <= *p && *p <= '9') {
        v = v * 10 + (int)(*p - '0');
        p++;
    }
    return v;
}

int main(void){
    int i, n;
    int a;
    
    a = fread(buf, sizeof(char), sizeof(buf), stdin);
    
    n = getInt();

    for (i = 0; i < n; i++) {
        a = getInt();
        idx[a] = i;
    }
    
    range.upper = n - 1;
    
    for (i = 1; i <= n; i++) {
        calc(i, idx[i]);
    }
    
    printf("%lld\n", sum);

    return 0;
}