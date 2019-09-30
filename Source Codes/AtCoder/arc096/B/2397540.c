#define max(a,b)a=a<b?b:a
int n;
long c,x[1<<17],v[1<<17];
main()
{
	scanf("%d%ld",&n,&c);
	long ans=0,L=0,R=0,Rmax=0;
	for(int i=0;i<n;i++)
	{
		scanf("%ld%d",x+i,v+i);
		L+=v[i];
	}
	ans=L-x[n-1];
	for(int i=n;i--;)
	{
		L-=v[i];
		R+=v[i];
		max(Rmax,R-(c-x[i]));
		max(ans,L-(i?x[i-1]*2:0)+Rmax);
	}
	long Lmax=0;
	for(int i=0;i<n;i++)
	{
		L+=v[i];
		R-=v[i];
		max(Lmax,L-x[i]);
		max(ans,R-(i!=n-1?(c-x[i+1])*2:0)+Lmax);
	}
	printf("%ld",ans);
} ./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%ld",&n,&c);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:10:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long int *’ [-Wformat=]
   scanf("%ld%d",x+i,v+i);
         ^
./Main.c:29:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%ld",ans);
  ^
./Main.c:29:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:29:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’