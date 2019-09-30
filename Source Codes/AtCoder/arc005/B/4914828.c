x,y;h,v;char c[99];i;j=5;main(W){for(scanf("%d%d%s",&x,&y,&W);~scanf("%s",c+9*i++););W&8|W&2?h=W/2%2?:-1,W>>=8:0,v=W%2?-1:!!W;for(;--j;x+=h=(x+h)%10?h:-h,y+=v=(y+v)%10?v:-v)putchar(c[9*y+x-10]);puts("");} ./Main.c:1:1: warning: data definition has no type or storage class
 x,y;h,v;char c[99];i;j=5;main(W){for(scanf("%d%d%s",&x,&y,&W);~scanf("%s",c+9*i++););W&8|W&2?h=W/2%2?:-1,W>>=8:0,v=W%2?-1:!!W;for(;--j;x+=h=(x+h)%10?h:-h,y+=v=(y+v)%10?v:-v)putchar(c[9*y+x-10]);puts("");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 x,y;h,v;char c[99];i;j=5;main(W){for(scanf("%d%d%s",&x,&y,&W);~scanf("%s",c+9*i++););W&8|W&2?h=W/2%2?:-1,W>>=8:0,v=W%2?-1:!!W;for(;--j;x+=h=(x+h)%10?h:-h,y+=v=(y+v)%10?v:-v)putchar(c[9*y+x-10]);puts("");}
   ^
./Main.c:1:5: warning: data definition has no type or storage class
 x,y;h,v;char c[99];i;j=5;main(W){for(scanf("%d%d%s",&x,&y,&W);~scanf("%s",c+9*i++););W&8|W&2?h=W/2%2?:-1,W>>=8:0,v=W%2?-1:!!W;for(;--j;x+=h=(x+h)%10?h:-h,y+=v=(y+v)%10?v:-v)putchar(c[9*y+x-10]);puts("");}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘h’ [-Wimplicit-int]
...