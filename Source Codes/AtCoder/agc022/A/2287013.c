#include<stdio.h>
#include<string.h>

int main(){
  int i,flag[26]={},j,flag1=0,k;
  char s[26],ss[26];
  scanf("%s",s);
  for(i=0;i<strlen(s);i++){
    flag[s[i]-'a']=1;
  }
  if(strlen(s)!=26){
    for(i=0;i<26;i++){
      if(!flag[i]){
        printf("%s%c\n",s,i+'a');
        break;
      }
    }
  }
  else{
    for(i=0;i<strlen(s);i++){
      flag[s[i]-'a']=i;
    }
    for(i=24;i>=0;i--){
      for(k=s[i]-'a'+1;k<26;k++){
        if(flag[k]>=i){
          for(j=0;j<i;j++) printf("%c",s[j]);
          printf("%c\n",k+'a');
          flag1=1;
          break;
        }
      if(flag1) break;
      }
if(flag1) break;

    }
    if(!flag1) printf("-1\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^