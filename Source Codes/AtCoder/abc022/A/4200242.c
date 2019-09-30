#include<stdio.h>

int main(){
    int n,s,t,w=0,count=0,i;
    int a[1000];

    scanf("%d %d %d",&n,&s,&t);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        w += a[i];
        if(w>=s && w<=t){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&n,&s,&t);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^