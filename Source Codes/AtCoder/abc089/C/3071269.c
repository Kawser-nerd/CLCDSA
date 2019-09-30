#include<stdio.h>
int main(){
  int n,i;
  long long int ans=0,m=0,a=0,r=0,c=0,h=0;
  char s[11];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",s);
    switch(s[0]){
    case 'M' : m++; break;
    case 'A' : a++; break;
    case 'R' : r++; break;
    case 'C' : c++; break;
    case 'H' : h++; break;
    }
  }
  ans+= m*a*r;  ans+= m*a*c;  ans+= m*a*h;  ans+= m*r*h;
  ans+= m*c*h;  ans+= a*r*c;  ans+= a*r*h;  ans+= a*c*h;
  ans+= r*c*h;  ans+= m*r*c;
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^