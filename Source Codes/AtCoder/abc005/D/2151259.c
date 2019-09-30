#define f(i,a)for(i=0;i++<a;)
s[2505],d[55][55],i,j,k,l;main(n){scanf("%d",&n);f(i,n)f(j,n)scanf("%d",d[i]+j);f(i,n)f(j,n)d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];f(i,n)f(j,n){i--,j--;f(k,n-i)f(l,n-j)s[k*l]=fmax(s[k*l],d[i+k][j+l]-d[i+k][j]-d[i][j+l]+d[i][j]);i++,j++;}f(i,n*n)s[i]=fmax(s[i],s[i-1]);for(i=1;~scanf("%d",&l);)--i<0&&printf("%d\n",s[l]);} ./Main.c:2:1: warning: data definition has no type or storage class
 s[2505],d[55][55],i,j,k,l;main(n){scanf("%d",&n);f(i,n)f(j,n)scanf("%d",d[i]+j);f(i,n)f(j,n)d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];f(i,n)f(j,n){i--,j--;f(k,n-i)f(l,n-j)s[k*l]=fmax(s[k*l],d[i+k][j+l]-d[i+k][j]-d[i][j+l]+d[i][j]);i++,j++;}f(i,n*n)s[i]=fmax(s[i],s[i-1]);for(i=1;~scanf("%d",&l);)--i<0&&printf("%d\n",s[l]);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;main(n){scanf("%d",&n);f(i,n)f(j,n)scanf("%d",d[i]+j);f(i,n)f(j,n)d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];f(i,n)f(j,n){i--,j--;f(k,n-i)f(l,n-j)s[k*l]=fmax(s[k*l],d[i+k][j+l]-d[i+k][j]-d[i][j+l]+d[i][j]);i++,j++;}f(i,n*n)s[i]=fmax(s[i],s[i-1]);for(i=1;~scanf("%d",&l);)--i<0&&printf("%d\n",s[l]);}
         ^
./Main.c:2:19: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;main(n){s...