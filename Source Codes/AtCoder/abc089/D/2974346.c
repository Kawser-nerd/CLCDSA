#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct{
    int a;
    int x;
    int y;
    int cost;
} cell_t;

int sort(const void *a, const void *b){
    return ((cell_t*)a)->a- ((cell_t*)b)->a ;
}

int main(void){
    int h,w,d,count=0;
    scanf("%d%d%d",&h,&w,&d);
    cell_t cell[h*w];
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            int p;
            scanf("%d",&p);
            cell[count].a=p;
            cell[count].x=i+1;
            cell[count].y=j+1;
            count++;
        }
    }
    qsort (cell,count,sizeof(cell_t),sort);
    for (int i=0; i<count; i++){
        if (i<d){
            cell[i].cost=0;
        } else {
            cell[i].cost=cell[i-d].cost+abs(cell[i].x-cell[i-d].x)+abs(cell[i].y-cell[i-d].y);
        }
    }
    int q;
    scanf("%d",&q);
    for (int i=0; i<q; i++){
        int l,r;
        scanf("%d%d",&l,&r);
        long long ans=cell[r-1].cost-cell[l-1].cost;
        printf("%lld\n",ans);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&h,&w,&d);
     ^
./Main.c:26:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&p);
             ^
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&q);
     ^
./Main.c:45:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&l,&r);
         ^