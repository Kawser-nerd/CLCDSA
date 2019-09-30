#include <stdlib.h>
#include <stdio.h>

int main()
{   int a[100001],n,i,len=0;
    scanf("%d",&n);
    a[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
            len+=abs(a[i]-a[i-1]);
    }
    a[n+1]=0;
    len+=abs(a[n]);
    for(i=1;i<=n;i++){
        if(i==0){
            printf("%d\n",len);
        }else{
            if(a[i]>=a[i-1]&&a[i]<=a[i+1]){
                printf("%d\n",len);
            }
            else if(a[i]<=a[i-1]&&a[i-1]<=a[i+1]){
                printf("%d\n",len-2*abs(a[i]-a[i-1]));
            }
            else if(a[i]<=a[i+1]&&a[i+1]<=a[i-1]){
              printf("%d\n",len-2*abs(a[i]-a[i+1]));  
            }
            else if(a[i+1]<=a[i]&&a[i]<=a[i-1]){
                printf("%d\n",len);
            }
            else if(a[i-1]<=a[i+1]&&a[i+1]<=a[i]){
                printf("%d\n",len-2*abs(a[i+1]-a[i]));
            }
            else if(a[i+1]<=a[i-1]&&a[i-1]<=a[i]){
                printf("%d\n",len-2*abs(a[i]-a[i-1]));
            }
        }
    }
    
    

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^