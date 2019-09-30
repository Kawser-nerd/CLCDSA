#include<stdio.h>
int S[26], i;
char c;
int main(){
  c=getchar();
  while(c!=10){
    S[c-'a']++;
    c=getchar();
  }
  for(i=0; i<26; i++){
    if(S[i]==0){break;}
  }
  if(i==26){
    printf("None\n");
  }else{
    printf("%c\n", i+'a');
  }
}