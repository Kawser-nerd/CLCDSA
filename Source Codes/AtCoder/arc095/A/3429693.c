f(int*a,int*b){return*a-*b;}
n,a[2<<17],b[2<<17],i;
main(){
	scanf("%d",&n);
	for(;~scanf("%d",a+i);i++)b[i]=a[i];
	qsort(a,n,4,f);
	for(i=0;i<n;i++)printf("%d\n",a[a[n/2]>b[i]?n/2:n/2-1]);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(int*a,int*b){return*a-*b;}
 ^
./Main.c:2:1: warning: data definition has no type or storage class
 n,a[2<<17],b[2<<17],i;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 n,a[2<<17],b[2<<17],i;
   ^
./Main.c:2:12: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 n,a[2<<17],b[2<<17],i;
            ^
./Main.c:2:21: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 n,a[2<<17],b[2<<17],i;
                     ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d",&n);
  ^
./Main.c:4:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:2: note: include ‘<stdio.h>’ or pr...