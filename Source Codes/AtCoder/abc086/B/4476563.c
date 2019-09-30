#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int c;
	char a[3];
	char b[3];
	char str[9];
scanf("%s",a);
scanf("%s",b);
sprintf(str,"%s%s",a,b);
int d=atoi(str);
c=sqrt(d);
if(c*c==d){
	printf("Yes");
}else{
	printf("No");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",a);
 ^
./Main.c:12:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",b);
 ^