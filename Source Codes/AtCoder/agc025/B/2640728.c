#define c(a,b)F[a]%M*p(F[a-b],M-2)%M*p(F[b],M-2)%M
long M=998244353,a,b,k,F[3<<17]={1},i,j,s;long p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(n){for(scanf("%d%d%d%ld",&n,&a,&b,&k);j++<n;)F[j]=j*F[j-1]%M;for(;i<=n;i+=j<0|j>n|a*i+b*j-k||(s=(s+c(n,i)*c(n,j))%M))j=(k-a*i)/b;printf("%d",s);} ./Main.c: In function ‘p’:
./Main.c:2:48: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
 long M=998244353,a,b,k,F[3<<17]={1},i,j,s;long p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(n){for(scanf("%d%d%d%ld",&n,&a,&b,&k);j++<n;)F[j]=j*F[j-1]%M;for(;i<=n;i+=j<0|j>n|a*i+b*j-k||(s=(s+c(n,i)*c(n,j))%M))j=(k-a*i)/b;printf("%d",s);}
                                                ^
./Main.c: At top level:
./Main.c:2:99: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=998244353,a,b,k,F[3<<17]={1},i,j,s;long p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(n){for(scanf("%d%d%d%ld",&n,&a,&b,&k);j++<n;)F[j]=j*F[j-1]%M;for(;i<=n;i+=j<0|j>n|a*i+b*j-k||(s=(s+c(n,i)*c(n,j))%M))j=(k-a*i)/b;printf("%d",s);}
                                                                                                   ^
./Main.c: In function ‘main’:
./Main.c:2:99: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:111: warning: implicit declaration of function ‘scanf’ [-Wimplicit-f...