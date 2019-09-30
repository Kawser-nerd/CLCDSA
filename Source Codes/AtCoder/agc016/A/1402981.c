#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
char s[100];
char orgS[100];

int shim(char x){
  int ans = 101;
  int L = strlen(s);
  int check=0;
  for (int i=1;i<strlen(s);i++){
    if (s[0] !=s[i]){
      check = 1;
      break;
    }
  }if (check == 0)return 0;
  for (int i=0;i<100;i++){
    if (check == 0){
      ans = i;
      break;
    }
    check = 0;
    for (int j=0;j<L-1;j++){
      if (s[j+1] == x)s[j] = s[j+1];
      if (s[j+1] != x&&s[j] !=x){
        check++;
      }
    }
    L--;
  }
  for (int i=0;i<100;i++){
    s[i]=orgS[i];
  }
  return ans;
}


int main(){
  scanf("%s",s);
  for (int i=0;i<100;i++){
    orgS[i] = s[i];
  }
  int best = 101;
  for (char x = 'a';x <= 'z';x++){
    if (best > shim(x))best = shim(x);
  }
  printf("%d\n",best);
} ./Main.c: In function ‘main’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^