#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define ll long long
#define MAX_VALUE 1000000000
#define MAX 100000

int main(void){
 int n;
 scanf("%d",&n);
 int a[200001];
 int i,j;
 for(i=0;i<n;i++){
  scanf("%d",&a[i]);
 }
 
 for(i=n-1;i>=0;i-=2)
  printf("%d ",a[i]);
 if(n%2==0){
 for(i=0;i<n;i+=2)
  printf("%d ",a[i]);
 }else{
 for(i=1;i<n;i+=2)
  printf("%d ",a[i]);
 }
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^