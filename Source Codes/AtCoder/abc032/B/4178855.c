#include<stdio.h>
#include<string.h>

int max = 0;
char list[300][300];

int check(char *s){
  int i;
  for (i = 0; i < max; i++){
    if(strcmp(s, list[i]) == 0){
      break;
    }
  }
  if(i == max){
    max++;
    strcpy(list[i], s);
    return 1;
  }
  return 0;
}

int main(){
  int k, len = 0, count = 0, i , j;
  char s1[300], s2[300];
  
  scanf("%s", s1);
  scanf("%d", &k);
  
  while(s1[len]){
    len++;
  }
  for (i = 0; i <= len - k; i++){
    for(j = 0; j < k; j++){
      s2[j] = s1[i + j];
    }
    s2[j + 1] = '\0';
    if(check(s2) == 1){
      count++;
    }
  }
  
  printf("%d\n", count);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s1);
   ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &k);
   ^