#include<stdio.h>
#include<string.h>
 
int main(void) {
  int i, j, k;
  int N;
  
  scanf("%d", &N);
  char str[N][11];
  
  for(i=0; i<N; i++){
    scanf("%s", str[i]);
    for(j=0; j<i; j++){
      if(strcmp(str[j], str[i])==0){
        puts("No");
        return 0;
      }
      if(j == i-1){
        if(str[j][strlen(str[j])-1] != str[i][0]){
          puts("No");
          return 0;
        }
      }
    }
  }
    puts("Yes");
    
    return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", str[i]);
     ^