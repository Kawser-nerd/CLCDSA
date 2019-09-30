#include<stdio.h>
long long MAX(long long a,long long b){return a<b?b:a;}
int main(){
  long long n,m,a,b,i,j,k,l,w,d[4][100],r[4]={1};
  long long max=0,s[4][100]={};
  scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
  d[0][0]=b;
  for(i=1;i<n;i++){
    scanf("%lld %lld",&w,&b);
    w-=a;
    for(j=r[w]++;j&&d[w][j-1]<b;j--)d[w][j]=d[w][j-1];
    d[w][j]=b;
  }
  /*for(i=0;i<4;i++){
    for(j=0;j<r[i];j++)printf("%lld ",d[i][j]);printf("\n");
    }//*/
  for(i=0;i<4;i++){
    for(j=0;j<r[i];j++)s[i][j+1]=d[i][j]+s[i][j];
  }
  /*for(i=0;i<4;i++){
    for(j=0;j<=r[i];j++)printf("%lld ",s[i][j]);printf("\n");
    }//*/
  for(i=0;i<=r[0];i++){
    for(j=0;j<=r[1];j++){
      for(k=0;k<=r[2];k++){
	for(l=0;l<=r[3];l++){
	  if((a+0)*i+(a+1)*j+(a+2)*k+(a+3)*l>m)continue;
	  max=MAX(max,s[0][i]+s[1][j]+s[2][k]+s[3][l]);
	}
      }
    }
  }
  printf("%lld\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&w,&b);
     ^