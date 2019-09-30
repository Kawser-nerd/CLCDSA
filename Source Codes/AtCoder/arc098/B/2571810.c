#include<stdio.h>

int main(){
  long n,i,j,a[200000],bit[200010][21]={},left,right,c,cnt=0,flag=1;
  scanf("%ld",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
    for(j=0;j<21;j++){
      bit[i+1][j]=bit[i][j]+a[i]%2;
      a[i]/=2;
    }
  }

  for(i=1;i<=n;i++){
    left=i;
    right=n;
    while(left<=right){//printf("%ld %ld\n",left,right);
      c=(right+left)/2;
      flag=1;
      for(j=0;j<21;j++){
        if(bit[c][j]-bit[i-1][j]>1){
          flag=0;
          break;
        }
      }
      if(flag) left=c+1;
      else right=c-1;
    }

    cnt+=left-i;
  }
  printf("%ld\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i]);
     ^