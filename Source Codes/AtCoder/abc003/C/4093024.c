#include<stdio.h>

int main(){
    int n, k, i, j, work, c=0;
    int r[100]={0};
    double rate=0;

    scanf("%d %d",&n,&k);

    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }  

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(r[i]<r[j]){
                work = r[i];
                r[i] = r[j];
                r[j] = work;
            }
        }
    }

    for(j=k-1;j>=0;j--){
        rate = (rate + r[j])/2.0;
    }

    printf("%lf\n",rate);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&k);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r[i]);
         ^