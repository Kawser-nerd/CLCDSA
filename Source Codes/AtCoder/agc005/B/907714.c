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

void calc(int value, register int index) {
    register Range *tmp = &range;
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


int main(void){
    register int i, n;
    int a;
    
    scanf("%d", &a); n = a;

    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        idx[a] = i;
    }
    
    range.upper = n - 1;
    
    for (i = 1; i <= n; i++) {
        calc(i, idx[i]);
    }
    
    printf("%lld\n", sum);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a); n = a;
     ^
./Main.c:60:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^