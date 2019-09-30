#include<stdio.h>


int main()
{
int n;
int x=0;
int y=0;
char a[100];
scanf("%d",&n);
scanf("%s",a);
for(int i=0;i<n;i++){
if(a[i]=='('){
x++;
}else{
y++;
if(x>=1){
x--;
y--;
}
}
}
for(int i=0;i<y;i++){
printf("(");
}
printf("%s",a);
for(int i=0;i<x;i++){
printf(")");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&n);
 ^
./Main.c:11:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",a);
 ^