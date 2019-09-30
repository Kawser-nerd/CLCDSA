#define T 444
D[T][T],i,j,x,y,a,b,c,r=9999;main(k){for(i=-1;++i<T;)for(j=-1;++j<T;)D[i][j]=r;scanf("%*d%d%d",&x,&y);for(D[0][0]=0;~scanf("%d%d%d",&a,&b,&c);)for(i=T;i-->a;)for(j=T;j-->b;){k=D[i-a][j-b]+c;if(D[i][j]>k)D[i][j]=k;}for(i=x,j=y;i<T&&j<T;i+=x,j+=y){if(D[i][j]<r)r=D[i][j];}printf(r>=9999?"-1\n":"%u\n",r);} ./Main.c:2:1: warning: data definition has no type or storage class
 D[T][T],i,j,x,y,a,b,c,r=9999;main(k){for(i=-1;++i<T;)for(j=-1;++j<T;)D[i][j]=r;scanf("%*d%d%d",&x,&y);for(D[0][0]=0;~scanf("%d%d%d",&a,&b,&c);)for(i=T;i-->a;)for(j=T;j-->b;){k=D[i-a][j-b]+c;if(D[i][j]>k)D[i][j]=k;}for(i=x,j=y;i<T&&j<T;i+=x,j+=y){if(D[i][j]<r)r=D[i][j];}printf(r>=9999?"-1\n":"%u\n",r);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘D’ [-Wimplicit-int]
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 D[T][T],i,j,x,y,a,b,c,r=9999;main(k){for(i=-1;++i<T;)for(j=-1;++j<T;)D[i][j]=r;scanf("%*d%d%d",&x,&y);for(D[0][0]=0;~scanf("%d%d%d",&a,&b,&c);)for(i=T;i-->a;)for(j=T;j-->b;){k=D[i-a][j-b]+c;if(D[i][j]>k)D[i][j]=k;}for(i=x,j=y;i<T&&j<T;i+=x,j+=y){if(D[i][j]<r)r=D[i][j];}printf(r>=9999?"-1\n":"%u\n",r);}
         ^
./Main.c:2:11: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 D[T][T],i,j,x,y,a,b,c,r=9999;main(k){for(i=-1;++i<T;)for(j=-1;++j<T;)D[i][j...