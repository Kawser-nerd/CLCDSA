#define f(i)for(int i=0;++i<N;)
N,c[300][300],u,v,z=1e9;main(l){for(N=atoi(gets(&N));~scanf("%d%d%d",&u,&v,&l);)c[--u][--v]=c[v][u]=l;f(k)f(i)f(j)c[i][j]=fmin(c[i][j]?:z,(c[i][k]?:z)+(c[k][j]?:z));f(i)f(j)i-j&&*c[i]**c[j]?z=fmin(z,*c[i]+c[i][j]+*c[j]):0;printf("%d\n",z<1e9?z:-1);} ./Main.c:2:1: warning: data definition has no type or storage class
 N,c[300][300],u,v,z=1e9;main(l){for(N=atoi(gets(&N));~scanf("%d%d%d",&u,&v,&l);)c[--u][--v]=c[v][u]=l;f(k)f(i)f(j)c[i][j]=fmin(c[i][j]?:z,(c[i][k]?:z)+(c[k][j]?:z));f(i)f(j)i-j&&*c[i]**c[j]?z=fmin(z,*c[i]+c[i][j]+*c[j]):0;printf("%d\n",z<1e9?z:-1);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 N,c[300][300],u,v,z=1e9;main(l){for(N=atoi(gets(&N));~scanf("%d%d%d",&u,&v,&l);)c[--u][--v]=c[v][u]=l;f(k)f(i)f(j)c[i][j]=fmin(c[i][j]?:z,(c[i][k]?:z)+(c[k][j]?:z));f(i)f(j)i-j&&*c[i]**c[j]?z=fmin(z,*c[i]+c[i][j]+*c[j]):0;printf("%d\n",z<1e9?z:-1);}
   ^
./Main.c:2:15: warning: type defaults to ‘int’ in declaration of ‘u’ [-Wimplicit-int]
 N,c[300][300],u,v,z=1e9;main(l){for(N=atoi(gets(&N));~scanf("%d%d%d",&u,&v,&l);)c[--u][--v]=c[v][u]=l;f(k)f(i)f(j)c[i][j]=fmin(c[i][j]?:z,(c[i][k]?:z)+(c[k][j]?:z));f(i)f(j)i-j&&*c[i]**c[j]...