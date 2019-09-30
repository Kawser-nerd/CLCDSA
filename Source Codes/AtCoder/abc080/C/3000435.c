#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    scanf("%d",&n);
    int open[105][11];
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            scanf("%d",&open[i][j]);
        }
    }
    int profit[105][11];
    for(int i=0; i<n; i++){
        for(int j=0; j<=10; j++){
            scanf("%d",&profit[i][j]);
        }
    }

    int ans=0,sum,max=-1000000000,count;
    for(int i=1; i<1<<10; i++){
        ans=0;
        for(int j=0; j<n; j++){
            count=0;
            for(int k=0; k<10; k++){
                if( (1&i>>k) && open[j][k] ){
                    count++;
                }
            }
            ans+=profit[j][count];
        }
        if(ans>max)max=ans;
    }
    printf("%d",max);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&open[i][j]);
             ^
./Main.c:16:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&profit[i][j]);
             ^