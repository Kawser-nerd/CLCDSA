a,b,c[1<<17],f,i;main(j){for(;~scanf("%d%d",&a,&b);)--j?c[a]++,c[b]++:0;for(;++i<1<<17;f+=c[i]%2);puts(f?"NO":"YES");} ./Main.c:1:1: warning: data definition has no type or storage class
 a,b,c[1<<17],f,i;main(j){for(;~scanf("%d%d",&a,&b);)--j?c[a]++,c[b]++:0;for(;++i<1<<17;f+=c[i]%2);puts(f?"NO":"YES");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b,c[1<<17],f,i;main(j){for(;~scanf("%d%d",&a,&b);)--j?c[a]++,c[b]++:0;for(;++i<1<<17;f+=c[i]%2);puts(f?"NO":"YES");}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 a,b,c[1<<17],f,i;main(j){for(;~scanf("%d%d",&a,&b);)--j?c[a]++,c[b]++:0;for(;++i<1<<17;f+=c[i]%2);puts(f?"NO":"YES");}
     ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 a,b,c[1<<17],f,i;main(j){for(;~scanf("%d%d",&a,&b);)--j?c[a]++,c[b]++:0;for(;++i<1<<17;f+=c[i]%2);puts(f?"NO":"YES");}
              ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 a,b,c[1<<17],f,i;...