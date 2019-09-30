f(int*a,int*b){return*a-*b;}
a[1000];n,s,i;
main(){
	for(scanf("%d",&n);~scanf("%d",a+i++););
	qsort(a,n,4,f);
	for(i=0;i<n;i++)s=a[i]*a[i]-s;
	printf("%.9f",s*3.14159261145141919810931893);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(int*a,int*b){return*a-*b;}
 ^
./Main.c:2:1: warning: data definition has no type or storage class
 a[1000];n,s,i;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:2:9: warning: data definition has no type or storage class
 a[1000];n,s,i;
         ^
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:2:11: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 a[1000];n,s,i;
           ^
./Main.c:2:13: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 a[1000];n,s,i;
             ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d",&n);~scanf("%d",a+i++););
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in ...