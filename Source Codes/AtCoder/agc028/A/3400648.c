#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int euc(int a,int b){
    int tmp;
     if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 int r;
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  
  return b;

}

int main()
{
    long long a,b,n,m,k,i=1,j,l,ans=-1;
    char s[100001],t[100001];
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    scanf("%s",t);
    k=euc(n,m);
    ans=n/k*m;
    for(i=0;i<k;i++){
        if(s[n*i/k]!=t[m*i/k]){
            ans=-1;
        }
    }
       printf("%lld",ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%d%d",&n,&m);
           ^
./Main.c:28:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t);
     ^