s;n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=s%127?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));} ./Main.c:1:1: warning: data definition has no type or storage class
 s;n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=s%127?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 s;n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=s%127?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 s;n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=s%127?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));}
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 s;n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=s%127?c:-c)c=c>b?b:c<a?a:c;...