#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int n,k;

    scanf("%d%d",&n,&k);
    int s[n];
    
    for (int i=0; i<n; i++){
        scanf("%d",&s[i]);
        if(s[i]==0){
            printf("%d\n",n);
            exit (0) ;
        } 
    }
    
    int i=0,j=0,tmp=0,ans=0;
    long long sum=1;
    while(i<n && j<n){
        if (sum*s[j]<=k){
            sum*=s[j];
            j++;
            tmp++;
            if (tmp>ans){
                ans=tmp;
            }
        } else {
            if (sum!=1){
                sum/=s[i];
            }
            i++;
            tmp--;
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&s[i]);
         ^