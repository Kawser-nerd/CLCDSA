#include<stdio.h>
int sum(n){
  int s=0;
  while(n){
    s+=n%10;
    n/=10;
  }
  return s;
}
int main(n){
  scanf("%d",&n);
  puts(n%sum(n)?"No":"Yes");
} ./Main.c: In function ‘sum’:
./Main.c:2:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 int sum(n){
     ^
./Main.c: In function ‘main’:
./Main.c:10:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 int main(n){
     ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^