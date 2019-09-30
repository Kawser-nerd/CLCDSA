#include <stdio.h>
#include <string.h>

int main()
{
  char w[100];
  scanf("%s", w);
  
  if(strlen(w) % 2 != 0){
    printf("No\n"); 
    return 0;
  }

  int hist[32] = {};
  for(int j=0; w[j] != '\0'; j++){
    for(int i=0; i<32; i++){
      if(w[j] == 'a' + i)
        hist[i]++;
    }
  }
  for(int i=0; i<32; i++){
    if(hist[i] % 2 != 0){
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", w);
   ^