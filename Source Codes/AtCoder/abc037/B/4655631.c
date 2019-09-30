a[100];i;main(l,r,t,n){for(scanf("%d%*d",&n);~scanf("%d%d%d",&l,&r,&t);)for(--l;l<r;)a[l++]=t;for(;i-n;)printf("%d\n",a[i++]);} ./Main.c:1:1: warning: data definition has no type or storage class
 a[100];i;main(l,r,t,n){for(scanf("%d%*d",&n);~scanf("%d%d%d",&l,&r,&t);)for(--l;l<r;)a[l++]=t;for(;i-n;)printf("%d\n",a[i++]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:8: warning: data definition has no type or storage class
 a[100];i;main(l,r,t,n){for(scanf("%d%*d",&n);~scanf("%d%d%d",&l,&r,&t);)for(--l;l<r;)a[l++]=t;for(;i-n;)printf("%d\n",a[i++]);}
        ^
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a[100];i;main(l,r,t,n){for(scanf("%d%*d",&n);~scanf("%d%d%d",&l,&r,&t);)for(--l;l<r;)a[l++]=t;for(;i-n;)printf("%d\n",a[i++]);}
          ^
./Main.c: In function ‘main’:
./Main.c:1:10: warning: type of ‘l’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:10: warning: type of ‘r’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:10: warning: type of ‘t’ defaults to ‘int’ [-Wimplic...