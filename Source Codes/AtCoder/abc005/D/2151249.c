#define f(i,a,b)for(i=a;i++<b;)
s[2505],d[55][55],i,j,k,l;
main(n)
{
	scanf("%d",&n);
	f(i,0,n)f(j,0,n)scanf("%d",d[i]+j);
	f(i,0,n)f(j,0,n)d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];
	f(i,-1,n-1)f(j,-1,n-1)f(k,i,n)f(l,j,n)s[(k-i)*(l-j)]=fmax(s[(k-i)*(l-j)],d[k][l]-d[k][j]-d[i][l]+d[i][j]);
	f(i,0,n*n)s[i]=fmax(s[i],s[i-1]);
	scanf("%d",&k);
	f(i,0,k)scanf("%d",&l),printf("%d\n",s[l]);
} ./Main.c:2:1: warning: data definition has no type or storage class
 s[2505],d[55][55],i,j,k,l;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;
         ^
./Main.c:2:19: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;
                   ^
./Main.c:2:21: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;
                     ^
./Main.c:2:23: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;
                       ^
./Main.c:2:25: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 s[2505],d[55][55],i,j,k,l;
                         ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n)
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘n’ defaults t...