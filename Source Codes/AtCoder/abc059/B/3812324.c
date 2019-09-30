#include<stdio.h>
int A, B, i;
char c, a[102], b[102];
int main(){
  c=getchar();
  while(c!=10){
    a[A]=c;
    c=getchar(); A++;
  }
  c=getchar();
  while(c!=10){
    b[B]=c;
    c=getchar(); B++;
  }
  if(A>B){
    printf("GREATER\n");
    return 0;
  }else if(A<B){
    printf("LESS\n");
    return 0;
  }
  for(i=0; i<A; i++){
    if(a[i]>b[i]){
      printf("GREATER\n");
      return 0;
    }else if(a[i]<b[i]){
      printf("LESS\n");
      return 0;
    }
  }
  printf("EQUAL\n");
}