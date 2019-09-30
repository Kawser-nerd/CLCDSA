#include<stdio.h>
#include<string.h>

int main(){
  char x[51];
  for(int i=0;i<51;i++){
    scanf("%s",&x[i]);
  }
  int len=strlen(x);
  for(int i=0;i<len;i++){
    if(x[i]=='o'||x[i]=='k'||x[i]=='u'){
    }else{
      if(x[i]=='c'&&x[i+1]=='h'){
      }else{
        if(x[i]=='h'&&x[i-1]=='c'){
        }else{
          printf("NO\n");
          return 0;
        }
      }
    }
  }
  printf("YES\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&x[i]);
     ^