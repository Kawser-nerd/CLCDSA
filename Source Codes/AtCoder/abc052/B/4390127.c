#include <stdio.h>
int main(){
int k,i,max=0,a=0;
scanf ("%d",&k);
char s[100];
scanf ("%s",s);
for (i=0;i<k;i++){
if (s[i]=='I'){
a++;
}
else if (s[i]=='D'){
a--;
}
if (max<a){
max=a;
}
}
  printf ("%d",max);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&k);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%s",s);
 ^