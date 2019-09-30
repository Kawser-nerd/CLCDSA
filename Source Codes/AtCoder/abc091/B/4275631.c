#include <stdio.h>
 int main(){
 int n,m,best=0,gain;
 scanf("%d",&n);
 char s[n][10];
 for (int i=0;i<n;i++){
 scanf(" %s",s[i]);
 }
 scanf("%d",&m);
 char t[m][10];
 for (int i=0;i<m;i++){
 scanf(" %s",t[i]);
 }
 for (int i=0;i<n;i++){
 gain=0;
 for (int j=0;j<n;j++){
 if (0==strcmp(s[i],s[j])){
 gain++;
 }
 }
 for (int j=0;j<m;j++){
 if (0==strcmp(s[i],t[j])){
 gain--;
 }
 }
 if (best<gain){
 best=gain;
 }
 }
 printf("%d\n",best);
 return 0;
 } ./Main.c: In function ‘main’:
./Main.c:17:9: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
  if (0==strcmp(s[i],s[j])){
         ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf(" %s",s[i]);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf(" %s",t[i]);
  ^