n,i,d=-1,m,a[1<<17];
main(){
	scanf("%d",&n);
	for(;~scanf("%d",a+i);i++)m<a[i]&&(m=a[i]);
	for(i=0;i<n;i++)m-a[i]&&abs(m-2*a[i])<abs(m-2*d)&&(d=a[i]);
	printf("%d %d",m,d);
} ./Main.c:1:1: warning: data definition has no type or storage class
 n,i,d=-1,m,a[1<<17];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 n,i,d=-1,m,a[1<<17];
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 n,i,d=-1,m,a[1<<17];
     ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 n,i,d=-1,m,a[1<<17];
          ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 n,i,d=-1,m,a[1<<17];
            ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d",&n);
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a ...