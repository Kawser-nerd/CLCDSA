#include <stdio.h>
#include <stdlib.h>
int main(){
int b,k,i,d=1000,x,y,z;
char a[11];
scanf ("%s ",a);
for(i=0;i< strlen(a)-2 ;i++)
{
x=a[i]-'0';
y=a[i+1]-'0';
z=a[i+2]-'0';
b=(100*x)+(10*y)+z;
if(d>abs(b-753)){
	d=abs(b-753);
	}
}
	printf ("%d",d);
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:7:12: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 for(i=0;i< strlen(a)-2 ;i++)
            ^
./Main.c:7:12: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:7:12: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%s ",a);
 ^