#include <stdio.h>
int main(){
    int n,count=0,point=1;
    scanf("%d",&n);
    int a[n],b[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=0;
    }
     while(1){
        if (point==2){
            break;
        }
        if (b[point-1]==1){
            count=-1;
            break;
        }
        b[point-1]=1;
        point=a[point-1];
        count++;
    }
    printf("%d\n",count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^