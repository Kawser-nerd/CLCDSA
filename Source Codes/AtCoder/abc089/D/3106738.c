#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct _place{
    int x,y;
}place;

//D ???????????????????
int main(void){
    int H,W,D;
    scanf("%d %d %d",&H,&W,&D);
    place p[H*W+1];
    int i,j,val;
    int p_sum[H*W+1];
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            scanf("%d ",&val);
            p[val].y = i+1;
            p[val].x = j+1;
        }
    }
    int now;
    for(i=0;i<H*W+1;i++){
        p_sum[i] = 0;
    }
    for(i=1;i<=D;i++){
        now=i;
        while(now+D<=H*W){//1 6 9 12????12-1????
            p_sum[now+D]+=p_sum[now] + abs(p[now+D].x-p[now].x)+abs(p[now+D].y-p[now].y);
            now += D;
        }
    }
    int Q;
    scanf("%d",&Q);
    int L[Q],R[Q];
    for(i=0;i<Q;i++){
        scanf("%d %d",&L[i],&R[i]);
    }
    int ans;
    for(i=0;i<Q;i++){
        ans = p_sum[R[i]]-p_sum[L[i]];
        printf("%d\n",ans);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&H,&W,&D);
     ^
./Main.c:19:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d ",&val);
             ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&Q);
     ^
./Main.c:39:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&L[i],&R[i]);
         ^