d[51]['~~'];a,b,i,j;main(w,k){for(scanf("%d%*d%d",&w,&k);~scanf("%d%d",&a,&b);)for(i=w;i/a;i--)for(j=0;k/++j;)d[j][i]=fmax(d[j][i],d[j-1][i-a]+b);printf("%d",d[k][w]);} ./Main.c:1:7: warning: multi-character character constant [-Wmultichar]
 d[51]['~~'];a,b,i,j;main(w,k){for(scanf("%d%*d%d",&w,&k);~scanf("%d%d",&a,&b);)for(i=w;i/a;i--)for(j=0;k/++j;)d[j][i]=fmax(d[j][i],d[j-1][i-a]+b);printf("%d",d[k][w]);}
       ^
./Main.c:1:1: warning: data definition has no type or storage class
 d[51]['~~'];a,b,i,j;main(w,k){for(scanf("%d%*d%d",&w,&k);~scanf("%d%d",&a,&b);)for(i=w;i/a;i--)for(j=0;k/++j;)d[j][i]=fmax(d[j][i],d[j-1][i-a]+b);printf("%d",d[k][w]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:1:13: warning: data definition has no type or storage class
 d[51]['~~'];a,b,i,j;main(w,k){for(scanf("%d%*d%d",&w,&k);~scanf("%d%d",&a,&b);)for(i=w;i/a;i--)for(j=0;k/++j;)d[j][i]=fmax(d[j][i],d[j-1][i-a]+b);printf("%d",d[k][w]);}
             ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 d[51]['~~'];a,b,i,j;...