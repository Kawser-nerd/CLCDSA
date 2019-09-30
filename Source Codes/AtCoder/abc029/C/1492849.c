#include <stdio.h>                                                                                                                                                                                        
#include <stdlib.h>                                                                                                                                                                                       
#include <string.h>                                                                                                                                                                                       
                                                                                                                                                                                                          
int len;                                                                                                                                                                                                  
char *ans;                                                                                                                                                                                                
char str[] = "abc";                                                                                                                                                                                       
                                                                                                                                                                                                          
void dfs(int i)                                                                                                                                                                                           
{                                                                                                                                                                                                          
        int j;                                                                                                                                                                                            
                                                                                                                                                                                                          
        if (i == len) {                                                                                                                                                                                   
                printf("%s\n", ans);                                                                                                                                                                      
                return;                                                                                                                                                                                   
        }                                                                                                                                                                                                 
                                                                                                                                                                                                          
        for (j = 0; j < 3; j++) {                                                                                                                                                                         
                ans[i] = str[j];                                                                                                                                                                          
                dfs(i + 1);                                                                                                                                                                               
        }                                                                                                                                                                                                 
        return;                                                                                                                                                                                           
}                                                                                                                                                                                                         
                                                                                                                                                                                                          
int main(void)                                                                                                                                                                                            
{                                                                                                                                                                                                         
        scanf("%d", &len);                                                                                                                                                                                
        ans = calloc(1, len + 1);                                                                                                                                                                         
        dfs(0);                                                                                                                                                                                           
        free(ans);                                                                                                                                                                                        
        return 0;                                                                                                                                                                                         
} ./Main.c: In function ‘main’:
./Main.c:27:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &len);                                                                                                                                                                                
         ^