c[51];n;i;main(a,b){for(scanf("%d%*d",&n);~scanf("%d%d",&a,&b);c[b]++)c[a]++;for(;++i<=n;)printf("%d ",c[i]);} ./Main.c:1:1: warning: data definition has no type or storage class
 c[51];n;i;main(a,b){for(scanf("%d%*d",&n);~scanf("%d%d",&a,&b);c[b]++)c[a]++;for(;++i<=n;)printf("%d ",c[i]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:7: warning: data definition has no type or storage class
 c[51];n;i;main(a,b){for(scanf("%d%*d",&n);~scanf("%d%d",&a,&b);c[b]++)c[a]++;for(;++i<=n;)printf("%d ",c[i]);}
       ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:9: warning: data definition has no type or storage class
 c[51];n;i;main(a,b){for(scanf("%d%*d",&n);~scanf("%d%d",&a,&b);c[b]++)c[a]++;for(;++i<=n;)printf("%d ",c[i]);}
         ^
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:11: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c[51];n;i;main(a,b){for(scanf("%d%*d",&n);~scanf("%d%d",&a,&b);c[b]++)c[a]++;for(;++i<=n;)printf("%d ",c[i]);}
           ^
./Main.c: ...