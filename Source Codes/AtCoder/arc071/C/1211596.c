s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar()-10;a++)s[a+1]=s[a]+d-54;for(;d=getchar()-10;b++)t[b+1]=t[b]+d-54;for(gets(&a);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b]-s[a-1])%3-(t[d]-t[c-1])%3?"NO":"YES");} ./Main.c:1:1: warning: data definition has no type or storage class
 s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar()-10;a++)s[a+1]=s[a]+d-54;for(;d=getchar()-10;b++)t[b+1]=t[b]+d-54;for(gets(&a);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b]-s[a-1])%3-(t[d]-t[c-1])%3?"NO":"YES");}
 ^
./Main.c:1:1: warning: type defaults to �int� in declaration of �s� [-Wimplicit-int]
./Main.c:1:10: warning: type defaults to �int� in declaration of �t� [-Wimplicit-int]
 s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar()-10;a++)s[a+1]=s[a]+d-54;for(;d=getchar()-10;b++)t[b+1]=t[b]+d-54;for(gets(&a);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b]-s[a-1])%3-(t[d]-t[c-1])%3?"NO":"YES");}
          ^
./Main.c:1:19: warning: data definition has no type or storage class
 s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar()-10;a++)s[a+1]=s[a]+d-54;for(;d=getchar()-10;b++)t[b+1]=t[b]+d-54;for(gets(&a);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b]-s[a-1])%3-(t[d]-t[c-1])%3?"NO":"YES");}
                   ^
./Main.c:1:19: warning: type defaults to �int� ...