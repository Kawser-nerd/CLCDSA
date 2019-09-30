#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,D,E,x,y,cou=0,v[3];
    char S[10],X,Y;
    scanf("%c %c",&X,&Y);
   if(X=='A'){
       x=10;
   }else if(X=='B'){
       x=11;
   }else if(X=='C'){
       x=12;
   }else if(X=='D'){
       x=13;
   }else if(X=='E'){
       x=14;
   }else if(X=='F'){
       x=15;
   }
   if(Y=='A'){
       y=10;
   }else if(Y=='B'){
       y=11;
   }else if(Y=='C'){
       y=12;
   }else if(Y=='D'){
       y=13;
   }else if(Y=='E'){
       y=14;
   }else if(Y=='F'){
       y=15;
   }
   if(x>y){
       printf(">");
   }else if(x==y){
       printf("=");
   }else{
       printf("<");
   }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c %c",&X,&Y);
     ^