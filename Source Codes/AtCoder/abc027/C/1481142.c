#include <stdio.h>                                                                          
#include <stdlib.h>                                                                         
                                                                                            
int main(void)                                                                              
{                                                                                           
        long long num, i, depth = 0, ans = 1;                                               
        char winner;                                                                        
                                                                                            
        scanf("%lld", &num);                                                                                                                                                                              
                                                                                                                                                                                                          
        for (i = num; i > 0; i /= 2) {                                                                                                                                                                    
                depth++;                                                                                                                                                                                  
        }                                                                                                                                                                                                 
                                                                                                                                                                                                          
        if (depth % 2 == 0) {                                                                                                                                                                             
                for (i = 0; i < depth - 1; i++) {                                                                                                                                                         
                        ans *= 2;                                                                                                                                                                         
                        if (i % 2 == 1) {                                                                                                                                                                 
                                ans++;                                                                                                                                                                    
                        }                                                                                                                                                                                 
                }                                                                                                                                                                                         
                winner = ans <= num ? 'T' : 'A';                                                                                                                                                          
        } else {                                                                                                                                                                                          
                for (i = 0; i < depth - 1; i++) {                                                                                                                                                         
                        ans *= 2;                                                                                                                                                                         
                        if (i % 2 == 0) {                                                                                                                                                                 
                                ans++;                                                                                                                                                                    
                        }                                                                                                                                                                                 
                }                                                                                                                                                                                         
                winner = ans <= num ? 'A' : 'T';                                                                                                                                                           
        }                                                                                                                                                                                                 
        if (winner == 'T') {                                                                                                                                                                              
                printf("Takahashi\n");                                                                                                                                                                    
        } else {                                                                                                                                                                                          
                printf("Aoki\n");                                                                                                                                                                         
        }                                                                                                                                                                                                 
        return 0;                                                                                                                                                                                         
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &num);                                                                                                                                                                              
         ^