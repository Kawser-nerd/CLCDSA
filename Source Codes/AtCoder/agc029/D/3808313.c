#include <stdio.h>
#include <limits.h>
#define H 200000
int v[H+1];
int main(void){
    int h, w, n, x, y;
    scanf("%d %d %d\n", &h, &w, &n);
    for(int i=1; i<h+1; i++){ v[i] = i+1; }
    for(int i=0; i<n; i++){
        scanf("%d %d\n", &x, &y);
        v[x] = y<v[x] ? y : v[x];
    }
    int right = 1;
    for(int x=1; x<h; x++){
        if(v[x+1]<right+1){
            printf("%d\n", x);
            return 0;
        }else if(v[x+1]>right+1){
            right++;
        }
    }
    printf("%d\n", h);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d\n", &h, &w, &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d\n", &x, &y);
         ^