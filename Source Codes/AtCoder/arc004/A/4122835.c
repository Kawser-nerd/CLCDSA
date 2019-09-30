#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    int x[n];
    int y[n];
    double res;
    double ans = 0; 

    for(int i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }

    for(int j=0;j<n;j++){
        for(int k=1;k<n;k++){
            res = sqrt(pow((x[j] - x[k]),2) + pow((y[j] - y[k]),2));
            if(res > ans){
                ans = res;
            }
        }
    }

    printf("%f\n",ans);

} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&x[i],&y[i]);
         ^