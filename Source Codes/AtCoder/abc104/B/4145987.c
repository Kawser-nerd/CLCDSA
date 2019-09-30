#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int min(int a,int b){
  if(a<=b) return a;
  else return b;
}
int max(int a,int b){
  if(a>=b) return a;
  else return b;
}

int main(){
  char s[11];
  int flag = 0;int count = 0;int k=0;
  scanf("%s",s);
  while(s[k] != '\0')k++;
  if(s[0] != 'A')flag = 1;
  for(int i=2;i<k-1;i++){
    if(s[i] == 'C')count ++;
  }
  if(count != 1)flag = 1;
  count = 0;
  for(int i=0;i<k;i++){
    if(s[i] >= 'A' && s[i]<= 'Z')count++;
  }
  if(count != 2)flag = 1;
  if(flag == 1)printf("WA");
  else printf("AC");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^