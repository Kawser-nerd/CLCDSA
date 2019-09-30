#include<stdio.h>
int n, ans, h;
int abs(int a);
int main(){
  scanf("%d", &n);
  ans=n;
  for(h=1; h<=n; h++){
    if(abs(n/h-h)+(n%h) < ans){ans = abs(n/h-h)+(n%h);}
  }
  printf("%d\n", ans);
}
int abs(int a){
  return a<0?-a:a;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^