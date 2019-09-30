#define f(i)for(i=0;i<k;i++)
a[100],b[100],c[101][100],d[100][100];i,j,l;
main(k,m)
{
	for(scanf("%d%d",&k,&m);j<2;j++)f(i)c[i+1][i]=-scanf("%d",j?*c+i:a+k-i-1);
	for(m-=k;m>0;m/=2){
		if(m&1){
			f(i)b[i]=a[i],a[i]=0;
			f(i)f(j)a[i]^=c[i][j]&b[j];
		}
		f(i)f(j)d[i][j]=c[i][j],c[i][j]=0;
		f(i)f(j)f(l)c[i][j]^=d[i][l]&d[l][j];
	}
	printf("%u\n",a[m<0?-m:0]);
} ./Main.c:2:1: warning: data definition has no type or storage class
 a[100],b[100],c[101][100],d[100][100];i,j,l;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:2:8: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a[100],b[100],c[101][100],d[100][100];i,j,l;
        ^
./Main.c:2:15: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 a[100],b[100],c[101][100],d[100][100];i,j,l;
               ^
./Main.c:2:27: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 a[100],b[100],c[101][100],d[100][100];i,j,l;
                           ^
./Main.c:2:39: warning: data definition has no type or storage class
 a[100],b[100],c[101][100],d[100][100];i,j,l;
                                       ^
./Main.c:2:39: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:41: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 a[100],b[100],c[101][100],d[100][100]...