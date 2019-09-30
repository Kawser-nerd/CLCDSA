#include<stdio.h>
 
int main()
{
  char A[11],B[11],C[11];
  int a,b,i;
  
  scanf("%s%s%s",A,B,C);
  
  for(i=1;i<11;i++){
	if(A[i]=='\0'){
      a=i-1;
      break;
    }
  }
    
  for(i=1;i<11;i++){
    if(B[i]=='\0'){
      b=i-1;
      break;
    }
  }
  
  /*printf("%d\n%d\n",a,b);*/
  
  if(A[a]==B[0]&&B[b]==C[0]){
      printf("YES");
  }else{
    printf("NO");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s%s",A,B,C);
   ^