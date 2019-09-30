#include<stdio.h>

int main(void){
  char s[3];
  int i,cnta=0,cntb=0,cntc=0;
  
  for(i=0;i<3;i++){
    s[i] = getchar();
    if(s[i]=='a') cnta++;
    else if(s[i]=='b') cntb++;
    else if(s[i]=='c') cntc++;
  }
  
  if((cnta==1) && (cntb==1) && (cntc==1)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}