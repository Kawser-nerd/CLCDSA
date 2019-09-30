#define $ i>>--r&1|r>4&r<20&(i>>r-5^i>>r+5)|r%5>0&r%5<4&(i>>r-1^i>>r+1)||(p[r=i|1<<r]+=p[i],p[r]%=a=1e9+7)
p[1<<25],x[26],G[21],i,r;*q=G;main(a){for(*p=1;~scanf("%d",&a);)a?x[a]=++r:(*q++=++r);for(;i<1<<25;i++)if(r=x[__builtin_popcount(i)+1])$;else for(q=G;r=*q++;$);printf("%d\n",p[i-1]);} ./Main.c:2:1: warning: data definition has no type or storage class
 p[1<<25],x[26],G[21],i,r;*q=G;main(a){for(*p=1;~scanf("%d",&a);)a?x[a]=++r:(*q++=++r);for(;i<1<<25;i++)if(r=x[__builtin_popcount(i)+1])$;else for(q=G;r=*q++;$);printf("%d\n",p[i-1]);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:2:10: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 p[1<<25],x[26],G[21],i,r;*q=G;main(a){for(*p=1;~scanf("%d",&a);)a?x[a]=++r:(*q++=++r);for(;i<1<<25;i++)if(r=x[__builtin_popcount(i)+1])$;else for(q=G;r=*q++;$);printf("%d\n",p[i-1]);}
          ^
./Main.c:2:16: warning: type defaults to ‘int’ in declaration of ‘G’ [-Wimplicit-int]
 p[1<<25],x[26],G[21],i,r;*q=G;main(a){for(*p=1;~scanf("%d",&a);)a?x[a]=++r:(*q++=++r);for(;i<1<<25;i++)if(r=x[__builtin_popcount(i)+1])$;else for(q=G;r=*q++;$);printf("%d\n",p[i-1]);}
                ^
./Main.c:2:22: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 p[1<<25],x[26],G[21],i,r...