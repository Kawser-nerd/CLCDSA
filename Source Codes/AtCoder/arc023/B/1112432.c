c[1000000],i,j,k,m;
main(w,d)
{
	for(scanf("%*d%d%d",&w,&d);~scanf("%d",c+j);m=m<c[j]?c[j]:m,j++)((k=j/w+j%w)>d||k+d&1)?c[j]=0:0;
	printf("%d\n",m);
} ./Main.c:1:1: warning: data definition has no type or storage class
 c[1000000],i,j,k,m;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 c[1000000],i,j,k,m;
            ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 c[1000000],i,j,k,m;
              ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 c[1000000],i,j,k,m;
                ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 c[1000000],i,j,k,m;
                  ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(w,d)
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘w’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declar...