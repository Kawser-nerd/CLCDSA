#include<stdio.h>
#include<string.h>

int flag[10];

long calc(char s[11],int p,long a,int n){
  if(p==n-1)
    return a*10+s[p]-'0';
  if(flag[p])
    return a*10+s[p]-'0'+calc(s,p+1,0,n);
  else
    return calc(s,p+1,10*a+s[p]-'0',n);
}
long dfs(char s[11],int n,int m){
  long ans=0;
  if(n-m>1){
    flag[m]=0;
    ans=dfs(s,n,m+1);
    flag[m]=1;
    ans+=dfs(s,n,m+1);
  }
  else
    ans=calc(s,0,0,n);
  return ans;
}

int main(){
  char s[11];
  int n;
  scanf("%s",s);
  n=strlen(s);
  printf("%ld\n",dfs(s,n,0));
} ./Main.c: In function ‘main’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^