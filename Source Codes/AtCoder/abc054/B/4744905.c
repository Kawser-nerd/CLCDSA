#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  int n, m,i,j,k,l;
  scanf("%d%d",&n,&m);
  char a[55][55],b[55][55];
  for(i=0;i<n;i++){
    scanf("%s",a[i]);
  }
  for(i=0;i<m;i++){
    scanf("%s",b[i]);
  }
  for(i=0;i<n-m+1;i++){
    for(j=0;j<n-m+1;j++){
      int t=1;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l])t=0;
        }
      }
      if(t){
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a[i]);
     ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",b[i]);
     ^