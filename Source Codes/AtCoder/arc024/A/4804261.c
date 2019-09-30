#include <stdio.h>
#include <stdlib.h>
int main(void){
    int L,R,*l,*r,i,j,p=0;
    scanf("%d%d",&L,&R);
    l=(int*) malloc(sizeof(int)*L);
    r=(int*) malloc(sizeof(int)*R);
    for(i=0;i<L;i++){
        scanf("%d",&l[i]);
    }
    for(j=0;j<R;j++){
        scanf("%d",&r[j]);
    }
    for(i=0;i<L;i++){
        for(j=0;j<R;j++){
            if(l[i]==r[j]){
                p++;
                r[j]=0;
                break;
            }
        }
    }
    printf("%d\n",p);
    free(l);
    free(r);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&L,&R);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&l[i]);
         ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r[j]);
         ^