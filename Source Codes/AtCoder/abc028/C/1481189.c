#include <stdio.h>                                                                                                                                                                                        
#include <stdlib.h>                                                                                                                                                                                       
#include <string.h>                                                                                                                                                                                       
#include <limits.h>                                                                                                                                                                                       
                                                                                                                                                                                                          
int cmp(const void *c, const void *d)                                                                                                                                                                     
{                                                                                                                                                                                                         
        int a = *((int *)c);                                                                                                                                                                              
        int b = *((int *)d);                                                                                                                                                                              
                                                                                                                                                                                                          
        if (a < b) {                                                                                                                                                                                      
                return -1;                                                                                                                                                                                
        } else if (a == b) {                                                                                                                                                                              
                return 0;                                                                                                                                                                                 
        } else {                                                                                                                                                                                          
                return 1;                                                                                                                                                                                 
        }                                                                                                                                                                                                  
}                                                                                                                                                                                                         
                                                                                                                                                                                                          
int main(void)                                                                                                                                                                                            
{                                                                                                                                                                                                         
        int org[5], sum[10] = { 0 }, i, j, k, l = 0, min = 0, cnt = 0;                                                                                                                                    
                                                                                                                                                                                                          
        scanf("%d %d %d %d %d", &org[0], &org[1], &org[2], &org[3], &org[4]);                                                                                                                             
            
        for (i = 0; i < 3; i++) {                                                                                                                                                                         
                for (j = i + 1; j < 4; j++) {                                                                                                                                                             
                        for (k = i + 2; k < 5; k++) {                                                                                                                                                     
                                if (i < j && j < k) {                                                                                                                                                     
                                        sum[l++] = org[i] + org[j] + org[k];                                                                                                                              
                                }                                                                                                                                                                         
                        }                                                                                                                                                                                 
                }                                                                                                                                                                                         
        }                                                                                                                                                                                                 
        qsort(sum, 10, sizeof(int), cmp);                                                                                                                                                                 
                                                                                                                                                                                                          
        min = INT_MAX;                                                                                                                                                                                    
        for (i = 9; i >= 0; i--) {                                                                                                                                                                        
                if (min > sum[i]) {                                                                                                                                                                       
                        min = sum[i];                                                                                                                                                                     
                        cnt++;                                                                                                                                                                            
                }                                                                                                                                                                                         
                if (cnt == 3) {                                                                                                                                                                           
                        break;                                                                                                                                                                            
                }                                                                                                                                                                                         
        }                                                                                                                                                                                                 
        printf("%d\n", sum[i]);                                                                                                                                                                           
        return 0;                                                                                                                                                                                         
} ./Main.c: In function ‘main’:
./Main.c:24:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d %d %d", &org[0], &org[1], &org[2], &org[3], &org[4]);                                                                                                                             
         ^