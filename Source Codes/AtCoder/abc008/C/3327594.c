#include <stdio.h>

int main(void){
    int n;
    double ans=0;
    scanf("%d",&n);
    int c[n];
    for (int i=0; i<n; i++){
        scanf("%d",&c[i]);
    }
    for (int i=0; i<n; i++){
        int count=-1;
        for (int j=0; j<n; j++){
            if (c[i]%c[j]==0){
                count++;
            }   
        }
        if (count%2!=0){
            ans+=(double)1/(double)2;
        } else{
            ans+=((double)count+2)/((double)count*2+2);
        }
    }
    printf("%.6f\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&c[i]);
         ^