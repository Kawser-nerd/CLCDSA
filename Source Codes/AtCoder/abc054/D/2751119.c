#define T 999
D[T][T],i,j,x,y,a,b,c,R;main(k){scanf("%*d%d%d",&x,&y);for(D[0][0]=9999;~scanf("%d%d%d",&a,&b,&c);)for(i=T;i-->a;)for(j=T;j-->b;)k=D[i-a][j-b]-c,D[i][j]<k?D[i][j]=k:0;for(i=x,j=y;i<T&&j<T;i+=x,j+=y)D[i][j]>R?R=D[i][j]:0;printf("%d\n",R>0?9999-R:-1);} ./Main.c:2:1: warning: data definition has no type or storage class
 D[T][T],i,j,x,y,a,b,c,R;main(k){scanf("%*d%d%d",&x,&y);for(D[0][0]=9999;~scanf("%d%d%d",&a,&b,&c);)for(i=T;i-->a;)for(j=T;j-->b;)k=D[i-a][j-b]-c,D[i][j]<k?D[i][j]=k:0;for(i=x,j=y;i<T&&j<T;i+=x,j+=y)D[i][j]>R?R=D[i][j]:0;printf("%d\n",R>0?9999-R:-1);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘D’ [-Wimplicit-int]
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 D[T][T],i,j,x,y,a,b,c,R;main(k){scanf("%*d%d%d",&x,&y);for(D[0][0]=9999;~scanf("%d%d%d",&a,&b,&c);)for(i=T;i-->a;)for(j=T;j-->b;)k=D[i-a][j-b]-c,D[i][j]<k?D[i][j]=k:0;for(i=x,j=y;i<T&&j<T;i+=x,j+=y)D[i][j]>R?R=D[i][j]:0;printf("%d\n",R>0?9999-R:-1);}
         ^
./Main.c:2:11: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 D[T][T],i,j,x,y,a,b,c,R;main(k){scanf("%*d%d%d",&x,&y);for(D[0][0]=9999;~scanf("%d%d%d",&a,&b,&c);)for(i=T;i-->a;)for(j=T;j-->b;)k=D[i-a][j-b]-c,D[i][j]<k?D[i][j]=k:0;for(i=x,j=y;i<...