#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define ll long long
#define MAX 200000000000
#define MOD 1000000007
ll int bin(ll int);

int main(void){
ll int N,A,B,C,D;
 scanf("%lld%lld%lld%lld%lld",&N,&A,&B,&C,&D);
 ll int b,u,h;
 if(B>A){
 h=B-A;
 }else{
 h=A-B;
 }
 
 int f=0;
 int i;
 if(f==0)
 for(i=N-1;i>=0;i--){
  if(C*i-D*(N-1-i)<=h&&h<=D*i-C*(N-1-i)) f=1;
 }
 
 if(f==1){
  printf("YES\n");
 }else{
  printf("NO\n");
 }
 
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld",&N,&A,&B,&C,&D);
  ^