#include <stdio.h>
int main(){
int ho,a,sum=0,i,j,s[1003];
  scanf ("%d ",&a);
  for(i=0;i<a;i++){
  scanf ("%d ",&s[i]);
  }
  for (i=0;i<a;i++){
  for(j=a-1;j>i;j--){
  if(s[j]<s[j-1]){
  ho=s[j];
  s[j]=s[j-1];
  s[j-1]=ho;
  }
  }
  }
  for (i=a-1;i>-1;i--){
  if((a-i)%2==1){
  sum=sum+(s[i]*s[i]);
  }
  else{
  sum=sum-(s[i]*s[i]);
  }
  }
printf ("%.10f\n",sum*3.141592653589793);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d ",&a);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d ",&s[i]);
   ^