#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,i,j=0,*a;
    scanf("%d",&n);
    a=(int*) malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;j<=n;j++){
        if(i==1){
            printf("%d\n",j);
            free(a);
            return 0;
        }
        i=a[i]-1;
    }
    printf("-1\n");
    free(a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^