#include <stdio.h>                                                                                                                                                                                          
                                                                                                                                                                                                            
int main(void){                                                                                                                                                                                             
  int n, i, right=0, left=0;                                                                                                                                                                                
  char s[100];                                                                                                                                                                                              
  scanf("%d", &n);                                                                                                                                                                                          
  scanf("%s", s);                                                                                                                                                                                           
  for(i=0; i<n; ++i){                                                                                                                                                                                       
    if(s[i] == '('){                                                                                                                                                                                        
      left += 1;                                                                                                                                                                                            
    } else if(s[i] == ')' && left > 0 ){                                                                                                                                                                    
      left -= 1;                                                                                                                                                                                            
    }else{                                                                                                                                                                                                  
      right += 1;                                                                                                                                                                                           
    }                                                                                                                                                                                                       
  }                                                                                                                                                                                                         
  for(i=0; i<right; ++i){                                                                                                                                                                                   
    printf("(");                                                                                                                                                                                            
  }                                                                                                                                                                                                         
  printf("%s", s);                                                                                                                                                                                          
  for(i=0; i<left; ++i){                                                                                                                                                                                    
    printf(")");                                                                                                                                                                                            
  }                                                                                                                                                                                                         
  return 0;                                                                                                                                                                                                 
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);                                                                                                                                                                                          
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);                                                                                                                                                                                           
   ^