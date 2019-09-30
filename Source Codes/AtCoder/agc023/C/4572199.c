long m=1e9+7,f[1<<20]={1},v[1<<20]={1},a=1;i;
long p(long a,long b){return b?p(a*a%m,b/2)*(b%2?a:1)%m:1;}
main(n){
	for(scanf("%d",&n);i++<n;)v[i]=p(f[i]=a=a*i%m,m-2);
	for(i=n/2;i<n;i++)a=(a-f[i]*f[i-1]%m*v[2*i-n]%m+m)%m;
	printf("%ld",a);
} ./Main.c:1:44: warning: data definition has no type or storage class
 long m=1e9+7,f[1<<20]={1},v[1<<20]={1},a=1;i;
                                            ^
./Main.c:1:44: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n){
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d",&n);i++<n;)v[i]=p(f[i]=a=a*i%m,m-2);
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%ld",a);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a decla...