#include <stdio.h>
int main (){
int k,han=0,i,j;
  scanf ("%d",&k);
  char s[100][11];
  scanf ("%s",s[0]);
  for (i=1;i<k;i++){
    scanf ("%s",s[i]);
  if (s[i-1][strlen(s[i-1])-1]==s[i][0]){
  }
    else{
    han=han+1;
      break;
    }
    for (j=0;j<i;j++){
  if(strcmp(s[i],s[j])==0){
  han=han+1;
    break;
  }
    }
  
  }  
  
  if (han==0){
printf ("Yes");
  }
  else{
printf("No");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:14: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   if (s[i-1][strlen(s[i-1])-1]==s[i][0]){
              ^
./Main.c:9:14: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:9:14: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:16:6: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
   if(strcmp(s[i],s[j])==0){
      ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&k);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s",s[0]);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%s",s[i]);
     ^