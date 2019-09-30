#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))

int square(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(void){
    int x1,y1,r;
    int x2,y2,x3,y3;
    scanf("%d%d%d",&x1,&y1,&r);
    scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
    
    if(x1-r >= x2 && y1-r >= y2 && x1+r <= x3 && y1+r <= y3) {
        printf("NO\n");
        printf("YES\n");
        return 0;
    }
    if(square(x1,y1,x2,y2) <= r*r && square(x1,y1,x3,y3) <= r*r && square(x1,y1,x2,y3) <= r*r && square(x1,y1,x3,y2) <= r*r){
        printf("YES\n");
        printf("NO\n");
        return 0;
    } 
    printf("YES\n");
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x1,&y1,&r);
     ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
     ^