#include <stdio.h>                                                                    
#include <stdlib.h>                                                                   
#include <string.h>                                                                   
                                                                                      
int num;                                                                              
int choise;                                                                           
int **list;                                                                           
                                                                                      
int dfs(int n, int value)                                                             
{                                                                                     
        int i;                                                                        
                                                                                      
        if (n == num) {                                                               
                return value == 0 ? 1 : 0;                                            
        }                                                                             
        for (i = 0; i < choise; i++) {                                                
                if (dfs(n + 1, value ^ list[n][i])) {                                 
                        return 1;                                                                            
                }                                                                                            
        }                                                                                                    
        return 0;                                                                                            
}                                                                                                            
                                                                                                             
int main(void)                                                                                               
{                                                                                                            
        int i, j, ret;                                                                                       
                                                                                                             
        scanf("%d %d", &num, &choise);                                                                       
                                                                                                             
        if ((list = calloc(sizeof(int *), num)) == NULL) {                                                   
                return -1;                                                                                   
        }                                                                                                     
        for (i = 0; i < num; i++) {                                                                          
                if ((list[i] = calloc(sizeof(int), choise)) == NULL) {                                       
                        return -1;                                                    
                }                                                                     
                for (j = 0; j < choise; j++) {                                                               
                        scanf("%d", &list[i][j]);                                     
                }                                                                                             
        }                                                                                                     
                                                                                      
        ret = dfs(0, 0);                                                                                      
                                                                                                              
/*                                                                                                            
        for (i = 0; i < choise; i++) {                                                                        
                for (j = 0; j < choise; j++) {                                                                
                        for (k = 0; k < choise; k++) {                                                        
                                if (((list[0][i] ^ list[1][j]) ^ list[2][k]) == 0) {                                          printf("Found\n");
                                        return 0;                                     
                                }                                                     
                        }                                                             
                }                                                                     
        }                                                                             
*/                                                                                    
        if (ret == 0) {
                printf("Nothing\n");
        } else {                                                                      
                printf("Found\n");
        }                                                                             
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &num, &choise);                                                                       
         ^
./Main.c:38:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                         scanf("%d", &list[i][j]);                                     
                         ^