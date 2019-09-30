t[999];i;s;main(x){for(;scanf("%d",t+i),i<=*t;++i)i?s+=t[i]:0;for(;~scanf("%d%d",&i,&x);)printf("%d ",s+x-t[i]);} ./Main.c:1:1: warning: data definition has no type or storage class
 t[999];i;s;main(x){for(;scanf("%d",t+i),i<=*t;++i)i?s+=t[i]:0;for(;~scanf("%d%d",&i,&x);)printf("%d ",s+x-t[i]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:1:8: warning: data definition has no type or storage class
 t[999];i;s;main(x){for(;scanf("%d",t+i),i<=*t;++i)i?s+=t[i]:0;for(;~scanf("%d%d",&i,&x);)printf("%d ",s+x-t[i]);}
        ^
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 t[999];i;s;main(x){for(;scanf("%d",t+i),i<=*t;++i)i?s+=t[i]:0;for(;~scanf("%d%d",&i,&x);)printf("%d ",s+x-t[i]);}
          ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:12: warning: return type defaults to ‘int’ [-Wimplicit-int]
 t[999];i;s;main(x){for(;scanf("%d",t+i),i<=*t;++i)i?s+=t[i]:0;for(;~scanf("%d%d",&i,&x);)printf("%d ",s+x-t[i]);}
       ...