#include<stdio.h>
#include<string.h>

int main(){
  char a[1010];
  scanf("%s",a);
  int i;
//  for(i=0;i<strlen(a);i++){
//  printf("%c",a[i]);
//}
//  printf("%d\n", strlen(a),i); 
  char last = a[0];
  int length = 1;
  
  for(i=1;i<strlen(a);i++){
   if(a[i]!=last){
    printf("%c%d",last,length);
   	 last=a[i];
     length=1;
   }else{
     length++; 
   }
  }
   printf("%c%d\n",last,length);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^