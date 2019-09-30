n,a,b;long h[1<<17];
f(long t)
{
	long c=0,i=0;
	for(;i<n;i++)c+=h[i]>b*t?ceil((h[i]-b*t)*1./(a-b)):0;
	return c>t;
}
main()
{
	int i=0,s=0,l=1e9,m;
	for(scanf("%d%d%d",&n,&a,&b);~scanf("%d",h+i++););
	for(i=0;i++<99;)f(m=(s+l)/2)?s=m:(l=m);
	printf("%d",l+f(l));
} ./Main.c:1:1: warning: data definition has no type or storage class
 n,a,b;long h[1<<17];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 n,a,b;long h[1<<17];
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 n,a,b;long h[1<<17];
     ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(long t)
 ^
./Main.c: In function ‘f’:
./Main.c:5:27: warning: implicit declaration of function ‘ceil’ [-Wimplicit-function-declaration]
  for(;i<n;i++)c+=h[i]>b*t?ceil((h[i]-b*t)*1./(a-b)):0;
                           ^
./Main.c:5:27: warning: incompatible implicit declaration of built-in function ‘ceil’
./Main.c:5:27: note: include ‘<math.h>’ or provide a declaration of ‘ceil’
./Main.c: At top level:
./Main.c:8:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:11:6: warning: ...