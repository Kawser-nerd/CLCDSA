#define f(i,a,b)for(i=a;i++<b;)
s[2505],d[55][55],i,j,k,l;main(n){scanf("%d",&n);f(i,0,n)f(j,0,n)scanf("%d",d[i]+j);f(i,0,n)f(j,0,n)d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];f(i,-1,n-1)f(j,-1,n-1)f(k,i,n)f(l,j,n)s[(k-i)*(l-j)]=fmax(s[(k-i)*(l-j)],d[k][l]-d[k][j]-d[i][l]+d[i][j]);f(i,0,n*n)s[i]=fmax(s[i],s[i-1]);for(i=1;~scanf("%d",&l);)--i<0&&printf("%d\n",s[l]);} ./Main.c:2:1: warning: data definition has no type or storage class
 s[2505],d[55][55],i,j,k,l;main(n){scanf("%d",&n);f(i,0,n)f(j,0,n)scanf("%d",d[i]+j);f(i,0,n)f(j,0,n)d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];f(i,-1,n-1)f(j,-1,n-1)f(k,i,n)f(l,j,n)s[(k-i)*(l-j)]=fmax(s[(k-i)*(l-j)],d[k][l]-d[k][j]-d[i][l]+d[i][j]);f(i,0,n*n)s[i]=fmax(s[i],s[i-1]);for(i=1;~scanf("%d",&l);)--i<0&&printf("%d\n",s[l]);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;main(n){scanf("%d",&n);f(i,0,n)f(j,0,n)scanf("%d",d[i]+j);f(i,0,n)f(j,0,n)d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];f(i,-1,n-1)f(j,-1,n-1)f(k,i,n)f(l,j,n)s[(k-i)*(l-j)]=fmax(s[(k-i)*(l-j)],d[k][l]-d[k][j]-d[i][l]+d[i][j]);f(i,0,n*n)s[i]=fmax(s[i],s[i-1]);for(i=1;~scanf("%d",&l);)--i<0&&printf("%d\n",s[l]);}
         ^
./Main.c:2:19: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 s[2505],d[55][5...