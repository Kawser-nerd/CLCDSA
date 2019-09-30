#include <stdio.h>

int main(void){
    int l,h,n;
    scanf("%d %d",&l,&h);
    scanf("%d",&n);
    int data[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&data[i]);
    }
    for(int i = 0;i<n;i++){
        if(data[i] < l){
            printf("%d\n",l-data[i]);
        }else if(data[i] <= h){
            printf("0\n");
        }else{
            printf("-1\n");
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&l,&h);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&data[i]);
         ^