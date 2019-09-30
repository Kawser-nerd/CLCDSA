#include <stdio.h>
     
    int n,tmp,ans=10000 ;
     
    int main(void){
        
        scanf ("%d",&n) ;
        
        for (int i=0; i<=n; i++) {
            
            tmp = 0 ;
            int j = i ;
            int k = n-j ;
            
            while (j>=1) {
                
                tmp += j%6 ;
                j /= 6 ;
                
            }    
            
            while (k>=1) {
                
                tmp += k%9 ;
                k /= 9 ;
                
            }
            
            if (ans>tmp) {
                
                ans = tmp ;
                
            }
            
        }
     
        printf ("%d\n",ans) ;
        
        return 0 ;
        
    } ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf ("%d",&n) ;
         ^