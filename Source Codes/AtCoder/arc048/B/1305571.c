#include<stdio.h>
int main(){
  int n,a[100010],b[100010],i,j;
  int s[100010],r[100010][4]={};
  scanf("%d",&n);
  for(i=s[0]=0;i<n;i++){
    scanf("%d %d",&a[i],&b[i]);
    r[a[i]][b[i]]++;
  }
  for(i=0;i<100005;i++)s[i+1]=s[i]+r[i][1]+r[i][2]+r[i][3];
  for(i=0;i<n;i++){
    j=s[a[i]]+r[a[i]][b[i]%3+1];
    printf("%d %d %d\n",j,n-j-r[a[i]][b[i]],r[a[i]][b[i]]-1);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i],&b[i]);
     ^