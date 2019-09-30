#include<stdio.h>
int i = 0; char list[26];
 
int check(char s){
  int j;
  for (j = 0; j < i; j++){
    if(list[j] == s){
      return j;
    }
  }
  list[i++] = s;
  return i - 1;
}
 
int main(){
  char w[101];
  int len = 0, flag = 1, count[26] = {0}, j;
  scanf("%s", w);
  while(w[len]){
    count[check(w[len])]++;
    len++;
  }
  
  for (j = 0; j < i; j++){
    if(count[j]%2 == 1){
      flag = 0;
      break;
    }
  }
  
  if(flag == 1){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", w);
   ^