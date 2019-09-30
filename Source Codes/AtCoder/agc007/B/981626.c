#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,a[20010],b[20010],m,s=0,i,max,p[20010];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&m);
    p[m-1]=i+1;
  }
  //for(i=0;i<n;i++)printf("%d ",p[i]);printf("\n");
  for(i=0;i<n;i++){
    b[i]=s+i;
    max=MAX(max,b[i]);
    s+=p[i];
    a[i]=s+i;
  }
  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d",a[i],max+1);
  for(i=1;i<n;i++)printf(" %d",max-b[i]+1);
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^