#include<stdio.h>
#include<string.h>

int main(){
  int tot,len,flipper,max,cnt,j;
  char pan[1004];
  scanf("%d",&tot);
  for(int i = 1;i<=tot;i++){
    scanf("%s",pan);
    len = strlen(pan);
    scanf("%d",&flipper);
    max = len-flipper+1;
    cnt = 0;
    for(j = 0;j<max;j++){
      if(pan[j]=='-'){
        for(int k = 0;k<flipper;k++){
          if(pan[j+k]=='-')
            pan[j+k] = '+';
          else
            pan[j+k] = '-';
        }
        cnt++;
      }
    }
    for(j = max;j<len;j++)
      if(pan[j]=='-')
        break;
    if(j==len)
      printf("Case #%d: %d\n",i,cnt);
    else
      printf("Case #%d: IMPOSSIBLE\n",i);
  }
  return 0;
}
