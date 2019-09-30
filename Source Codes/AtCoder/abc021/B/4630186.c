p[999];i;main(a,b){scanf("%*d%d%d%*d",&i,&b);for(*p=i,p[1]=b;~scanf("%d",&b)&&a;p[i]=b)for(i=-1;p[++i]&&(a=b-p[i]););puts(a?"YES":"NO");} ./Main.c:1:1: warning: data definition has no type or storage class
 p[999];i;main(a,b){scanf("%*d%d%d%*d",&i,&b);for(*p=i,p[1]=b;~scanf("%d",&b)&&a;p[i]=b)for(i=-1;p[++i]&&(a=b-p[i]););puts(a?"YES":"NO");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:1:8: warning: data definition has no type or storage class
 p[999];i;main(a,b){scanf("%*d%d%d%*d",&i,&b);for(*p=i,p[1]=b;~scanf("%d",&b)&&a;p[i]=b)for(i=-1;p[++i]&&(a=b-p[i]););puts(a?"YES":"NO");}
        ^
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 p[999];i;main(a,b){scanf("%*d%d%d%*d",&i,&b);for(*p=i,p[1]=b;~scanf("%d",&b)&&a;p[i]=b)for(i=-1;p[++i]&&(a=b-p[i]););puts(a?"YES":"NO");}
          ^
./Main.c: In function ‘main’:
./Main.c:1:10: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:10: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:20: warning: implicit ...