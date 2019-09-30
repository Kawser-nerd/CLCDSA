#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define min(a,b) ((a)<(b)?(a):(b))
//#define abs(a) ((a)>(0)?(a):-(a))
int check(long int x){
  char num[12];
  int a=0,b=0,c=0,i;//3,5,7
  sprintf(num,"%ld",x);
  for(i=0;i<strlen(num);i++){
    if(num[i]=='3')a++;
    else if(num[i]=='5')b++;
    else if(num[i]=='7')c++;
  }
  if(a>0&&b>0&&c>0) return 1;
  else return 0;
}
void dfs(long int x,long int n,int *ans){
  if(x<=n){
    *ans+=check(x);
    dfs(10*x+3,n,ans);
    dfs(10*x+5,n,ans);
    dfs(10*x+7,n,ans);
  }
}
int main(){
  long int n;
  int ans=0;
  scanf("%ld",&n);
  dfs(0,n,&ans);
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^