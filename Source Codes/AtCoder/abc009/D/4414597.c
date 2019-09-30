#define f(i)for(i=0;i<k;i++)
#define _(a,b)f(i)f(j){b=0;f(l)b^=a[i][l]&c[l][j];}f(i)f(j)a[i][j]=b;}
a[100],b[100],c[101][100],A[100][100],d[100][100];i,j,l;
main(k,m)
{
	for(scanf("%d%d",&k,&m);j<2;j++)f(i)A[i][i]=c[i+1][i]=-scanf("%d",j?*c+i:a+k-i-1);
	for(m-=k;m>0;m/=2){if(m&1){_(A,d[i][j])_(c,d[i][j])
	l=0;f(i)l^=a[i]&A[0][i];
	printf("%u\n",m<0?a[-m]:l);
} ./Main.c:3:1: warning: data definition has no type or storage class
 a[100],b[100],c[101][100],A[100][100],d[100][100];i,j,l;
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:3:8: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a[100],b[100],c[101][100],A[100][100],d[100][100];i,j,l;
        ^
./Main.c:3:15: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 a[100],b[100],c[101][100],A[100][100],d[100][100];i,j,l;
               ^
./Main.c:3:27: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
 a[100],b[100],c[101][100],A[100][100],d[100][100];i,j,l;
                           ^
./Main.c:3:39: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 a[100],b[100],c[101][100],A[100][100],d[100][100];i,j,l;
                                       ^
./Main.c:3:51: warning: data definition has no type or storage class
 a[100],b[100],c[101][100],A[100][100],d[100][100];i,j,l;
     ...