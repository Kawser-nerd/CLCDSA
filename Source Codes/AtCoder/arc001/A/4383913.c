#include <stdio.h>
int main (){
char s[101]={0};
  int a,i,min=1000,max=0,b[5]={0};
scanf (" %d ",&a);
scanf (" %s ",s);
for (i=0;i<a;i++){
if (s[i] == '1'){
b[0]++;
}
else if (s[i] == '2'){
b[1]++;
}
else if (s[i] == '3'){
b[2]++;
}
else {
b[3]++;
}
}
for (i=0;i<4;i++){
if (max < b[i]){
max=b[i];
}
  if (min>b[i]){
  min=b[i];
  }
}
  printf ("%d %d\n",max,min);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf (" %d ",&a);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf (" %s ",s);
 ^