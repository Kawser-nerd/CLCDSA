char s[];n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=*s-69?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));} ./Main.c:1:10: warning: data definition has no type or storage class
 char s[];n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=*s-69?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));}
          ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 char s[];n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=*s-69?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));}
            ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 char s[];n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=*s-69?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"West ":"East ":"",abs(n));}
              ^
./Main.c:1:16: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[];n,b,c;main(a){for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",&s,&c);n+=*s-69?c:-c)c=c>b?b:c<a?a:c;printf("%s%d\n",n?n>0?"...