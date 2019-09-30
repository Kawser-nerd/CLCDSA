#include<stdio.h>
#include<string.h>

int main(){
  int tot,len,k,j;
  char num[20];
  scanf("%d",&tot);
  for(int i = 1;i<=tot;i++){
    scanf("%s",num);
    len = strlen(num);
    for(j = 0;j<len-1;j++){
      if(num[j]>num[j+1]){
        for(k = j+1;k<len;k++)
          num[k] = '9';
        for(k = j;k>0;k--){
          if(num[k]!=num[k-1]){
            num[k]--;
            break;
          }
          else
            num[k] = '9';
        }
        if(k==0)
          num[0]--;
        if(num[0]=='0')
          printf("Case #%d: %s\n",i,&(num[1]));
        else
          printf("Case #%d: %s\n",i,num);
        break;
      }
    }
    if(j==len-1)
      printf("Case #%d: %s\n",i,num);
  }
  return 0;
}
