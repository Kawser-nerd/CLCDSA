#define f(i)for(i=0;i<k;i++)
long a[100],b[100],c[101][100],d[100][100];i,j,l;
main(k,m)
{
	for(scanf("%d%d",&k,&m);j<2;j++)f(i)c[i+1][i]=-scanf("%d",j?*c+i:a+k-i-1);
	for(m-=k;m>0;m/=2){
		if(m&1){f(i)b[i]=a[i],a[i]=0;f(i)f(j)a[i]^=b[j]&c[i][j];}
		f(i)f(j)d[i][j]=c[i][j],c[i][j]=0;
		f(i)f(j)f(l)c[i][j]^=d[i][l]&d[l][j];
	}
	printf("%ld\n",a[m<0?-m:0]);
} ./Main.c:2:44: warning: data definition has no type or storage class
 long a[100],b[100],c[101][100],d[100][100];i,j,l;
                                            ^
./Main.c:2:44: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:46: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 long a[100],b[100],c[101][100],d[100][100];i,j,l;
                                              ^
./Main.c:2:48: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 long a[100],b[100],c[101][100],d[100][100];i,j,l;
                                                ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(k,m)
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:5:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d%d",&k,&m);j<2;j++)f(i)c[i+1]...