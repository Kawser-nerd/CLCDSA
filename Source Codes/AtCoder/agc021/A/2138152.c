#include<stdio.h>
int main(){
int i,j,k,x,y,z,flag=0;
char s[100];
scanf("%s",s);
for(i=1;s[i]!='\0';i++)
if(s[i]!='9')
{
flag=1;
break;
}
x=0;
y=strlen(s);
if(flag==1)
x=s[0]-48+9*(y-1)-1;
else
x=s[0]-48+9*(y-1);
printf("%d",x);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 y=strlen(s);
   ^
./Main.c:13:3: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:13:3: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",s);
 ^