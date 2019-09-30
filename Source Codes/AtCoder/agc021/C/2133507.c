#include <stdio.h>
#define f(c,d)for(c=d%2;c<d;c+=2)
p[2<<19],a,b,m,i,j,o;x(i,j){if(a)p[i]=60,p[i+1]=62,a--;}y(i,j){if(b)p[i]=94,p[i+m]=118,b--;}main(n){scanf("%d%d%d%d",&n,&m,&a,&b);if(n&1)f(j,m)x(j);if(m&1)f(i,n)y(i*m);if(n>2&m>2&n&m&a&a>0&b>0)a++,x(0),x(2*m+1),y(2);f(i,n)f(j,m)if(p[(o=i*m+j)+1]);else if(a)x(o),x(o+m);else y(o),y(o+1);puts(a|b?"NO":"YES");if(!a&!b)for(i=0;i<n*m;++i%m||puts(""))putchar(p[i]?:46);} ./Main.c:3:1: warning: data definition has no type or storage class
 p[2<<19],a,b,m,i,j,o;x(i,j){if(a)p[i]=60,p[i+1]=62,a--;}y(i,j){if(b)p[i]=94,p[i+m]=118,b--;}main(n){scanf("%d%d%d%d",&n,&m,&a,&b);if(n&1)f(j,m)x(j);if(m&1)f(i,n)y(i*m);if(n>2&m>2&n&m&a&a>0&b>0)a++,x(0),x(2*m+1),y(2);f(i,n)f(j,m)if(p[(o=i*m+j)+1]);else if(a)x(o),x(o+m);else y(o),y(o+1);puts(a|b?"NO":"YES");if(!a&!b)for(i=0;i<n*m;++i%m||puts(""))putchar(p[i]?:46);}
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:3:10: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 p[2<<19],a,b,m,i,j,o;x(i,j){if(a)p[i]=60,p[i+1]=62,a--;}y(i,j){if(b)p[i]=94,p[i+m]=118,b--;}main(n){scanf("%d%d%d%d",&n,&m,&a,&b);if(n&1)f(j,m)x(j);if(m&1)f(i,n)y(i*m);if(n>2&m>2&n&m&a&a>0&b>0)a++,x(0),x(2*m+1),y(2);f(i,n)f(j,m)if(p[(o=i*m+j)+1]);else if(a)x(o),x(o+m);else y(o),y(o+1);puts(a|b?"NO":"YES");if(!a&!b)for(i=0;i<n*m;++i%m||puts(""))putchar(p[i]?:46);}
          ^
./Main.c:3:12: warning: type default...