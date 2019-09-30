#include <stdio.h>

int main(void){
    int n;
    int hi[300005];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&hi[i]);
    }
    int ans=0,max=0;
    for(int i=0; i<n; i++){
        ans=1;
        if(i==0){
            int j=0;
            while(hi[j]>hi[j+1] && j<n-1){
                ans++;
                j++;
            }
        }
        else if(i==n-1){
            int j=n-1;
            while(hi[j-1]<hi[j] && 0<j){
                ans++;
                j--;
            }
        }
        else if(hi[i-1]<hi[i] && hi[i]>hi[i+1]){
            int j=i,k=i;
            while(hi[j-1]<hi[j] && 0<j){
                ans++;
                j--;
            }
            while(hi[k]>hi[k+1] && k<n-1){
                ans++;
                k++;
            }
        }
        if(max<ans)max=ans;
    }
    printf("%d\n",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&hi[i]);
         ^