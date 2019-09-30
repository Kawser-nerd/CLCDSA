#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int a;
    int b;
} sword_t;

int sorta(const void *a, const void *b){
    return ((sword_t*)b)->a -((sword_t*)a)->a ;
}

int sortb(const void *a, const void *b){
    return ((sword_t*)b)->b -((sword_t*)a)->b ;
}

int main(void){
    int n,h,ans=0;
    scanf("%d%d",&n,&h);
    sword_t sword[n];
    for (int i=0; i<n; i++){
        scanf("%d%d",&sword[i].a,&sword[i].b);
    }
    qsort (sword,n,sizeof(sword_t),sorta);
    int s=sword[0].a;
    qsort (sword,n,sizeof(sword_t),sortb);
    for (int i=0; i<n; i++){
        if (sword[i].b>=s){
            h-=sword[i].b;
            ans++;
        }
        if (h<=0){
            break;
        }
    }
    while (h>0){
        h-=s;
        ans++;
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&h);
     ^
./Main.c:26:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&sword[i].a,&sword[i].b);
         ^