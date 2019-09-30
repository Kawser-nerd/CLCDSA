long M=1e9+7,s;d[200][101],b,m,u,v,c[101],G[101][200];main(n){scanf("%d%d%d%*d",&n,&s,&b);for(n++;~scanf("%d%d",&u,&v);G[u][c[u]++]=v)G[v][c[v]++]=u;for(d[m][s]=1;!s+!m++;s=d[m][b])for(u=n;s=0,--u;d[m][u]=s%M)for(v=c[u];v--;s+=d[m-1][G[u][v]]);printf("%d\n",s);} ./Main.c:1:16: warning: data definition has no type or storage class
 long M=1e9+7,s;d[200][101],b,m,u,v,c[101],G[101][200];main(n){scanf("%d%d%d%*d",&n,&s,&b);for(n++;~scanf("%d%d",&u,&v);G[u][c[u]++]=v)G[v][c[v]++]=u;for(d[m][s]=1;!s+!m++;s=d[m][b])for(u=n;s=0,--u;d[m][u]=s%M)for(v=c[u];v--;s+=d[m-1][G[u][v]]);printf("%d\n",s);}
                ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:1:28: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 long M=1e9+7,s;d[200][101],b,m,u,v,c[101],G[101][200];main(n){scanf("%d%d%d%*d",&n,&s,&b);for(n++;~scanf("%d%d",&u,&v);G[u][c[u]++]=v)G[v][c[v]++]=u;for(d[m][s]=1;!s+!m++;s=d[m][b])for(u=n;s=0,--u;d[m][u]=s%M)for(v=c[u];v--;s+=d[m-1][G[u][v]]);printf("%d\n",s);}
                            ^
./Main.c:1:30: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 long M=1e9+7,s;d[200][101],b,m,u,v,c[101],G[101][200];main(n){scanf("%d%d%d%*d",&n,&s,&b);for(n++;~scanf("%d%d",&u,&v);G...