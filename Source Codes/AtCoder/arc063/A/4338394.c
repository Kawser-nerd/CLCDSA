#include<stdio.h>
#include<string.h>
int main()
{
int n=0,i,N;
char a[200000];
scanf("%s",&a);
N=strlen(a);

for(i=0;i<N-1;i++)
{
if(a[i]!=a[i+1])          //??????????
n++;
}

printf("%d",n);


return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:7: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[200000]’ [-Wformat=]
 scanf("%s",&a);
       ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",&a);
 ^