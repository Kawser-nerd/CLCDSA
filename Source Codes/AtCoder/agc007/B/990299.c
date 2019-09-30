#define R for(i=0;i++<n;)
#define S(s) int s;scanf("%d",&s);
#define P(x) R printf("%d%c",x[i-1],i<n?32:10);
main(i){S(n)int a[n],b[n];R a[i-1]=b[n-i]=i*n;R{S(p)a[--p]+=i,b[p]+=i;}P(a)P(b)} ./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i){S(n)int a[n],b[n];R a[i-1]=b[n-i]=i*n;R{S(p)a[--p]+=i,b[p]+=i;}P(a)P(b)}
 ^
./Main.c: In function ‘main’:
./Main.c:4:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:20: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 #define S(s) int s;scanf("%d",&s);
                    ^
./Main.c:4:9: note: in expansion of macro ‘S’
 main(i){S(n)int a[n],b[n];R a[i-1]=b[n-i]=i*n;R{S(p)a[--p]+=i,b[p]+=i;}P(a)P(b)}
         ^
./Main.c:2:20: warning: incompatible implicit declaration of built-in function ‘scanf’
 #define S(s) int s;scanf("%d",&s);
                    ^
./Main.c:4:9: note: in expansion of macro ‘S’
 main(i){S(n)int a[n],b[n];R a[i-1]=b[n-i]=i*n;R{S(p)a[--p]+=i,b[p]+=i;}P(a)P(b)}
         ^
./Main.c:2:20: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
 #define S(s) int s;scanf("%d",&s);
                    ^
./Main.c:4:9: note: in expansion of macro ‘S’
 main...