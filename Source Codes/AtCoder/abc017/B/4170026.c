#include <stdio.h>
#include <string.h>
 
int main(){
    char s[51];
    int i,count=0;

    scanf("%s", s);
  
    for(i = 0; i < strlen(s); i++){
    if(s[i] == 'o' || s[i] == 'k' || s[i] == 'u'){
        }else if(s[i] == 'c'){
            count++;
        }else if(s[i] == 'h' && count == 1){
            count = 0;
        }else{
            printf("NO\n");
            return 0;
        }
    }
  printf("YES\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^