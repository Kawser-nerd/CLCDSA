/* AtCoder My Practice
 * author: Leonardone @ NEETSDKASU
 */
#include <stdio.h>
#include <stdlib.h>
 
#define N_MAX (200001)
#define MAX(A,B) ((A) > (B) ? (A) : (B))
 
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
    Range *tmp;
    int ld = depth(range->lbound);
    int ud = depth(range->ubound);
    range->depth = MAX(ld, ud) + 1;
    if (abs(ld - ud) < 2) { return range; }
    tmp = range;
    if (ud > ld) {
        int uld = depth(range->ubound->lbound);
        int uud = depth(range->ubound->ubound);
        if (uud > uld) {
            range = tmp->ubound;
            tmp->ubound = range->lbound;
            range->lbound = tmp;
        } else {
            range = tmp->ubound->lbound;
            tmp->ubound->lbound = range->ubound;
            range->ubound = tmp->ubound;
            tmp->ubound = range->lbound;
            range->lbound = tmp;
        }
    } else {
        int lld = depth(range->lbound->lbound);
        int lud = depth(range->lbound->ubound);
        if (lud > lld) {
            range = tmp->lbound->ubound;
            tmp->lbound->ubound = range->lbound;
            range->lbound = tmp->lbound;
            tmp->lbound = range->ubound;
            range->ubound = tmp;
        } else {
            range = tmp->lbound;
            tmp->lbound = range->ubound;
            range->ubound = tmp;
        }
    }
    tmp->depth = MAX(depth(tmp->lbound), depth(tmp->ubound)) + 1;
    range->depth = MAX(depth(range->lbound), depth(range->ubound)) + 1;
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
./Main.c:120:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:124:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^