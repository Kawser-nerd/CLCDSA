#include <stdio.h>
#include <string.h>
int main (){
int i,j,k,a[51]={0},max=0,n=0;
char s[51][51];
scanf ("%d",&k);
  for (i=0;i<k;i++){
  scanf ("%s",s[i]);
  }
  for (i=0;i<k;i++){
  for (j=i+1;j<k;j++){
  if (strcmp(s[i],s[j])==0){
  a[i]++;
      }
  }
  }
 for (i=0;i<k;i++){
 if (max<a[i]){
 max=a[i];
 n=i;
 }
 }
  printf ("%s\n",s[n]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&k);
 ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s",s[i]);
   ^