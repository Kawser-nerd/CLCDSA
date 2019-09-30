#include <stdio.h>
int z[9999],r[9999];
int f(int a,int b){
	fflush(!printf("? %d %d\n",a,b));
	char c[2];
	scanf("%s",c);
	return*c=='Y';
}
int main(){
	int a,b,c=0,h,i;
	if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return 0;}
	for(i=a+=b;~--i;)!c||f(i,z[c-1])?(z[c++]=i):c--;
	for(h=*z,i=a;~--i;)r[i]=f(h,i);
	for(printf("! "),i=0;i<a;)printf("%d",r[i++]);
	puts("");
} ./Main.c: In function ‘f’:
./Main.c:4:9: warning: passing argument 1 of ‘fflush’ makes pointer from integer without a cast [-Wint-conversion]
  fflush(!printf("? %d %d\n",a,b));
         ^
In file included from ./Main.c:1:0:
/usr/include/stdio.h:242:12: note: expected ‘FILE * {aka struct _IO_FILE *}’ but argument is of type ‘int’
 extern int fflush (FILE *__stream);
            ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",c);
  ^
./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return 0;}
     ^