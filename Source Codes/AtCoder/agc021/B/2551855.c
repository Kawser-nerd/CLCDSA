x[100],y[100];i,j,k;
double p[101],s,P=2*acos(-1);
c(a,b)double*a,*b;{return*a<*b?-1:*a>*b;}
main(n){
	for(scanf("%d",&n);~scanf("%d%d",x+j++,y+j););
	for(;i<n;i++)
	{
		for(k=j=0;j<n;j++)i-j&&(p[k++]=atan2(y[j]-y[i],x[j]-x[i]));
		qsort(p,k,8,c);
		for(p[k]=p[j=s=0]+P;++j<n;)s=fmax(s,(p[j]-p[j-1])/P-.5);
		printf("%.9f\n",s);
	}
} ./Main.c:1:1: warning: data definition has no type or storage class
 x[100],y[100];i,j,k;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 x[100],y[100];i,j,k;
        ^
./Main.c:1:15: warning: data definition has no type or storage class
 x[100],y[100];i,j,k;
               ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:17: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 x[100],y[100];i,j,k;
                 ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 x[100],y[100];i,j,k;
                   ^
./Main.c:2:21: warning: implicit declaration of function ‘acos’ [-Wimplicit-function-declaration]
 double p[101],s,P=2*acos(-1);
                     ^
./Main.c:2:21: warning: incompatible implicit declaration of built-in function ‘acos’
./Main.c:2:21: note: include ‘<math...