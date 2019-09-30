c,a[100],m,i,j,x,e;main(n){for(scanf("%d%d",&n,&c);~scanf("%d",a+m++););for(;i++<10;)for(j=0;j++<10;)if(i-j){for(e=x=0;x<n;)e+=(x%2?i:j)!=a[x++];m=e<m?e:m;}printf("%d\n",c*m);} ./Main.c:1:1: warning: data definition has no type or storage class
 c,a[100],m,i,j,x,e;main(n){for(scanf("%d%d",&n,&c);~scanf("%d",a+m++););for(;i++<10;)for(j=0;j++<10;)if(i-j){for(e=x=0;x<n;)e+=(x%2?i:j)!=a[x++];m=e<m?e:m;}printf("%d\n",c*m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 c,a[100],m,i,j,x,e;main(n){for(scanf("%d%d",&n,&c);~scanf("%d",a+m++););for(;i++<10;)for(j=0;j++<10;)if(i-j){for(e=x=0;x<n;)e+=(x%2?i:j)!=a[x++];m=e<m?e:m;}printf("%d\n",c*m);}
   ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 c,a[100],m,i,j,x,e;main(n){for(scanf("%d%d",&n,&c);~scanf("%d",a+m++););for(;i++<10;)for(j=0;j++<10;)if(i-j){for(e=x=0;x<n;)e+=(x%2?i:j)!=a[x++];m=e<m?e:m;}printf("%d\n",c*m);}
          ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 c,a[100],m,i,j,x,e;main(n){for(scanf("%d%d",&n,&c);~scanf("...