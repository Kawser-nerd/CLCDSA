#define h(a,b) (a)*(a)+(b)*(b)>r*r||
a,b,c,d,e,f;main(r){scanf("%d%d%d%d%d%d%d",&a,&d,&r,&b,&e,&c,&f);puts(b>a-r||c<a+r||e>d-r||f<d+r?"YES":"NO");puts(h(b-a,e-d)h(b-a,f-d)h(c-a,e-d)h(c-a,f-d)0?"YES":"NO");} ./Main.c:2:1: warning: data definition has no type or storage class
 a,b,c,d,e,f;main(r){scanf("%d%d%d%d%d%d%d",&a,&d,&r,&b,&e,&c,&f);puts(b>a-r||c<a+r||e>d-r||f<d+r?"YES":"NO");puts(h(b-a,e-d)h(b-a,f-d)h(c-a,e-d)h(c-a,f-d)0?"YES":"NO");}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b,c,d,e,f;main(r){scanf("%d%d%d%d%d%d%d",&a,&d,&r,&b,&e,&c,&f);puts(b>a-r||c<a+r||e>d-r||f<d+r?"YES":"NO");puts(h(b-a,e-d)h(b-a,f-d)h(c-a,e-d)h(c-a,f-d)0?"YES":"NO");}
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 a,b,c,d,e,f;main(r){scanf("%d%d%d%d%d%d%d",&a,&d,&r,&b,&e,&c,&f);puts(b>a-r||c<a+r||e>d-r||f<d+r?"YES":"NO");puts(h(b-a,e-d)h(b-a,f-d)h(c-a,e-d)h(c-a,f-d)0?"YES":"NO");}
     ^
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 a,b,c,d,e,f;main(r){scanf("%d%d%d%d%d%d%d",&a,&d,&r,&b,&e,&c,&f);puts(b>a-r||c<a+r||e>d...