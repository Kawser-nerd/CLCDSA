#include <stdio.h>
#include <string.h>

int main(){
  int n;
  scanf("%d", &n);
  char s[n][11];
  int i;
  for(i=0;i<n;i++){
    scanf("%s", s[i]);
  }
  int m;
  scanf("%d", &m);
  char t[m][11];
  for(i=0;i<m;i++){
    scanf("%s", t[i]);
  }
  int ans = 0;
  int flag[n];
  for(i=0;i<n;i++){
    flag[i] = 0;
  }
  for(i=0;i<n;i++){
    if(flag[i]==0){
      flag[i] = 1;
      int tmp_ans = 1;
      int j;
      for(j=i+1;j<n;j++){
        if(strcmp(s[i],s[j]) == 0){
          flag[j] = 1;
          tmp_ans++;
        }
      }
      for(j=0;j<m;j++){
        if(strcmp(s[i],t[j]) == 0){
          tmp_ans--;
        }
      }
      if(tmp_ans > ans){
        ans = tmp_ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &m);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", t[i]);
     ^