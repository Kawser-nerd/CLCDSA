/* AtCoder My Practice
 * author: Leonardone @ NEETSDKASU
 */
#include <stdio.h>
#include <stdlib.h>
 
#define N_MAX (200001)
 
typedef struct _range {
    int upper, lower, depth;
    struct _range *ubound, *lbound;
} Range;
 
Range *newRange(int lower, int upper) {
    Range *range = (Range*)malloc(sizeof(Range));
    range->lower = lower;
    range->upper = upper;
    range->ubound = range->lbound = NULL;
    range->depth = 1;
    return range;
}

int depth(Range* range) {
    if (range) { return range->depth; }
    else { return 0; }
}

Range* rotate(Range* range) {
    return range;
}

Range* appendMax(Range* range, Range* newone) {
    if (range == NULL) { 
        return newone;
    }
    range->ubound = appendMax(range->ubound, newone);
    return rotate(range);
}

Range* appendMin(Range* range, Range* newone) {
    if (range == NULL) {
        return newone;
    }
    range->lbound = appendMin(range->lbound, newone);
    return rotate(range);
}
 
int idx[N_MAX];
long long sum, len;

Range* calc(Range *range, int value, int index) {
    if (range->lower <= index && index <= range->upper) {
        len = (long long)(range->upper - range->lower + 1);
        sum += (len * (len + 1LL) / 2LL) * (long long)value;
        len = (long long)(range->upper - index);
        sum -= (len * (len + 1LL) / 2LL) * (long long)value;
        len = (long long)(index - range->lower);
        sum -= (len * (len + 1LL) / 2LL) * (long long)value;
        if (range->lower == index) {
            range->lower++;
        } else if (range->upper == index) {
            range->upper--;
        } else if (range->upper - index > index - range->lower) {
            range->lbound = appendMax(range->lbound, newRange(range->lower, index - 1));
            range->lower = index + 1;
        } else {
            range->ubound = appendMin(range->ubound, newRange(index + 1, range->upper));
            range->upper = index - 1;
        }
    } else if (index < range->lower) {
        range->lbound = calc(range->lbound, value, index);
    } else {
        range->ubound = calc(range->ubound, value, index);
    }
    return rotate(range);
}
 
 
int main(void){
    int i, n;
    
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        idx[a] = i;
    }
    
    Range *range = newRange(0, n - 1);
    
    for (i = 1; i <= n; i++) {
        range = calc(range, i, idx[i]);
    }
    
    printf("%lld\n", sum);
 
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:82:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:86:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^