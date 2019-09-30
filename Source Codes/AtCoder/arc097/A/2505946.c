#include<stdio.h>
#include<string.h>

int main(){
  int i,k,m,j,l,cnt=0,flag=1;
  char s[5000],ss[25000][6],sss[5][5];
  scanf("%s",s);
  scanf("%d",&k);
  for(i=1;i<=k;i++){
    for(j=0;j<strlen(s)-i+1;j++){
      for(l=0;l<i;l++){
        ss[cnt][l]=s[j+l];
      }
      cnt++;
    }
  }

  for(i=0;i<k;i++){
    strcpy(sss[i],"zzzzz");
    for(j=0;j<cnt;j++){
      if(strcmp(sss[i],ss[j])>0){
        flag=1;
        for(l=0;l<i;l++){
          if(strcmp(ss[j],sss[l])==0)flag=0;
        }
        if(flag) strcpy(sss[i],ss[j]);
      }
    }
  }
  printf("%s\n",sss[k-1]);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^