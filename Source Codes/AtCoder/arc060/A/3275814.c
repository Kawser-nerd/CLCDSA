long d['~~'];A,x,i,j;main(n){for(scanf("%d%d",&n,&A),d[n*=A]=1;~scanf("%d",&x);i=5e3-i)for(j=2*n;j--;)d[5000-i+j]=d[i+j]+d[j<x-A?:i+j-x+A];printf("%ld",d[i+n]-1);} ./Main.c:1:8: warning: multi-character character constant [-Wmultichar]
 long d['~~'];A,x,i,j;main(n){for(scanf("%d%d",&n,&A),d[n*=A]=1;~scanf("%d",&x);i=5e3-i)for(j=2*n;j--;)d[5000-i+j]=d[i+j]+d[j<x-A?:i+j-x+A];printf("%ld",d[i+n]-1);}
        ^
./Main.c:1:14: warning: data definition has no type or storage class
 long d['~~'];A,x,i,j;main(n){for(scanf("%d%d",&n,&A),d[n*=A]=1;~scanf("%d",&x);i=5e3-i)for(j=2*n;j--;)d[5000-i+j]=d[i+j]+d[j<x-A?:i+j-x+A];printf("%ld",d[i+n]-1);}
              ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 long d['~~'];A,x,i,j;main(n){for(scanf("%d%d",&n,&A),d[n*=A]=1;~scanf("%d",&x);i=5e3-i)for(j=2*n;j--;)d[5000-i+j]=d[i+j]+d[j<x-A?:i+j-x+A];printf("%ld",d[i+n]-1);}
                ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 long d['~~'];A,x,i,j;main(n){for(scanf("%d%d",&n,&A),d[n*=A]=1;~scanf("%d",&x);i=5e3-...