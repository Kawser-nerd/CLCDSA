#include <stdio.h>

int main(){
    int t,n,m,i,j=0;
    
    scanf("%d%d",&t,&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    scanf("%d",&m);
    int b[m];
  	for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
  
    for(i=0;i<m;i++){
        while(1){
            if(b[i]<a[j] || j>=n){
                puts("no");
                return 0;
            }else if(b[i]>=a[j] && b[i]<=a[j]+t){
                j++;
              	break;
            }
            j++;
            
        }
    }
    
    puts("yes");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&t,&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&b[i]);
         ^