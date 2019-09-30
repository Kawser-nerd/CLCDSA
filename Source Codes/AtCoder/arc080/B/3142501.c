#include<stdio.h>
#include<string.h>

int main(){
  int h,w,n,a[10000],p=1;
  int c[110][110];
  scanf("%d %d",&h,&w);
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(int i=0;i<h;i++){
    if(i%2==0)
      for(int j=0;j<w;j++){
        if(a[p-1]!=0){
          c[i][j]=p;
          a[p-1]--;
        }
        else{
          p++;
          c[i][j]=p;
          a[p-1]--;
        }
      }
    else{
      for(int j=w-1;j>=0;j--){
        if(a[p-1]!=0){
          c[i][j]=p;
          a[p-1]--;
        }
        else{
          p++;
          c[i][j]=p;
          a[p-1]--;
        }
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      printf("%d ",c[i][j]);
    printf("\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^