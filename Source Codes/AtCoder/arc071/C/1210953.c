#include<stdio.h>
int main(){
  char s[100010],w[100010];
  int i,j,n,a,b,c[100010]={};
  int d[100010]={};
  scanf("%s %s",s,w);
  for(i=0;s[i];i++){
    if(s[i]=='A')d[i+1]=1;
    else         d[i+1]=2;
    d[i+1]+=d[i];
  }
  for(i=0;w[i];i++){
    if(w[i]=='A')c[i+1]=1;
    else         c[i+1]=2;
    c[i+1]+=c[i];
  }
  scanf("%d",&n);
  while(n--){
    scanf("%d %d %d %d",&i,&j,&a,&b);
    if((d[j]-d[i-1])%3==(c[b]-c[a-1])%3)printf("YES\n");
    else                                    printf("NO\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",s,w);
   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&i,&j,&a,&b);
     ^