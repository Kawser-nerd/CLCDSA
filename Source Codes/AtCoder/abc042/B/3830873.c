#include<stdio.h>

int l;
int han(char* a,char* b){
  int i;
  for(i=0;i<l;i++){
    if(a[i]>b[i])return -1;
    if(a[i]<b[i])return 1;
  }
  return 0;
}

int main(){
  int n,j,i;scanf("%d%d",&n,&l);
  char s[100][101];
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  int ans[100];
  for(i=0;i<n;i++)ans[i]=i;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(han(s[ans[i]],s[ans[j]])==1){
        int tmp=ans[i];
        ans[i]=ans[j];
        ans[j]=tmp;
      }
    }
  }
  for(i=0;i<n;i++)printf("%s",s[ans[i]]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   int n,j,i;scanf("%d%d",&n,&l);
             ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^