#include<stdio.h>
#include<math.h>
int main (){
char s[9]={0};
int shu=0,wa=0,ji[8]={0},i,j;
  scanf ("%s",s);
  for (i=0;i<strlen(s);i++){
   ji[i]= s[i]-'0';
  }
for (i=0;i<strlen(s);i++){
wa=wa+ji[i];
shu=shu+(ji[i]*pow(10,strlen(s)-i-1));
}


  if (shu%wa == 0){
  printf ("Yes");
  }
    else{
    printf ("No");
    }
   return 0; 
  } ./Main.c: In function ‘main’:
./Main.c:7:14: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   for (i=0;i<strlen(s);i++){
              ^
./Main.c:7:14: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:7:14: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:10:12: warning: incompatible implicit declaration of built-in function ‘strlen’
 for (i=0;i<strlen(s);i++){
            ^
./Main.c:10:12: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s",s);
   ^