#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a < b) ? b : a)
#define LL long long

LL min1(int h, int w) { // h >= 3???????
    int h1, h2;
    LL min, max, s1, s2, s3, dif_min;
    dif_min = (LL)h*w;
    for(h1 = 1; h1 < h-1; ++h1) {
        h2 = (LL)(h - h1)/2;
        s1 = (LL)h1 * w;
        s2 = (LL)h2*w;
        s3 = (LL)(h - h1 - h2) * w;
        max = MAX(MAX(s1, s2), s3);
        min = MIN(MIN(s1, s2), s3);
        dif_min = MIN(dif_min, max - min);
        
    }
    return dif_min;
}

LL min2(int h, int w) { //h >= 2 ??w >=2???????
    int h1, w1;
    LL min, max, s1, s2, s3, dif_min;
    dif_min = (LL)h * w;
    for(h1 = 1; h1 < h; ++h1) {
        w1 = w / 2;
        s1 = (LL)h1 * w;
        s2 = (LL)(h - h1) * w1;
        s3 = (LL)(h - h1) * (w - w1);
        max = MAX(MAX(s1, s2), s3);
        min = MIN(MIN(s1, s2), s3);
        dif_min = MIN(dif_min, max - min);
    }
    return dif_min;
}

void solve(int h, int w) {
    LL  dif1 = (h >= 3)? min1(h, w) : (LL)h*w,
        dif2 = min2(h, w),
        dif3 = (h >= 3)? min1(w, h) : (LL)h*w,
        dif4 = min2(w, h),
        min;
    //LL test = (LL)h * w; printf("test : %lld\n", test);
    //printf("dif1; %lld dif2: %lld dif3: %lld dif4: %lld\n", dif1, dif2, dif3, dif4);
    min = MIN(dif1, dif2);
    min = MIN(dif3, min);
    min = MIN(dif4, min);
    printf("%lld\n", min);
}

int main(void)
{
    int h, w;
    scanf("%d %d", &h, &w);
    solve(h, w);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h, &w);
     ^