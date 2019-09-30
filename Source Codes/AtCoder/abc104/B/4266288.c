#include<stdio.h>
#include<string.h>

int main(){
  char str[100];
  int i,j,k=0;
  
  scanf("%s",str);
  
  if(str[0] != 'A'){
    puts("WA");
    return 0;
  }
  
  if(!(str[1]>=97&&str[1]<=122)){
    puts("WA");
    return 0;
  }
  
  for(i=2;i<strlen(str)-1;i++){
    if(str[i] == 'C'){
      k++;
      continue;
    }
    if(!(str[i]>=97&&str[i]<=122)){
      puts("WA");
      return 0;
    }
  }
  
  for(i=strlen(str)-1;i < strlen(str);i++){
    if(!(str[i]>=97&&str[i]<=122)){
    puts("WA");
    return 0;
  }
  }
  
  if(k == 1){
    puts("AC");
    return 0;
  }
  
  puts("WA");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^