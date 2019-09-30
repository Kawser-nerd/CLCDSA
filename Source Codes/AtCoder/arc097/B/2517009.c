c,p[1<<17],P[1<<17],i;f(a){return a-p[a]?p[a]=f(p[a]):a;}main(x,y){for(scanf("%d%*d",&x);i++<x;p[i]=i)scanf("%d",P+i);for(;~scanf("%d%d",&x,&y);)p[x=f(x)]=x-f(y)?f(y):x;for(;--i;)c+=f(P[i])==f(i);printf("%d",c);} ./Main.c:1:1: warning: data definition has no type or storage class
 c,p[1<<17],P[1<<17],i;f(a){return a-p[a]?p[a]=f(p[a]):a;}main(x,y){for(scanf("%d%*d",&x);i++<x;p[i]=i)scanf("%d",P+i);for(;~scanf("%d%d",&x,&y);)p[x=f(x)]=x-f(y)?f(y):x;for(;--i;)c+=f(P[i])==f(i);printf("%d",c);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
 c,p[1<<17],P[1<<17],i;f(a){return a-p[a]?p[a]=f(p[a]):a;}main(x,y){for(scanf("%d%*d",&x);i++<x;p[i]=i)scanf("%d",P+i);for(;~scanf("%d%d",&x,&y);)p[x=f(x)]=x-f(y)?f(y):x;for(;--i;)c+=f(P[i])==f(i);printf("%d",c);}
   ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘P’ [-Wimplicit-int]
 c,p[1<<17],P[1<<17],i;f(a){return a-p[a]?p[a]=f(p[a]):a;}main(x,y){for(scanf("%d%*d",&x);i++<x;p[i]=i)scanf("%d",P+i);for(;~scanf("%d%d",&x,&y);)p[x=f(x)]=x-f(y)?f(y):x;for(;--i;)c+=f(P[i])==f(i);printf("%d",c);}
            ^
./Main.c:1:21: warning: type default...