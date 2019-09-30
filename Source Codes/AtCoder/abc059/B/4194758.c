#include<stdio.h>
#include<string.h>

int main(){
  int len1 = 0, len2 = 0;
  char s1[101], s2[101];
  
  scanf("%s %s", s1, s2);
  
  while(s1[len1]){
    len1++;
  }
  while(s2[len2]){
    len2++;
  }
  if(len1 > len2 || (len1 == len2 && strcmp(s1, s2) > 0)){
    printf("GREATER\n");
  } else if(strcmp(s1, s2) == 0){
    printf("EQUAL\n");
  } else {
    printf("LESS\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s", s1, s2);
   ^