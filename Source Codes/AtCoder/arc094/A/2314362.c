#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int a,b,c,ans=0,max;
  scanf("%d %d %d",&a,&b,&c);
  if(a%2==b%2&&b%2-c%2){
    a++;
    b++;
    ans++;
  }
  else if(a%2==c%2&&a%2-b%2){
    a++;
    c++;
    ans++;
  }
  else if(b%2==c%2&&a%2-b%2){
    b++;
    c++;
    ans++;
  }
  max=MAX(a,MAX(b,c));
  ans+=(max-a)/2;
  ans+=(max-b)/2;
  ans+=(max-c)/2;
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^