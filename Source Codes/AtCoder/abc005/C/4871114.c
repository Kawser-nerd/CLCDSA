#include <stdio.h>
#include <stdlib.h>
int main(void){
    int t,n,m,i,j,*a,b;
    scanf("%d",&t);
    scanf("%d",&n);
    a=(int*) malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    i=0;
    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d",&b);
        if(i>=n){
            printf("no\n");
            free(a);
            return 0;
        }
        if(a[i]>b){
            printf("no\n");
            free(a);
            return 0;
        }
        while(a[i]+t<b){
            i++;
            if(i>=n){
                printf("no\n");
                free(a);
                return 0;
            }
        }
        i++;
    }
    printf("yes\n");
    free(a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&b);
         ^