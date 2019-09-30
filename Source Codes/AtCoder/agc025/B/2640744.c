long M=998244353,a,b,k,F[3<<17]={1,1},I[3<<17]={1,1},R[3<<17]={1,1},i,j=1,s;main(n){for(scanf("%d%d%d%ld",&n,&a,&b,&k);j++<n;R[j]=(I[j]=(M-M/j)*I[M%j]%M)*R[j-1]%M)F[j]=j*F[j-1]%M;for(;i<=n;i+=j<0|j>n|a*i+b*j-k||(s=(s+F[n]*R[n-i]%M*R[i]%M*F[n]%M*R[n-j]%M*R[j])%M))j=(k-a*i)/b;printf("%d",s);} ./Main.c:1:77: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=998244353,a,b,k,F[3<<17]={1,1},I[3<<17]={1,1},R[3<<17]={1,1},i,j=1,s;main(n){for(scanf("%d%d%d%ld",&n,&a,&b,&k);j++<n;R[j]=(I[j]=(M-M/j)*I[M%j]%M)*R[j-1]%M)F[j]=j*F[j-1]%M;for(;i<=n;i+=j<0|j>n|a*i+b*j-k||(s=(s+F[n]*R[n-i]%M*R[i]%M*F[n]%M*R[n-j]%M*R[j])%M))j=(k-a*i)/b;printf("%d",s);}
                                                                             ^
./Main.c: In function ‘main’:
./Main.c:1:77: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:89: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long M=998244353,a,b,k,F[3<<17]={1,1},I[3<<17]={1,1},R[3<<17]={1,1},i,j=1,s;main(n){for(scanf("%d%d%d%ld",&n,&a,&b,&k);j++<n;R[j]=(I[j]=(M-M/j)*I[M%j]%M)*R[j-1]%M)F[j]=j*F[j-1]%M;for(;i<=n;i+=j<0|j>n|a*i+b*j-k||(s=(s+F[n]*R[n-i]%M*R[i]%M*F[n]%M*R[n-j]%M*R[j])%M))j=(k-a*i)/b;printf("%d",s);}
                                                                                        ...