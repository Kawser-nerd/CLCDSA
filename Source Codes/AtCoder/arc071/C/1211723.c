s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar(a++)/11;)s[a+1]=s[a]+d-4;for(;d=getchar(b++)/11;)t[b+1]=t[b]+d-4;for(gets(s);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b+1]-s[a]-t[d+1]+t[c])%3?"NO":"YES");} ./Main.c:1:1: warning: data definition has no type or storage class
 s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar(a++)/11;)s[a+1]=s[a]+d-4;for(;d=getchar(b++)/11;)t[b+1]=t[b]+d-4;for(gets(s);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b+1]-s[a]-t[d+1]+t[c])%3?"NO":"YES");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar(a++)/11;)s[a+1]=s[a]+d-4;for(;d=getchar(b++)/11;)t[b+1]=t[b]+d-4;for(gets(s);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b+1]-s[a]-t[d+1]+t[c])%3?"NO":"YES");}
          ^
./Main.c:1:19: warning: data definition has no type or storage class
 s[1<<17],t[1<<17];a,b,c;main(d){for(;d=getchar(a++)/11;)s[a+1]=s[a]+d-4;for(;d=getchar(b++)/11;)t[b+1]=t[b]+d-4;for(gets(s);~scanf("%d%d%d%d",&a,&b,&c,&d);)puts((s[b+1]-s[a]-t[d+1]+t[c])%3?"NO":"YES");}
                   ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘a’...