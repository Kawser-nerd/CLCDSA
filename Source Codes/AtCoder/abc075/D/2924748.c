#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct {
    long long x;
    long long y;
} dot_t;

int sortx(const void *a, const void *b){
    return ((dot_t*)a)->x - ((dot_t*)b)->x ;
}

int sorty(const void *a, const void *b){
    return ((dot_t*)a)->y - ((dot_t*)b)->y ;
}

int main(void){
    int n,k;
    long long tmp=LONG_MAX,ans=LONG_MAX;
    scanf("%d%d",&n,&k);
    dot_t dx[n],dy[n];
    for (int i=0; i<n; i++){
        scanf("%lld%lld",&dx[i].x,&dx[i].y);
        dy[i].x=dx[i].x;
        dy[i].y=dx[i].y;
    }
    qsort (dx,n,sizeof(dot_t),sortx);
    qsort (dy,n,sizeof(dot_t),sorty);
    for (int a=0; a<n; a++){
        for (int b=a+1; b<n; b++){
            for (int c=0; c<n; c++){
                for (int d=c+1; d<n; d++){
                    int count=0;
                    for (int e=0; e<n; e++){
                        if (dx[e].x>=dx[a].x && dx[e].x<=dx[b].x && dx[e].y>=dy[c].y && dx[e].y<=dy[d].y){
                            count++;
                        }
                    }
                    if (count>=k){
                        tmp=(dx[b].x-dx[a].x)*(dy[d].y-dy[c].y);
                    }
                    if (ans>tmp){
                        ans=tmp;
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:27:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&dx[i].x,&dx[i].y);
         ^