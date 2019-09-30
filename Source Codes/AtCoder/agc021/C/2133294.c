#include <stdio.h>

p[2<<19],a,b,m,i,j;

x(i,j){if(a)p[i]=60,p[i+1]=62,a--;}
y(i,j){if(b)p[i]=94,p[i+m]=118,b--;}
#define c for(i=n%2;i<n;i+=2)
#define d for(j=m%2;j<m;j+=2)
#define o i*m+j

main(n) {
	scanf("%d%d%d%d",&n,&m,&a,&b);

	if(n&1)d x(j);
	if(m&1)c y(i*m);
	if(n>2&m>2&n&m&a&a>0&b>0)a++,x(0),x(2*m+1),y(2);
	c d if(p[o+1]);else if(a)x(o),x(o+m);else y(o),y(o+1);

	if(a|b)puts("NO");
	else{
		puts("YES");
		for(i=0;i<n;puts(""),i++)
			for(j=0;j<m;)putchar(p[o++]?:46);
	}
} ./Main.c:3:1: warning: data definition has no type or storage class
 p[2<<19],a,b,m,i,j;
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:3:10: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 p[2<<19],a,b,m,i,j;
          ^
./Main.c:3:12: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 p[2<<19],a,b,m,i,j;
            ^
./Main.c:3:14: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 p[2<<19],a,b,m,i,j;
              ^
./Main.c:3:16: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 p[2<<19],a,b,m,i,j;
                ^
./Main.c:3:18: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 p[2<<19],a,b,m,i,j;
                  ^
./Main.c:5:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 x(i,j){if(a)p[i]=60,p[i+1]=62,a--;}
 ^
./Main.c: In function ‘x’:
./Main.c:5:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:5:1: warn...