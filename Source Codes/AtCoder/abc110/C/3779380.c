#include <stdio.h>
#include <string.h>
/*
S??T????????????????
??{'a','b',...,'z'}????R?????????i????
  R(S_{i}) = T_{i}
???????????
*/

int main(){
  char S[200010] = {};
  char T[200010] = {};
  char R1[30] = {};//S??T????
  char R2[30] = {};//T??S????
  scanf("%s %s", S, T);
  int l = strlen(S);

  int flag = 1;
  for(int i = 0; i < l; i++){

    if(R1[S[i] - 'a'] == 0){
      R1[S[i] - 'a'] = T[i];
    }else if(R1[S[i] - 'a'] != T[i]){
      flag = 0;
      break;
    }

    if(R2[T[i] - 'a'] == 0){
      R2[T[i] - 'a'] = S[i];
    }else if(R2[T[i] - 'a'] != S[i]){
      flag = 0;
      break;
    }

  }
  if(flag == 1){
    printf("Yes\n");
  }else{
    printf("No\n");
  }


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s", S, T);
   ^