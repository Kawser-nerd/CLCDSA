#define m(a,b)(a=a<b?b:a)
long c,x[1<<17],v[1<<17],s,L,R,r,l;i;main(n){for(scanf("%d%ld",&n,&c);~scanf("%ld%d",x+i,v+i);)L+=v[i++];for(;i--;){L-=v[i];R+=v[i];m(s,L-x[i-1]*2+m(r,R-c+x[i]));}for(;i<n;){L+=v[i];R-=v[i++];m(s,R-(i!=n)*(c-x[i])*2+m(l,L-x[i-1]));}printf("%ld",s);} ./Main.c:2:36: warning: data definition has no type or storage class
 long c,x[1<<17],v[1<<17],s,L,R,r,l;i;main(n){for(scanf("%d%ld",&n,&c);~scanf("%ld%d",x+i,v+i);)L+=v[i++];for(;i--;){L-=v[i];R+=v[i];m(s,L-x[i-1]*2+m(r,R-c+x[i]));}for(;i<n;){L+=v[i];R-=v[i++];m(s,R-(i!=n)*(c-x[i])*2+m(l,L-x[i-1]));}printf("%ld",s);}
                                    ^
./Main.c:2:36: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:38: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long c,x[1<<17],v[1<<17],s,L,R,r,l;i;main(n){for(scanf("%d%ld",&n,&c);~scanf("%ld%d",x+i,v+i);)L+=v[i++];for(;i--;){L-=v[i];R+=v[i];m(s,L-x[i-1]*2+m(r,R-c+x[i]));}for(;i<n;){L+=v[i];R-=v[i++];m(s,R-(i!=n)*(c-x[i])*2+m(l,L-x[i-1]));}printf("%ld",s);}
                                      ^
./Main.c: In function ‘main’:
./Main.c:2:38: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:50: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long c,x[1<<17],v...