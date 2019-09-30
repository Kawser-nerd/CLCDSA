p[1<<17],s,x,y,z;f(a){return p[a]-a?p[a]=f(p[a]):a;}main(n){for(n=atoi(gets(p));y++<n;)p[y]=y;for(;~scanf("%d%d",&x,&y);)p[f(y)]=f(x);for(;z++<n;)s+=f(z)==z;printf("%d\n",s-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 p[1<<17],s,x,y,z;f(a){return p[a]-a?p[a]=f(p[a]):a;}main(n){for(n=atoi(gets(p));y++<n;)p[y]=y;for(;~scanf("%d%d",&x,&y);)p[f(y)]=f(x);for(;z++<n;)s+=f(z)==z;printf("%d\n",s-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 p[1<<17],s,x,y,z;f(a){return p[a]-a?p[a]=f(p[a]):a;}main(n){for(n=atoi(gets(p));y++<n;)p[y]=y;for(;~scanf("%d%d",&x,&y);)p[f(y)]=f(x);for(;z++<n;)s+=f(z)==z;printf("%d\n",s-1);}
          ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 p[1<<17],s,x,y,z;f(a){return p[a]-a?p[a]=f(p[a]):a;}main(n){for(n=atoi(gets(p));y++<n;)p[y]=y;for(;~scanf("%d%d",&x,&y);)p[f(y)]=f(x);for(;z++<n;)s+=f(z)==z;printf("%d\n",s-1);}
            ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 p[1<<17],s,x,y,z;f(a){return p[a]-a?p[a]=f(p[a...